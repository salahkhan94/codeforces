#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m+n);
        std::merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),temp.begin());
    }
};