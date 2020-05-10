#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(arr.empty()) return false;
        sort(arr.begin(),arr.end());
        for(auto i= arr.begin();i<arr.end();i++){
            if(binary_search(i+1, arr.end(),(*i)*2)) return true;
        }
        return false;    
    }
    
};