import json
from datetime import datetime, timezone
from pathlib import Path

import requests


USERNAME = "Himesh-rupchandani"
LEETCODE_URL = "https://leetcode.com/graphql"


QUERY = """
query getUserProfile($username: String!) {
  matchedUser(username: $username) {
    profile {
      ranking
    }

    submitStats {
      acSubmissionNum {
        difficulty
        count
      }
    }

    userCalendar {
      streak
      totalActiveDays
      submissionCalendar
    }
  }
}
"""


def calculate_max_streak(calendar_raw):
    """
    Calculate the all-time longest active-day streak
    from LeetCode's submission calendar.
    """

    calendar = json.loads(calendar_raw or "{}")

    active_dates = sorted(
        datetime.fromtimestamp(int(timestamp), tz=timezone.utc).date()
        for timestamp, count in calendar.items()
        if int(count) > 0
    )

    if not active_dates:
        return 0

    best_streak = 1
    current_streak = 1

    for previous_day, current_day in zip(active_dates, active_dates[1:]):
        if (current_day - previous_day).days == 1:
            current_streak += 1
            best_streak = max(best_streak, current_streak)
        else:
            current_streak = 1

    return best_streak


def create_dashboard_svg(stats):
    """
    Creates assets/leetcode-dashboard.svg directly.
    No JSON file is required.
    """

    def number(key):
        return f"{stats.get(key, 0):,}"

    svg = f"""<svg xmlns="http://www.w3.org/2000/svg" width="900" height="300" viewBox="0 0 900 300" role="img">
  <defs>
    <linearGradient id="orange" x1="0" x2="1">
      <stop stop-color="#ff7a18"/>
      <stop offset=".5" stop-color="#ffb000"/>
      <stop offset="1" stop-color="#ff7a18"/>
    </linearGradient>

    <linearGradient id="chartFill" x1="0" x2="1">
      <stop stop-color="#ff7a18" stop-opacity=".28"/>
      <stop offset="1" stop-color="#ffb000" stop-opacity=".03"/>
    </linearGradient>
  </defs>

  <rect width="900" height="300" rx="20" fill="#0d1117"/>
  <rect x="1" y="1" width="898" height="298" rx="19" fill="none" stroke="#30363d"/>

  <text x="34" y="45"
        font-family="Arial, sans-serif"
        font-size="23"
        font-weight="700"
        fill="#f0f6fc">
    LEETCODE / CONSISTENCY DASHBOARD
  </text>

  <text x="34" y="67"
        font-family="Arial, sans-serif"
        font-size="13"
        fill="#8b949e">
    Himesh Rupchandani · C++ problem-solving journey
  </text>

  <path d="M28 80H872" stroke="#30363d"/>
  <path d="M28 80H330" stroke="url(#orange)" stroke-width="2"/>

  <text x="35" y="122"
        font-family="Arial, sans-serif"
        font-size="14"
        fill="#8b949e">
    PROBLEMS SOLVED
  </text>

  <text x="35" y="169"
        font-family="Arial, sans-serif"
        font-size="45"
        font-weight="700"
        fill="#f0f6fc">
    {number("total_solved")}
  </text>

  <text x="35" y="196"
        font-family="Arial, sans-serif"
        font-size="13"
        fill="#ffb000">
    EASY {number("easy_solved")} · MEDIUM {number("medium_solved")} · HARD {number("hard_solved")}
  </text>

  <text x="35" y="244"
        font-family="Arial, sans-serif"
        font-size="13"
        fill="#8b949e">
    GLOBAL RANK #{number("ranking")}
  </text>

  <path d="M322 105V250" stroke="#30363d"/>

  <text x="365" y="122"
        font-family="Arial, sans-serif"
        font-size="14"
        fill="#8b949e">
    TOTAL ACTIVE DAYS
  </text>

  <text x="365" y="190"
        font-family="Arial, sans-serif"
        font-size="60"
        font-weight="700"
        fill="#ffb000">
    {number("active_days")}
  </text>

  <text x="365" y="218"
        font-family="Arial, sans-serif"
        font-size="14"
        fill="#c9d1d9">
    days of showing up
  </text>

  <path d="M590 105V250" stroke="#30363d"/>

  <text x="635" y="122"
        font-family="Arial, sans-serif"
        font-size="14"
        fill="#8b949e">
    MAX STREAK
  </text>

  <text x="635" y="190"
        font-family="Arial, sans-serif"
        font-size="60"
        font-weight="700"
        fill="#ffb000">
    {number("max_streak")}
  </text>

  <text x="635" y="218"
        font-family="Arial, sans-serif"
        font-size="14"
        fill="#c9d1d9">
    consecutive active days
  </text>

  <path d="M365 251 C425 230 458 274 515 242 S620 270 690 237 S785 260 860 225"
        fill="none"
        stroke="url(#orange)"
        stroke-width="3"/>

  <path d="M365 251 C425 230 458 274 515 242 S620 270 690 237 S785 260 860 225
           L860 275 L365 275Z"
        fill="url(#chartFill)"/>
</svg>
"""

    Path("assets").mkdir(exist_ok=True)

    Path("assets/leetcode-dashboard.svg").write_text(
        svg,
        encoding="utf-8"
    )


def fetch_and_create_dashboard():
    response = requests.post(
        LEETCODE_URL,
        json={
            "query": QUERY,
            "variables": {
                "username": USERNAME
            }
        },
        headers={
            "Content-Type": "application/json",
            "User-Agent": "Mozilla/5.0"
        },
        timeout=20
    )

    response.raise_for_status()

    user = response.json()["data"]["matchedUser"]

    if not user:
        raise RuntimeError("LeetCode username was not found.")

    solved_data = {
        item["difficulty"]: item["count"]
        for item in user["submitStats"]["acSubmissionNum"]
    }

    calendar = user["userCalendar"] or {}

    stats = {
        "ranking": user["profile"]["ranking"],
        "total_solved": solved_data.get("All", 0),
        "easy_solved": solved_data.get("Easy", 0),
        "medium_solved": solved_data.get("Medium", 0),
        "hard_solved": solved_data.get("Hard", 0),
        "active_days": calendar.get("totalActiveDays", 0),
        "max_streak": calculate_max_streak(
            calendar.get("submissionCalendar", "{}")
        )
    }

    create_dashboard_svg(stats)

    print("LeetCode dashboard updated successfully.")
    print(stats)


if __name__ == "__main__":
    fetch_and_create_dashboard()
