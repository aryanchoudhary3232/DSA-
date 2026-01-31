#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        if (n == 1)
        {
            return nums[0];
        }

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (mid == 0)
            {
                if (nums[mid] != nums[mid + 1])
                {
                    return nums[mid];
                }
            }
            if (mid == n - 1)
            {
                if (nums[mid] != nums[mid - 1])
                {
                    return nums[mid];
                }
            }

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }

            if (mid % 2 == 0)
            {
                if (nums[mid] != nums[mid + 1])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if (nums[mid - 1] != nums[mid])
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 1, 2};
    cout << s.singleNonDuplicate(nums);

    return 0;
}