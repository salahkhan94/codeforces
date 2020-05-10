#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return;
        unsigned int ctr = 0,k=0,val=0;
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
            if(k) ctr++;
        }
        for(int i = nums.size()-ctr; i<nums.size();i++) 
            nums[i] = 0;
    }
};