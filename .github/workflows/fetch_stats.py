import requests
import json
import os
import re

USERNAME = "Himesh-rupchandani"
URL = "https://leetcode.com/graphql"

STATS_QUERY = """
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
    }
  }
}
"""

RECENT_QUERY = """
query recentAcSubmissions($username: String!, $limit: Int!) {
  recentAcSubmissionList(username: $username, limit: $limit) {
    title
    titleSlug
    timestamp
  }
}
"""

def fetch_stats():
    response = requests.post(
        URL,
        json={"query": STATS_QUERY, "variables": {"username": USERNAME}},
        headers={"Content-Type": "application/json", "User-Agent": "Mozilla/5.0"},
        timeout=10
    )
    data = response.json()
    user = data["data"]["matchedUser"]

    ranking = user["profile"]["ranking"]
    submissions = user["submitStats"]["acSubmissionNum"]

    total_solved = easy_solved = medium_solved = hard_solved = 0
    for item in submissions:
        if item["difficulty"] == "All":
            total_solved = item["count"]
        elif item["difficulty"] == "Easy":
            easy_solved = item["count"]
        elif item["difficulty"] == "Medium":
            medium_solved = item["count"]
        elif item["difficulty"] == "Hard":
            hard_solved = item["count"]

    streak = user["userCalendar"]["streak"]
    active_days = user["userCalendar"]["totalActiveDays"]

    return {
        "ranking": ranking,
        "total_solved": total_solved,
        "easy_solved": easy_solved,
        "medium_solved": medium_solved,
        "hard_solved": hard_solved,
        "streak": streak,
        "active_days": active_days
    }


def fetch_recent_submissions(limit=11):
    response = requests.post(
        URL,
        json={"query": RECENT_QUERY, "variables": {"username": USERNAME, "limit": limit}},
        headers={"Content-Type": "application/json", "User-Agent": "Mozilla/5.0"},
        timeout=10
    )
    data = response.json()
    submissions = data["data"]["recentAcSubmissionList"]
    return submissions


def build_markdown_table(submissions):
    header = "| # | Problem | Link |\n|:-:|:--------|:----:|\n"
    rows = ""
    for i, sub in enumerate(submissions, start=1):
        title = sub["title"]
        slug = sub["titleSlug"]
        link = f"https://leetcode.com/problems/{slug}/"
        rows += f"| {i} | {title} | [Solve →]({link}) |\n"
    return header + rows


def update_readme(table_markdown):
    # README is in repo root, script is in .github/workflows/
    script_dir = os.path.dirname(os.path.abspath(__file__))
    readme_path = os.path.join(script_dir, "..", "..", "README.md")
    readme_path = os.path.normpath(readme_path)

    with open(readme_path, "r", encoding="utf-8") as f:
        content = f.read()

    new_section = f"<!--START_SECTION:recent-solutions-->\n{table_markdown}\n<!--END_SECTION:recent-solutions-->"

    updated_content = re.sub(
        r"<!--START_SECTION:recent-solutions-->.*?<!--END_SECTION:recent-solutions-->",
        new_section,
        content,
        flags=re.DOTALL
    )

    with open(readme_path, "w", encoding="utf-8") as f:
        f.write(updated_content)


def save_stats_json(stats):
    script_dir = os.path.dirname(os.path.abspath(__file__))
    json_path = os.path.join(script_dir, "leetcode-stats.json")
    with open(json_path, "w") as f:
        json.dump(stats, f, indent=2)


def main():
    try:
        stats = fetch_stats()
        save_stats_json(stats)
        print("✅ Stats JSON updated:", stats)

        recent = fetch_recent_submissions(limit=11)
        table = build_markdown_table(recent)
        update_readme(table)
        print("✅ README Recent Solutions table updated!")

    except Exception as e:
        print(f"❌ Error: {e}")


if __name__ == "__main__":
    main()
