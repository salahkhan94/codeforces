#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return 0;
        unsigned int ctr = 0,k=0,val=nums[0];
        for(int i=1; i<nums.size()-ctr; i++){
            if(nums[i]==val || ctr!=0){
                while(nums[i+ctr]==val) 
                {
                    if(i+ctr+1 <nums.size()) ctr++;
                    else{
                         k=1;
                         break;
                    }
                }
                nums[i] = nums[i+ctr];
            }
            val = nums[i];
            if(k) ctr++;
        }
        nums.resize(nums.size()-ctr);
        return (nums.size());
    }
    
};