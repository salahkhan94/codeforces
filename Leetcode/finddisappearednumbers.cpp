#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return nums;
        vector<int> arr;
        bitset<100000> k;
        for(int i=0;i<nums.size();i++) k[nums[i]]=1;
        for(int i=1;i<nums.size()+1;i++){
            if(!(k[i])) arr.push_back(i);
        }
        return arr;
    }
};