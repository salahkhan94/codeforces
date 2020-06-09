#include <bits/stdc++.h>

using namespace std;
string mult10(string s, int l){
    for(int i=0;i<l;i++){
        s+='0';
    }
    return s;
}
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n1 - n2; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n2-1; i>=0; i--) 
    { 
        // Do school mathematics, compute difference of 
        // current digits and carry 
        int sub = ((str1[i+diff]-'0') - 
                   (str2[i]-'0') - 
                   carry); 
        if (sub < 0) 
        { 
            sub = sub+10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of str1[] 
    for (int i=n1-n2-1; i>=0; i--) 
    { 
        if (str1[i]=='0' && carry) 
        { 
            str.push_back('9'); 
            continue; 
        } 
        int sub = ((str1[i]-'0') - carry); 
        if (i>0 || sub>0) // remove preceding 0's 
            str.push_back(sub+'0'); 
        carry = 0; 
  
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
    int diff = n2 - n1; 
  
    // Initially take carry zero 
    int carry = 0; 
  
    // Traverse from end of both strings 
    for (int i=n1-1; i>=0; i--) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0') + 
                   (str2[i+diff]-'0') + 
                   carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining digits of str2[] 
    for (int i=n2-n1-1; i>=0; i--) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string karatsubamult(string x, string y){

    string s={'0'};
    while (x.size()>y.size() || y.size()<2 || y.size()%2)
    {
        y.insert(0, s);
    }
    while (x.size()<y.size() || x.size()<2 || x.size()%2)
    {
        x.insert(0, s);
    }
    cout<<"x is : "<< x<< endl;
    cout<<"y is : "<< y<< endl;

    string ans;
    if(x.size()>2){
        string ac, bd, adplusbc, temp;
        ac = karatsubamult(x.substr(0, x.size()/2), y.substr(0, y.size()/2));
        bd = karatsubamult(x.substr((x.size()/2),ceil((float)x.size()/2)),y.substr((y.size()/2),ceil((float)y.size()/2)) );
        temp = karatsubamult(findSum(x.substr(0, x.size()/2), x.substr((x.size()/2),ceil((float)x.size()/2))), findSum(y.substr(0, y.size()/2), y.substr((y.size()/2),ceil((float)y.size()/2))));
        temp = findDiff(temp, ac);
        adplusbc = findDiff(temp, bd);
        ac = mult10(ac, x.size());
        adplusbc = mult10(adplusbc, ceil((float)x.size()/2));
        ans = findSum(ac, adplusbc);
        ans = findSum(ans, bd);
    }
    else{
        int ac, bd, adplusbc, temp, a,b,c,d;

        a = (int)x[0] - '0';
        b = (int)x[1] - '0';
        c = (int)y[0] - '0';
        d = (int)y[1] - '0';
        ac = a*c;
        bd = b*d;
        temp = (a + b) * (c + d);
        adplusbc = temp-ac-bd;
        ac*=pow(10,x.size());
        adplusbc*=pow(10, x.size()/2);
        ans = to_string( ac + adplusbc + bd);
    }
    return ans;
}

  
int main(){
    string m1, m2;
    cin>> m1 >> m2;
    string m = karatsubamult(m1, m2);
    cout << m;
}