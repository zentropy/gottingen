class Solution {
public:
    bool isValid(string s) {					// 对于只有()的可以直接计算个数;对于这种可能嵌套的,栈实现
        size_t len = s.size();
        if(len&1) return false;
        std::vector<char> stk(len,' ');
        size_t p = 0;
        for(size_t i = 0;i < len;++i)
        {
            if('(' == s[i] || '[' == s[i] || '{' == s[i])
            {
                stk[p] = s[i];
                ++ p;
            }
            else if(')' == s[i])
            {
                if(0 == p) return false;
                --p;
                if(stk[p] != '(') return false;
            }
            else if(']' == s[i])
            {
                if(0 == p) return false;
                -- p;
                if(stk[p] != '[') return false;
                
            }
            else if('}' == s[i])
            {
                if(0 == p) return false;
                -- p;
                if(stk[p] != '{') return false;
            }
        }
        return (0 == p);
    }
};