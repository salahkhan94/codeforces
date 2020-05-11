#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        
        int max_ones = 0;
        int count = 0;
        
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        for (auto i : nums)
        {
           (i) ? ++count : (count = 0);
            max_ones = max(max_ones, count);
        }
        
        return max_ones;
    }
};