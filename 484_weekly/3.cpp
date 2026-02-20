#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string, int> mp;
        for(auto str: words) {
            string key = "";
            for(int i=1; i<str.size(); i++) {
                int diff = (str[i] - str[i-1] + 26) % 26;
                key += to_string(diff) + "#";
            }
            mp[key]++;
        }

        long long pairs = 0;
        for(auto i: mp) {
            long long k = i.second;
            pairs += (k*(k-1)) / 2;
        }

        return pairs;
    }
};

int main()
{
    vector<string> words = {"ab","aa","za","aa"};
    Solution s;
    cout<<s.countPairs(words)<<endl;
    return 0;
}