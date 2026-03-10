#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeCharacters(string s, int k)
    {

        int i = 0;
        while (true)
        {
            int n = s.size();
            int originalSize = n;

            for (int i = 0; i < n; i++)
            {
                bool sizeReduce = false;
                for (int j = i + 1; j <= i + k && j<n; j++)
                {
                    if (s[i] == s[j])
                    {
                        s.erase(j, 1);
                        cout << s << endl;
                        n--;
                        sizeReduce = true;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }
                if (sizeReduce)
                    break;
            }

            if (originalSize == n)
                break;
        }

        return s;
    }
};

int main()
{
    Solution s;
    s.mergeCharacters("igg", 1);

    return 0;
}