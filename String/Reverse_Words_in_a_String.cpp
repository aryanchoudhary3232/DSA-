#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string normalizeSpaces(string s)
    {
        string result = "";
        bool spaceFound = false;
        for (char c : s)
        {
            if (c != ' ')
            {
                result += c;
                spaceFound = false;
            }
            else
            {
                if (!spaceFound && !result.empty())
                {
                    result += " ";
                    spaceFound = true;
                }
            }
        }

        return result;
    }

public:
    string reverseWords(string s)
    {
        s = normalizeSpaces(s);
        vector<string> temp;
        string res = "";

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                res += s[i];
            }
            if (s[i] == ' ')
            {
                temp.push_back(res);
                if (i != s.size() - 1)
                {
                    temp.push_back(" ");
                }
                res = "";
            }
        }
        temp.push_back(res);

        string ans = "";
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            ans += temp[i];
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords(" abc ");
    cout << endl;
    return 0;
}