#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result;
        int size = nums.size();
        
        for(int i=0; i<size; i++)
        {
            // Find the difference
            int diff = target - nums[i];
            
            // if diff is in map
            if(m.find(diff) != m.end())
            {
                // get the map pair <value, index>
                auto p = m.find(diff);        
                // push the index from the map pair
                result.push_back(p->second);
                // push the current index to the result vector
                result.push_back(i);
            }
            // if diff not in map
            // insert <value, index> to map
            m.insert(make_pair(nums[i], i));
        }
          
        return result;
    }
};