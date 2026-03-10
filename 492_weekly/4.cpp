#include<bits/stdc++.h>
using namespace std;

//prefix sum trick to obtain no. of 1's in O(1)
class Solution {
private:
    vector<int> pref;

    long long recursion(int l, int r, int encCost, int flatCost) {
        int L = r - l + 1;

        int X = pref[r+1] - pref[l];

        long long cost;
        if (X > 0) {
            cost = 1LL * L * X * encCost;
        } else {
            cost = flatCost;
        }

        if (L % 2 != 0) {
            return cost;
        }

        int mid = (l + r) / 2;

        long long leftCost = recursion(l, mid, encCost, flatCost);
        long long rightCost = recursion(mid+1, r, encCost, flatCost);

        return min(cost, leftCost + rightCost);
    }

public:
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();

        pref.resize(n+1,0);

        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + (s[i]=='1');
        }

        return recursion(0, n-1, encCost, flatCost);
    }
};

int main() {

    return 0;
}