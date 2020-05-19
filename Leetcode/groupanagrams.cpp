#include <bits/stdc++.h>
using namespace  std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<string>> anag;
        if(strs.size()<2) {
            anag.push_back(strs);
            return anag;
        }
        vector<string> sorted;
        for(int i=0;i< strs.size();i++){
            sorted.push_back(sortstring(strs[i]));
        }
        set<string> un;
        vector<string> an;
        for(int i=0; i<strs.size(); i++){
            if(un.find(sorted[i])==un.end()){
                an.push_back(strs[i]);    
                for(int j=1+i; j< strs.size();j++){
                    if(sorted[i]==sorted[j]){
                        an.push_back(strs[j]);
                    }
                }
                un.insert(sorted[i]);
            }
            if(!an.empty())
            anag.push_back(an);
            an.clear();
        }
        return anag;
    }
    string sortstring(string str){
        sort(str.begin(), str.end());
        return str;
    }
};