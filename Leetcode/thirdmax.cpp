#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return 0;
        else if(nums.size()<3) return (nums[0]>nums[1]?nums[0]:nums[1]);
        
        set<int> s(nums.begin(),nums.end());
        auto itr= s.begin();
        if(s.size()<3) {
            std::advance(itr,s.size()-1);
            return *(itr);            
        }
        std::advance(itr,s.size()-3);
        return *(itr);
    }
};

