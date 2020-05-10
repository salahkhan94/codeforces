#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(A.empty()) return A;
        vector<int> squarearr(A.size()),pos,neg;
        
        for(auto i: A){
            if(i>-1)
            pos.push_back(i*i);
            else neg.push_back(i*i);
        }
        reverse(neg.begin(),neg.end());
        merge(pos.begin(),pos.end(),neg.begin(),neg.end(),squarearr.begin());
        return squarearr;
    }
};