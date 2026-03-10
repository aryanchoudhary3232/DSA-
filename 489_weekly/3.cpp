#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int expandAroundCenter(const string &s, int l, int r)
    {
        int best = 0;

        int n = s.size();
        while (l >= 0 && r < n)
        {
            if (s[l] == s[r])
            {
                best = r - l + 1;
                l--;
                r++;
            }
            else
            {

                for (int i = l - 1, j = r; i >= 0 && j < n; i--, j++)
                {
                    if (s[i] == s[j])
                    {
                        best = max(best, j - i + 1);
                    }
                    else
                    {
                        break;
                    }
                }

                for (int i = l, j = r + 1; i >= 0 && j < n; i--, j++)
                {
                    if (s[i] == s[j])
                    {
                        best = max(best, j - i + 1);
                    }
                    else
                    {
                        break;
                    }
                }

                break;
            }
        }

        return best;
    }

public:
    int almostPalindromic(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int odd = expandAroundCenter(s, i, i);
            int even = expandAroundCenter(s, i, i + 1);

            ans = max(ans, max(odd, even));
        }

        return ans;
    }
};

int main()
{
    string s = "abca";

    Solution s1;
    int ans = s1.almostPalindromic(s);
    cout << ans;
    return 0;
}