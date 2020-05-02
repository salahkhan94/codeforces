#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n=0;
    string poly;
    getline(cin, poly);
    for (auto it=poly.begin(); it!=poly.end(); it++){
        if(*it=='a') n++;
    }
    cout<< std::min((2*n-1), (int)poly.length());
}