#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*template<typename T>
std::vector<T> split(const std::string& line) {
    std::istringstream is(line);
    return std::vector<T>(std::istream_iterator<T>(is), std::istream_iterator<T>());
}

template <typename T>
T * spitarr(string s, int size){
    T* arr = new T[size];
    istringstream ss(s);

    while(ss >> buf){
        n[q] = stoi(buf);
        q++;
    }
}*/
    // getline(cin, rawInput);
    // istringstream ss1(rawInput);
    // while(ss1 >> buf){
    //     s[q] = buf.c_str();
    //     q++;
    // }
    // cout<<"The value q is: "<<q<<endl;

int main(){

    int n[2],q=0,k;
    string rawInput;
    string buf;
    while(getline(cin, rawInput,' ') ){
        n[q] = stoi(rawInput.c_str());
        q++;
        if(q==1){
            getline(cin, rawInput);
            n[q] = stoi(rawInput.c_str());
            break;
        }
        
    }
  
    string *s,*t;
    s = new string [n[0]];
    t = new string [n[1]];
    q=0;
    while(1){
        if(q==n[0]-1){
            getline(cin, rawInput);
            s[q] = rawInput.c_str();
            break;
        }
        else{
            getline(cin, rawInput,' ');
            s[q] = rawInput.c_str();
            q++;
        }
    }
    
    q=0;
    while(1){
        if(q==n[1]-1){
            getline(cin, rawInput);
            t[q] = rawInput.c_str();
            break;
        }
        else{
            getline(cin, rawInput,' ');
            t[q] = rawInput.c_str();
            q++;
        }
    }

    cin>>q;
    for(int i=0; i<q; i++){
        cin>>k;
        cout<<(s[(k-1)%n[0]]+t[((k-1)%n[1])])<<endl;
    }

    delete [] s;
    delete [] t;
    return 0;

}