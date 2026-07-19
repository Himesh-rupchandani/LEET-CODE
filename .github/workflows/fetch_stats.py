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
      totalActiveDays
      submissionCalendar
    }
  }
}
"""


def calculate_max_streak(calendar_raw):
    calendar = json.loads(calendar_raw or "{}")

    active_dates = sorted(
        datetime.fromtimestamp(int(timestamp), tz=timezone.utc).date()
        for timestamp, count in calendar.items()
        if int(count) > 0
    )

    if not active_dates:
        return 0

    current_streak = 1
    max_streak = 1

    for previous_day, current_day in zip(active_dates, active_dates[1:]):
        if (current_day - previous_day).days == 1:
            current_streak += 1
            max_streak = max(max_streak, current_streak)
        else:
            current_streak = 1

    return max_streak


def main():
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

    if user is None:
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
        "streak": calculate_max_streak(
            calendar.get("submissionCalendar", "{}")
        )
    }

    Path("assets").mkdir(exist_ok=True)

    Path("assets/leetcode-stats.json").write_text(
        json.dumps(stats, indent=2),
        encoding="utf-8"
    )

    print("LeetCode stats updated successfully.")
    print(stats)


if __name__ == "__main__":
    main()
