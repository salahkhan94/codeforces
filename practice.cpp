#include <bits/stdc++.h> 
using namespace std;

//__builtin_popcount(x); prints number of 1s in the binary representation of x

const int MAX_D=10,MAX_N=10; //Max_D: Total number of days MAX_N : N workers
const int K = MAX_D/64 +1; //divide total number of days into segments of 64 as max size of ll is 64 bits
unsigned long long x[MAX_N][K];
int intersection(int i, int j){
    int total = 0;
    for(int z=0;z<K;z++){
        total +=__builtin_popcountll(x[i][z] & x[j][z]);
    }
    return total;
}

bitset<MAX_D> X[MAX_N];
int intersections(int i, int j){
    return (X[i] & X[j]).count();
}
/*
std::set<int> set{ 1, 2, 3 };
auto result = set.insert(1);
if (!result.second)
    std::cout << "Failed to insert element!" << std::endl;*/
//if(my_set.insert("value").second == false) { do_something_for_duplicate(); }
bitset<365> a;

/*bool can[MAX_N];
int knapsack(){
    int n, W;
    cin >> n >> W;
    can[0] = true;
    for(int id=0;id<n;id++){
        int x;
        cin>>x;
        for(int i=W;i>=x;i--){
            if(can[i-x]) can[i] = true;
        }
    }
    puts(can[W] ? "YES" : "NO");
}*/

//check if sum of a subset equals W
bitset<MAX_N> can;
int knapsack2(){
    int n, W;
    cin >> n >> W;
    can[0] = true;
    for(int id=0;id<n;id++){
        int x;
        cin>>x;
        can |= (can<<x);
    }
    puts(can[W] ? "YES" : "NO");
}

int main(){
    // int x;
    // cin >> x;
    // for(int i=2;i>-1;i--){
    //     if((x & (1<<i))!=0) cout<<"1";    //(x>>i) &1
    //     else cout<<"0";
    // }
    string s;   //iterate over all the subsets
    getline(cin,s);
    int n = s.length();
    for(int mask=0; mask<(1<<n); mask++){
        string temp = "";
        for(int i=0; i<n; i++){
            if(mask & (1 <<i)) {
                temp += s[i];
            }
        }
        cout<<temp<<endl;
    }
    
}

