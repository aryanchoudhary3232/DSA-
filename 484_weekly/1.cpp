#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDistinctChar(string s) {
        vector<bool> visited(256,false);
        int len = 0;
        for(auto c: s) {
            if(!visited[c]) {
                visited[c] = true;
                len++;
            }
        }

        return len;
    }


    int residuePrefixes(string s)
    {
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            string prefix = s.substr(0, i + 1);
            int len = findDistinctChar(prefix);
            if(len == (prefix.length() % 3)) {
                cnt++;
            }
        }

        return cnt;
    }
};

int main()
{
    string str = "abc";
    Solution s;
    cout<<s.residuePrefixes(str)<<endl;

    return 0;
}