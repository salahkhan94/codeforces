#include <bits/stdc++.h>
using namespace std;
bitset <100000> Muk, Sum;
unsigned int a[100000], b[100000], l1, l2, r1, r2;

int main(){
    cin.sync_with_stdio(false); 
    unsigned  int N, M, Q;
    cin >> N >> M >> Q;

    for(unsigned int i=1;i<=N;i++)
    {
        cin>>a[i];
    }

    for(unsigned int i=1;i<=M;i++)
    {
        cin>>b[i];
    }

    for(unsigned int j=1;j<=Q; j++){

        cin >> l1 >> r1 >>  l2 >> r2;

        for(unsigned int i=l1;i<=r1;i++)
        {
            Muk[a[i]] = !Muk[a[i]];
        }
        for(unsigned int i=l2;i<=r2;i++)
        {
            Sum[b[i]] = !Sum[b[i]];
        }
        Muk ^= Sum;
        cout<<Muk.count()<<endl;
        Muk.reset();
        Sum.reset();
    }

}