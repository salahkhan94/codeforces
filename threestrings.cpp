/* Problem statement can be found here : https://codeforces.com/problemset/problem/1301/A */

#include <iostream>
#include <string>

using namespace std;

void testcase(){
    string a,b,c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    for(int i=0;i<a.length();i++){
        if((a[i]==c[i]) || (b[i]==c[i]))
            continue;
        else{
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main(){
    int t;
    string s;
    getline(cin,s);
    t = stoi(s);
    for(int i=0; i<t; i++){
        testcase();
    }
}