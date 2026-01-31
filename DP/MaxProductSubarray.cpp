#include <bits/stdc++.h>
using namespace std;

// Brute force approach

// class Solution
// {
//     private:
//     vector<int> subArray(vector<int> nums) {
//         int n = nums.size();
//         vector<int> sums;

//         for(int i=0; i<n; i++) {
//             int sum=1;
//             for(int j=i; j<n; j++) {
//                 sum *= nums[j];
//                 sums.push_back(sum);
//             }
//         }

//         return sums;
//     }
// public:
//     int maxProduct(vector<int> &nums)
//     {
//         vector<int> sums = subArray(nums);
//         for(auto i:sums) {
//             cout<<i<<" ";
//         }cout<<endl;

//         int max = INT_MIN;
//         for(auto i:sums) {
//             if(i>max) {
//                 max = i;
//             }
//         }

//         return max;

//     }
// };

// int main()
// {
//     vector<int> nums = {2,3,-2,4};
//     Solution s;
//     cout<<s.maxProduct(nums)<<endl;

//     return 0;
// }

// optimal approach

class Solution
{

public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = nums[0], mini = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            int oldMax = maxi;
            int oldMin = mini;
            maxi = max(curr, max(oldMax * curr, oldMin * curr));
            mini = min(curr, min(oldMax * curr, oldMin * curr));

            ans = max(ans, maxi);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, -2, 4};
    Solution s;
    cout << s.maxProduct(nums) << endl;

    return 0;
}