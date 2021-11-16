// C++ program to merge two sorted arrays
//using maps
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	// Function to merge arrays
	vector<int> mergeArrays(vector<int> a, vector<int> b)
	{
		// Declaring a map.
		// using map as a inbuilt tool
		// to store elements in sorted order.
		map<int, int> mp;
		int n = a.size(), m = b.size();

		// Inserting values to a map.
		for (int i = 0; i < n; i++)
			mp[a[i]]++;

		for (int i = 0; i < m; i++)
			mp[b[i]]++;

		// Printing keys of the map.
		vector<int> ret;
		int i = 0;
		for (auto i : mp)
		{
			while (i.second > 0)
			{
				ret.insert(ret.end(), i.first);
				i.second--;
			}
		}

		return ret;
	}

	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		auto arr = mergeArrays(nums1, nums2);

		if (arr.size() % 2 == 0)
		{
			int left = arr[arr.size() / 2];
			int right = arr[arr.size() / 2 - 1];
			double ret = double(left + right) / 2;

			return ret;
		}
		else
		{
			return arr[arr.size() / 2];
		}
	}
};

// Driver Code
int main()
{
	vector<int> a = {1, 1}, b = {1, 2};

	int n = a.size();
	int m = b.size();

	auto solution = new Solution();
	cout << solution->findMedianSortedArrays(a, b);

	return 0;
}