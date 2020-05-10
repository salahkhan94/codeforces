#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums.empty()) return 0;
        unsigned int ctr = 0,k=0;
        for(int i=0; i<nums.size()-ctr; i++){
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
        nums.resize(nums.size()-ctr);
        return (nums.size());
    }
};

int main(){
    Solution sol;
    vector<int> v1;
    v1.push_back(0); 
    v1.push_back(1); 
    v1.push_back(2);
    v1.push_back(2); 
    v1.push_back(3); 
    v1.push_back(0);  
    v1.push_back(4);
    v1.push_back(2);
    v1.push_back(2); 
    int l = sol.removeElement(v1,2);
    for(auto i: v1){
        cout<<i;
    }
    cout<< "length : " <<l<<endl;

}