#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(A.empty()) return A;
        int j=0;
        for(int i=0;i<A.size();i++){
            if(A[i]&1){
                j=i+1;
                while((A[j]&1) && j<A.size()) j++;
                    if(j==A.size())
                        return A;
                    else 
                        std::swap(A[i],A[j]);                
            }
        }
        return A;
    }
};