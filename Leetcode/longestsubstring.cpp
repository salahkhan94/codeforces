#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(s.empty()) return 0;
        set<char> sp;
        int count =0,l=0,j=0;
        for(auto c:s){
            auto itr = sp.insert(c);
            if(itr.second) count++;
            else{
                while(!itr.second){
                    l = std::max(count,l);
                    sp.erase(s[j]);
                    j++;
                    itr = sp.insert(c);
                    count--;
                }
                count++;
            }


        }
        l = std::max(count,l);
        return l;
    }
};