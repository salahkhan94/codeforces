#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(s.empty()) return s;
        int l=1;
        string pal="";
        for(int k=0; k<s.length();k++){
            string temp = checkpalindrome(k,k+1,s);
            pal = temp.length()>pal.length()?temp:pal;
            temp = checkpalindrome(k,k,s);
            pal = temp.length()>pal.length()?temp:pal;
            if(pal.length()==s.length()) return pal;
        }
        return pal;
    }
    string checkpalindrome(int i, int j, string s){
        string pal(1,s[0]);
        int r=i, t=j;
        while(r>-1 && t<s.length() && s[r]==s[t]){
            r--;
            t++;
        }
        if(r!=i) return s.substr(r+1,t-r-1);
        else return pal;
    }
};

/*
class Solution {
public:
    string longestPalindrome(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(s.empty()) return s;
        int l=1;
        string pal="";
        for(int i=0; i<s.length();i++){
            for(int j=s.length()-1; j>=i;j--){
                if(s[i]==s[j]){
                    string temp = checkpalindrome(s.substr(i,j-i+1));
                    pal = temp.length()>pal.length()?temp:pal;
                    //cout<<pal.length()<<endl;
                    if(pal.length()==s.length()) return pal;
                    if(pal == s.substr(i,j-i+1)) break;
                }
                
            }
        }
        return pal;
    }
    string checkpalindrome(string s){
        int left=0, right=s.length()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
                //cout<<s.substr(left,right-left+1)<<endl;
            }
            else break;
        }
        string t(1,s[0]);
        if(left<right) return t;
        else return s; 
    }
};
};*/