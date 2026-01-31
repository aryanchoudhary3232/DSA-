#include <bits/stdc++.h>
using namespace std;

// approach 1
//  class Solution
//  {
//  private:
//      vector<string> substr(string s)
//      {
//          vector<string> str;
//          for (int i = 0; i < s.size(); i++)
//          {
//              string temp = "";

//             for (int j = i; j < s.size(); j++)
//             {
//                 temp += s[j];
//                 str.push_back(temp);
//             }
//         }

//         return str;
//     }

//     bool isPalindrome(string s)
//     {
//         int n = s.size();
//         for (int i = 0; i < n / 2-1; i++)
//         {
//             if (s[i] != s[n - i - 1])
//             {
//                 return false;
//             }
//         }

//         return true;
//     }

// public:
//     string longestPalindrome(string s)
//     {
//         vector<string> subStr = substr(s);

//         string maxi = "";
//         for (int i = 0; i < subStr.size(); i++)
//         {
//             if (isPalindrome(subStr[i]))
//             {
//                 if (subStr[i].length() > maxi.length())
//                 {
//                     maxi = subStr[i];
//                 }
//             }
//         }

//         return maxi;
//     }
// };

// int main()
// {
//     Solution s;
//     cout << s.longestPalindrome("babad");

//     return 0;
// }

// approach 2

class Solution
{
private:
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        int n = s.size();
        while (left>=0 && right<n && s[left] == s[right])
        {
            left--;
            right++;
        }

        return {left+1, right-1};
    }

public:
    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            pair<int, int> odd = expandAroundCenter(s, i, i);
            pair<int, int> even = expandAroundCenter(s, i, i + 1);

            if(odd.second - odd.first > end - start) {
                start = odd.first;
                end = odd.second;
            }
            if(even.second - even.first > end - start) {
                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start,end-start+1);
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babadda");

    return 0;
}