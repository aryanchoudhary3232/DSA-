#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int centeredSubarrays(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                st.insert(nums[j]);

                if (st.count(sum))
                {
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<int> nums = {-1, 1, 0};
    Solution s;
    // vector<vector<int>> ans;
    // s.subarrayFind(nums, ans);
    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    cout << s.centeredSubarrays(nums) << endl;

    return 0;
}