#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(heights.empty()) return 0;
        vector<int> sortedarr(heights);
        std::sort(sortedarr.begin(), sortedarr.end());
        int ctr=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sortedarr[i])
            ctr++;
        }        
        return ctr;
    }
};



//number of swaps 
/*
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int mini=heights[0],itr=0,ctr=0;
        if(heights.empty()) return 0;
        for(int i=0;i<heights.size();i++){
            mini = heights[i];
            for(int j=i+1;j<heights.size();j++){
                if(heights[j]<mini) {
                    mini = heights[j];
                    itr = j;
                }
            }
            if(heights[i]>mini){
                std::swap(heights[i],heights[itr]);
                ctr++;
            }
        }
        return ctr;
    }
};*/