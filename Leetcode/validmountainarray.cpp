#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(arr.empty()) return arr;
        auto max = max_element(arr.begin()+1,arr.end());
        for(auto i=arr.begin();i<arr.end()-1;i++){
            if(i<max) *i = *max;
            else {
                max = max_element(i+1,arr.end());
                *i=*max;
            }
        }
        arr[arr.size()-1] = -1;
        return arr;
        
    }
};