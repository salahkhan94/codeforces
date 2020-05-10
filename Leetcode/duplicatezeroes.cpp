#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(arr.empty()) return;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                arr.insert(arr.begin()+i+1, 0);
                arr.erase(arr.end()-1);
            }
        }
    }
};