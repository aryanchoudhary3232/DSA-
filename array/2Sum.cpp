#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0; i<nums.size(); i++) {
            if(mp.find(target-nums[i]) != mp.end()) {
                return {mp[target-nums[i]],i};
            }else {
                mp[nums[i]] = i;
            }
        }

        return {-1,-1};
        
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 18;

    vector<int> ans = s.twoSum(nums, target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}