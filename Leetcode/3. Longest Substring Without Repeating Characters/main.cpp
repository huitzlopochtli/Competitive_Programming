#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		int leftPointer = 0;
		int rightPointer = 0;
		int result = 0;

		unordered_set<int> hash_set;

		while (rightPointer < s.size())
		{
			if (hash_set.find(s[rightPointer]) == hash_set.end())
			{
				hash_set.insert(s[rightPointer]);
				result = max(result, rightPointer - leftPointer + 1);
				rightPointer++;
			}
			else
			{
				hash_set.erase(s[leftPointer]);
				leftPointer++;
			}
		}

		return result;
	}

	int lengthOfLongestSubstringArray(string s)
	{
		int leftPointer = 0, rightPointer = 0, result = 0;
		int map[256] = {0};

		while (rightPointer < s.size())
		{
			int r = s[rightPointer], l = s[leftPointer];
			if (map[r] == 0)
			{
				map[r] = 1;
				result = max(result, rightPointer - leftPointer + 1);
				rightPointer++;
			}
			else
			{
				map[l] = 0;
				leftPointer++;
			}
		}

		return result;
	}
};

int main()
{
	auto solution = new Solution();
	cout << solution->lengthOfLongestSubstringArray("abcabcbbccdd");
	return 0;
}