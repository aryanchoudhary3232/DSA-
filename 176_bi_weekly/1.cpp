#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mapWordWeights(vector<string> &words, vector<int> &weights)
    {
        string ans = "";
        for (int i = 0; i<words.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < words[i].size(); j++)
            {
                int idx = words[i][j] - 'a';
                int weight = weights[idx];
                sum += weight;
            }
            sum %= 26;
            char c = 'z' - sum;
            ans += c;
        }

        return ans;
    }
};

int main()
{
    vector<string> words = {"abcd", "def", "xyz"};
    vector<int> weights = {5, 3, 12, 14, 1, 2, 3, 2, 10, 6, 6, 9, 7, 8, 7, 10, 8, 9, 6, 9, 9, 8, 3, 7, 7, 2};

    Solution s;
    cout<<s.mapWordWeights(words, weights);
  
    return 0;
}