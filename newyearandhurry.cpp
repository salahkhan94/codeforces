//link to the problem statement https://codeforces.com/problemset/problem/750/A
#include<iostream>
#include<cmath>
#include <algorithm>

using namespace std;
int main(){
    unsigned int n,k,p;
    string rawInput;
    getline(cin, rawInput,' ');
    n = stoi(rawInput.c_str());
    getline(cin, rawInput);
    k = stoi(rawInput.c_str());
    p = floor(min((double)n, ((sqrt(1+(1.6*(240-k)))-1)/2)));
    cout<<p;
}