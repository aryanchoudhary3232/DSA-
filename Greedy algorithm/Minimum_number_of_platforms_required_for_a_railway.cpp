#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPlatorms(vector<int> start, vector<int> end)
    {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int size = start.size();

        int p1 = 1, p2 = 0;
        int n = 1;
        int ans = 1;
        while (p1 < size)
        {
            if (start[p1] > end[p2])
            {
                n--;
                p2++;
            }
            else
            {
                n++;
                p1++;
            }

            ans = max(ans, n);
        }

        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> start = {900, 940, 950, 1100, 1500, 1800};
    vector<int> end = {910, 1200, 1120, 1130, 1900, 2000};
    cout<<s.minPlatorms(start, end)<<endl;

    return 0;
}