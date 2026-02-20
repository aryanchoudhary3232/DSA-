#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> toggleLightBulbs(vector<int> &bulbs)
    {
        map<int, bool> mp;
        for (auto i : bulbs)
        {
            if (mp.find(i) != mp.end())
            {
                mp[i] = !mp[i];
            }
            else
            {
                mp[i] = true;
            }
        }

        vector<int> ans;
        for (auto i : mp)
        {
            if (i.second)
            {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> bulbs = {100,100};

    Solution s;
    vector<int> ans = s.toggleLightBulbs(bulbs);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}