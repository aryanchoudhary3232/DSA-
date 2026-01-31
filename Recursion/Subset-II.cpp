#include <bits/stdc++.h>
using namespace std;

// approach 1
// class Solution
// {
// private:
//     set<vector<int>> st;
//     void subset(int i, vector<int> &nums, vector<int> temp)
//     {
//         if (i == nums.size())
//         {
//             st.insert(temp);
//             return;
//         }
//         temp.push_back(nums[i]);
//         subset(i + 1, nums, temp);
//         temp.pop_back();
//         subset(i + 1, nums, temp);
//     }

// public:
//     vector<vector<int>> subsetsWithDup(vector<int> &nums)
//     {
//         vector<int> temp;
//         sort(nums.begin(), nums.end());
//         subset(0, nums, temp);

//         vector<vector<int>> ans;
//         for (auto i : st)
//         {
//             ans.push_back(i);
//         }

//         return ans;
//     }
// };

// int main()
// {
//     Solution s;
//     vector<int> nums = {1, 2, 2};
//     vector<vector<int>> ans = s.subsetsWithDup(nums);
//     for (auto i : ans)
//     {
//         cout << "[";
//         for (auto j : i)
//         {
//             cout << j;
//         }
//         cout << "]" << " ";
//     }

//     return 0;
// }

// approach 2

class Solution
{
private:
    void subset(int start, vector<int> &nums, vector<int> temp, vector<vector<int>> &ans)
    {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            temp.push_back(nums[i]);
            subset(i + 1, nums, temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> temp;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        subset(0, nums, temp, ans);

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    for (auto i : ans)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j;
        }
        cout << "]" << " ";
    }

    return 0;
}
