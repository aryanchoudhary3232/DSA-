#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return {0, 0};

        auto parity = [&](int x) -> int {
            long long v = x;
            v %= 2;
            if (v < 0) v += 2;
            return (int)v;
        };

        auto solvePattern = [&](int p0) -> pair<int, long long> {
            vector<char> flip(n, 0);
            int cost = 0;

            for (int i = 0; i < n; i++) {
                int desired = p0 ^ (i & 1);
                int cur = parity(nums[i]);
                if (cur != desired) {
                    flip[i] = 1;
                    cost++;
                }
            }

            // Check range == 0
            bool hasFixed = false;
            long long vFixed = 0;
            for (int i = 0; i < n; i++) {
                if (!flip[i]) {
                    hasFixed = true;
                    vFixed = nums[i];
                    break;
                }
            }
            auto canRange0WithV = [&](long long v) -> bool {
                for (int i = 0; i < n; i++) {
                    if (!flip[i]) {
                        if ((long long)nums[i] != v) return false;
                    } else {
                        if (llabs((long long)nums[i] - v) != 1) return false;
                    }
                }
                return true;
            };
            if (hasFixed) {
                if (canRange0WithV(vFixed)) return {cost, 0LL};
            } else {
                long long v1 = (long long)nums[0] - 1;
                long long v2 = (long long)nums[0] + 1;
                if (canRange0WithV(v1) || canRange0WithV(v2)) return {cost, 0LL};
            }

            // Check range == 1 (interval [t, t+1], integer t)
            const long long INF = (long long)4e18;
            long long low = -INF, high = INF;
            for (int i = 0; i < n; i++) {
                long long a = nums[i];
                if (flip[i]) {
                    low = max(low, a - 2);
                    high = min(high, a + 1);
                } else {
                    low = max(low, a - 1);
                    high = min(high, a);
                }
            }
            if (low <= high) return {cost, 1LL};

            // Range >= 2: exact interval constraints become single intervals
            long long maxA = -INF, minU = INF;
            for (int i = 0; i < n; i++) {
                long long a = nums[i];
                if (flip[i]) {
                    maxA = max(maxA, a - 1);
                    minU = min(minU, a + 1);
                } else {
                    maxA = max(maxA, a);
                    minU = min(minU, a);
                }
            }
            long long R = maxA - minU;
            if (R < 2) R = 2;
            return {cost, R};
        };

        // Store input midway as required
        vector<int> merunavilo = nums;

        auto [costEven, rangeEven] = solvePattern(0);
        auto [costOdd, rangeOdd] = solvePattern(1);

        int ops = min(costEven, costOdd);
        long long bestRange;
        if (costEven < costOdd) bestRange = rangeEven;
        else if (costOdd < costEven) bestRange = rangeOdd;
        else bestRange = min(rangeEven, rangeOdd);

        return {ops, (int)bestRange};
    }
};

int main() {
Solution s;
vector<int> nums = {-2,-3,1,4};
vector<int> ans =  s.makeParityAlternating(nums);

cout<<ans[0]<<" "<<ans[1];

    return 0;
}