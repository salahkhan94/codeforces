//Problem statement can be found here  https://codeforces.com/problemset/problem/99/A

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    string rawInput, i,f;
    getline(cin, rawInput,'.');
    i = rawInput.c_str();
    getline(cin, rawInput);
    f = rawInput.c_str();
    if(i[i.length()-1]<'9' && f[0] < '5'){
        cout<<i<<endl;
    }
    else if(i[i.length()-1]<'9'){
        i[i.length()-1]++;
        cout<<i<<endl;
    }
    else cout<<"GOTO Vasilisa."<<endl;
}