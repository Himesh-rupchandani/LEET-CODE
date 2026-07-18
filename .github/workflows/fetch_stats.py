import requests
import json
import os

USERNAME = "Himesh-rupchandani"
URL = "https://leetcode.com/graphql"

QUERY = """
query getUserProfile($username: String!) {
  matchedUser(username: $username) {
    profile { ranking }
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
        total_solved = easy_solved = medium_solved = hard_solved = 0
        for item in submissions:
            if item["difficulty"] == "All": total_solved = item["count"]
            elif item["difficulty"] == "Easy": easy_solved = item["count"]
            elif item["difficulty"] == "Medium": medium_solved = item["count"]
            elif item["difficulty"] == "Hard": hard_solved = item["count"]

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

        # Save to same folder as this script (.github/workflows/)
        script_dir = os.path.dirname(os.path.abspath(__file__))
        json_path = "leetcode-stats.json" 
        
        with open(json_path, "w") as f:
            json.dump(stats, f, indent=2)

        print("✅ SUCCESS!")
        print(f"Rank: {ranking}")
        print(f"Solved: {total_solved} (E:{easy_solved} M:{medium_solved} H:{hard_solved})")
        print(f"Streak: {streak} | Active Days: {active_days}")

    except Exception as e:
        print(f"❌ ERROR: {e}")

if __name__ == "__main__":
    fetch_stats()
