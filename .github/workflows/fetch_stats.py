import requests
import json
import os

# ✅ Your LeetCode username
USERNAME = "Himesh-rupchandani"

URL = "https://leetcode.com/graphql"

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
    }
  }
}
"""

def fetch_stats():
    try:
        response = requests.post(
            URL,
            json={"query": QUERY, "variables": {"username": USERNAME}},
            headers={
                "Content-Type": "application/json",
                "User-Agent": "Mozilla/5.0"
            },
            timeout=10
        )

        data = response.json()
        user = data["data"]["matchedUser"]

        ranking = user["profile"]["ranking"]

        submissions = user["submitStats"]["acSubmissionNum"]
        total_solved = 0
        easy_solved = 0
        medium_solved = 0
        hard_solved = 0

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

        stats = {
            "ranking": ranking,
            "total_solved": total_solved,
            "easy_solved": easy_solved,
            "medium_solved": medium_solved,
            "hard_solved": hard_solved,
            "streak": streak,
            "active_days": active_days
        }

        # ✅ Save JSON in the same folder as this script (.github/workflows/)
        script_dir = os.path.dirname(os.path.abspath(__file__))
        json_path = os.path.join(script_dir, "leetcode-stats.json")

        with open(json_path, "w") as f:
            json.dump(stats, f, indent=2)

        print("✅ Stats updated successfully!")
        print(f"   Rank        : {ranking}")
        print(f"   Total Solved: {total_solved}")
        print(f"   Easy        : {easy_solved}")
        print(f"   Medium      : {medium_solved}")
        print(f"   Hard        : {hard_solved}")
        print(f"   Streak      : {streak}")
        print(f"   Active Days : {active_days}")

    except Exception as e:
        print(f"❌ Error fetching stats: {e}")

if __name__ == "__main__":
    fetch_stats()
