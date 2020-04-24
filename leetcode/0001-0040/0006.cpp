// "ab" 1 -> "ab"					numRows = 1的特殊情况没有考虑
// "abcd" 3 -> "abdc"				k*(numRows-1) >= len但是k*(numRows-1) - k可能小于len

class Solution {
public:
    string convert(string s, int numRows) {
        size_t len = s.size(),w = 1;
        if(len <= 1 || numRows <= 1 || len <= numRows) return s;
        string ret = s;
        for(size_t i = 1;i < len;++i) ret[i] = '@';
        size_t delta = 2*numRows - 2;
        for(size_t p = delta;p < len && w < len;p += delta,++w) ret[w] = s[p];
        for(size_t k = 1;k + 1 < numRows;++k)
        {
            ret[w] = s[k];++w;
            for(size_t p = delta;p - k < len && w < len;p += delta,++w)
            {
                ret[w] = s[p-k];
                if(p + k < len)
                {
                    ret[w+1] = s[p+k];
                    ++w;
                }
            }
        }
        for(size_t p = 1;w < len;p += 2,++w)
        {
            if((numRows-1)*p >= len) break;
            ret[w] = s[(numRows-1)*p];   
        }
        return ret;
    }
};