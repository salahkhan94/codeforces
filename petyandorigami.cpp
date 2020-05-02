//Problem statement : https://codeforces.com/problemset/problem/1080/A

#include <iostream>
#include <cmath>
#include <string>

using namespace  std;
 
int main(){
    unsigned int n,k,q=0;
    string rawInput;
    getline(cin, rawInput,' ');
    n = stoi(rawInput.c_str());
    getline(cin, rawInput);
    k = stoi(rawInput.c_str());
    unsigned long int ans = ( (ceil((float)2*n/k)) + (ceil((float)5*n/k)) + (ceil((float)8*n/k)) );
    cout<< ans<<endl;

}