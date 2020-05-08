#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        unsigned int ctr=0,max=0;
        for(auto i=nums.begin(); i<nums.end();i++){
            
            if(*i == 1){
                ctr++;
                if(ctr>max) max = ctr;
            }
            else{
                
                ctr = 0;
            }
        }
        return max;
        
    }
};