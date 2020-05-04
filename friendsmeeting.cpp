//link to the problem statement https://codeforces.com/problemset/problem/931/A

#include <iostream>
using namespace std;
int main(){
    int x1,x2;
    cin>>x1;
    cin>>x2;
    if(abs(x1-x2)%2){
        int n = (abs(x1-x2)-1)/2;
        cout<<(n*(n+1)) + n+1<<endl;
    }
    else{
        int n = abs(x1-x2)/2;
        cout<<(n*(n+1))<<endl;
    }

}