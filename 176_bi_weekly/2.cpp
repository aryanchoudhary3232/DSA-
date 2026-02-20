#include <bits/stdc++.h>
using namespace std;

// brute force approach (TLE)
//  class Solution {
//  public:
//      int prefixConnected(vector<string>& words, int k) {
//          int ans = 0;
//          map<string, int> mp;

//         for (int i = 0; i < words.size(); i++) {
//             for (int j = i + 1; j < words.size(); j++) {
//                 bool check = false;
//                 string s = "";
//                 for (int x = 0; x < k; x++) {
//                     if (words[i].size() >= k && words[j].size() >= k) {
//                         if (words[i][x] != words[j][x]) {
//                             check = false;
//                             break;

//                         } else if (words[i][x] == words[j][x]) {
//                             check = true;
//                             s += words[j][x];
//                         }
//                     }
//                 }
//                 if (check) {
//                     if (mp.find(s) != mp.end()) {
//                         continue;
//                     } else {
//                         mp[s] = j;
//                         ans++;
//                     }
//                 }
//             }
//         }

//         return ans;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<string> words = {"bat","dog","dog","doggy","bat"};
//     int k = 3;
//     cout<<s.prefixConnected(words, k);

//     return 0;
// }

// approach 2
class Solution
{
public:
    int prefixConnected(vector<string> &words, int k)
    {
        map<string, int> mp;
        int count = 1;
        for (int i = 0; i < words.size(); i++)
        {

            if (words[i].length() >= k)
            {
                string s = "";
                for (int j = 0; j < k; j++)
                {
                    s += words[i][j];
                }
                if (mp.find(s) != mp.end())
                {
                    int cnt = mp[s];
                    mp[s] = cnt + 1;
                }
                else
                {
                    mp[s] = count;
                }
            }
        }

        int ans = 0;
        for(auto i:mp) {
            if(i.second >= 2) {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"bat", "dog", "dog", "doggy", "bat"};
    int k = 3;
    cout << s.prefixConnected(words, k);

    return 0;
}