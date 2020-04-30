#include<iostream>
#include<string>
#include <map>

using namespace std;

int main(){
    int i,t=0;
    string poly;
    cin>>i;
    map<string, int> polyhedrons;
    polyhedrons.insert(make_pair("Tetrahedron", 4));
    polyhedrons.insert(make_pair("Cube", 6));
    polyhedrons.insert(make_pair("Octahedron", 8));
    polyhedrons.insert(make_pair("Dodecahedron", 12));
    polyhedrons.insert(make_pair("Icosahedron", 20));
    for(;i>=0;i--){
        getline(cin, poly);
        t+=polyhedrons[poly];
    }
    cout<<t<<endl;
}