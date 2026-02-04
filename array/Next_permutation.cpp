#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int idx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (i > 0 && nums[i - 1] < nums[i])
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        int justgreater = nums[idx];
        int currEle = nums[idx - 1];
        int swapingIdx = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > currEle)
            {
                swapingIdx = i;
                break;
            }
        }

        swap(nums[idx - 1], nums[swapingIdx]);
        sort(nums.begin() + idx, nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 2};
    s.nextPermutation(nums);
    for (auto i : nums)
    {
        cout << i << " ";
    }

    return 0;
}