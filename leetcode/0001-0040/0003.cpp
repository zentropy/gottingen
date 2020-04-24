// 没有考虑到的情况
// "" -> 0
// " " -> 1
// "dvdf" -> 3

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        static const size_t max_charset = 0x100;
        int pos[max_charset] = { 0 };
        for(size_t i = 0;i < max_charset;++i) pos[i] = -1;			// 随手,这里误写成i < len
        size_t len = s.size();
        int ans = 0,lastnot = -1;
        for(size_t i = 0;i < len;++i)
        {
            if(pos[s[i]] > lastnot)
            {
                int current = i - 1 - lastnot;
                if(current > ans) ans = current;
                lastnot = pos[s[i]];
            }
            pos[s[i]] = i;
        }
        int current = len - 1 - lastnot;
        if(current > ans) ans = current;
        return ans;
    }
};