//
// Created by bhagirathi on 3/3/2018.
//
//library
#include <bits/stdc++.h>
using namespace std;

//macros
typedef unsigned int UI;
typedef unsigned long long int ULLI;
#define MAX 4294967296
#define MOD 4294967296

//members
ULLI stor[MAX / 64];

//methods

int main() {
    int q;
    ULLI s,a,b,ans=0,t;
    scanf("%d", &q);
    scanf("%lld %lld %lld", &s, &a, &b);

    while(q--){
        if(s%2){ //add operation
            ans+=s/2;
            t=s/2;
            stor[t / 64] = stor[t / 64] | (1LL << (t % 64));
        }
        else{ //erase operation
            t = s / 2;
            if(stor[t / 64] & (1LL << (t % 64))) {
                ans -= t;
                stor[t / 64] = stor[t / 64] ^ (1LL << (t % 64));
            }
        }
        s=(a*s+b)%MOD;
    }
    printf("%lld", ans);
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     int x;
//     cin>>x;
//     //x = 1<<(__builtin_ctz(x));
//     x = 1<<(32-__builtin_clz(x));
//     cout << x<<endl;
// }