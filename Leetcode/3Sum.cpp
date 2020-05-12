#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        //if(nums.empty()) return nums;
        vector<vector<int>> arr1;
        if(nums.size()<3) return arr1;
        
        sort(nums.begin(),nums.end());
        list<vector<int>> sarr;
        int val;
        for(int i = 0;i<nums.size()-2;i++){
            
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                
                if(nums[left] + nums[right] + nums[i] == 0){
                    vector<int> vect{ nums[left], nums[right], nums[i] }; 
                    sort(vect.begin(),vect.end());
                    sarr.push_back(vect);
                    right--;
                    left++;
                }
                
                else if(nums[left] + nums[right] + nums[i] > 0){
                    right--;
                }
                else{
                    left++;
                }
                // moving left pointer to right to skip duplicates
                while(left < right && nums[left] == nums[left - 1]){
                    left++;
                }
                // moving right pointer to left to skip duplicates 
                while(left < right && nums[right] == nums[right + 1]){
                    right--;
                }
                        
            }
        }
        if(!sarr.empty())
        arr1.assign(sarr.begin(),sarr.end());
        return arr1;
    }
};




/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        //if(nums.empty()) return nums;
        vector<vector<int>> arr;
        if(nums.empty()) return arr;
        sort(nums.begin(),nums.end());
        int val;
        for(auto i = nums.begin();i<nums.end();i++){
            for(auto j =i+1;j<nums.end();j++){
                val = *i + *j;
                auto k = find(j+1, nums.end(), (-1*val) );
                if(k!=nums.end()){
                    vector<int> vect{ *i, *j, *k }; 
                    if(find(arr.begin(),arr.end(), vect)==arr.end())
                    arr.push_back(vect);
                }
            }
        }
        return arr;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        //if(nums.empty()) return nums;
        //sort(nums.begin(),nums.end());
        unordered_set<vector<int>, VectorHash> sarr;
        unordered_multiset<int> s(nums.begin(),nums.end());
        int val;
        for(auto i = nums.begin();i<nums.end();i++){
            for(auto j =i+1;j<nums.end();j++){
                val = *i + *j;
                val = -1*val;
                int ctr = (val==*i);
                ctr+= (val==*j);
                if(s.count(val)>ctr){
                    vector<int> vect{ *i, *j, val }; 
                    sort(vect.begin(),vect.end());
                    sarr.insert(vect);
                }
            }
        }
        vector<vector<int>> arr(sarr.begin(),sarr.end());
        return arr;
    }
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
    };
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        //if(nums.empty()) return nums;
        vector<vector<int>> arr1;
        if(nums.size()<3) return arr1;
        sort(nums.begin(),nums.end());
        unordered_set<vector<int>, VectorHash> sarr;
        unordered_multiset<int> s(nums.begin(),nums.end());
        int val;
        for(auto i = nums.begin();i<nums.end()-2;i++){
            if(i>nums.begin() && *i==*(i-1)) continue;
            for(auto j =i+1;j<nums.end();j++){
                val = *i + *j;
                val = -1*val;
                int ctr = (val==*i);
                ctr+= (val==*j);
                if(s.count(val)>ctr){
                    vector<int> vect{ *i, *j, val }; 
                    sort(vect.begin(),vect.end());
                    sarr.insert(vect);
                }
            }
        }
        vector<vector<int>> arr(sarr.begin(),sarr.end());
        return arr;
    }
    struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
    };
};

*/

