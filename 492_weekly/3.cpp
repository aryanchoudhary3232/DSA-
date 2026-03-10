class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;

        bool isSort=true;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] > s[i + 1]) {
                isSort = false;
                break;
            }
        }

        if (isSort)
            return 0;
        if (isSort == false && n == 2)
            return -1;

        char min_c = s[0], max_c = s[0];
        for (auto it : s) {
            if (it < min_c)
                min_c = it;
            if (it > max_c)
                max_c = it;
        }

        if ((s[0] == min_c && s[n - 1] == max_c) || (s[0] == min_c) ||
            (s[n - 1] == max_c))
            return 1;
        
        int max_count=0, min_count=0;
        for(auto it:s) {
            if(max_c == it) max_count++;
            if(min_c == it) min_count++;
        }

        if(s[0]==max_c && s[n-1]==min_c && max_count==1 && min_count==1) return 3;

        if ((s[0] != min_c && s[n - 1] != max_c) ||
            (s[0] == max_c && s[n - 1] != min_c) ||
            (s[n - 1] == min_c && s[0] != max_c))
            return 2;

        return -1;
    }
};