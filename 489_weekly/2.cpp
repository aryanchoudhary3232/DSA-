#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstUniqueFreq(vector<int> &nums)
    {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(nums[i]) != mp.end())
            {
                int count = mp[nums[i]];
                count++;
                mp[nums[i]] = count;
            }
            else
            {
                mp[nums[i]] = 1;
            }
        }

        map<int, int> freqCount;
        for (auto i : mp)
        {
            int freq = i.second;

            if (freqCount.find(freq) != freqCount.end())
            {
                int count = freqCount[freq];
                count++;
                freqCount[freq] = count;
            }
            else
            {
                freqCount[freq] = 1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int freq = mp[nums[i]];
            if (freqCount[freq] != 1)
            {
                continue;
            }
            else
            {
                return nums[i];
            }
        }

        return -1;
    }
};

int main()
{
    vector<int> nums = {20, 10, 30, 30};

    Solution s;
    int ans = s.firstUniqueFreq(nums);
    cout << ans;
    return 0;
}