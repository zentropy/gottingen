class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(0 == strs.size()) return "";
        if(1 == strs.size()) return strs[0];
        size_t len = 0;
        for(size_t i = 0;i < strs[0].size();++i)
        {
            size_t k = 1;
            for(;k < strs.size() && i < strs[k].size() && strs[0][i] == strs[k][i];++k);
            if(k != strs.size())
            {
                break;
            }
            else
            {
                len = i + 1;
            }
        }
        return strs[0].substr(0,len);
    }
};