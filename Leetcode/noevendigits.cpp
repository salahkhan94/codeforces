#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return 0;
        unsigned int t=0,d;
        for(auto i:nums){
            d =  (i < 10 ? 1 :   
            (i < 100 ? ++t :   
            (i < 1000 ? 3 :   
            (i < 10000 ? ++t :   
            (i < 100000 ? 5 :++t)))));             
        }
        return t;
    }
};