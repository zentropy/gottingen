class Solution {
public:
    int myAtoi(string str) {
        size_t p = 0,len = str.size();
        for(;p < len && str[p] == ' ';++p);
        if(p == len) return 0;
        if((str[p] < '0' || str[p] > '9') && str[p] != '-' && str[p] != '+') return 0;
        bool neg = false,overflow = false;
        long long ret = 0;
        if('-' == str[p]) neg = true;
        else if('+' == str[p]) neg = false;					//
        else ret = str[p] - '0';
        for(++p;p < len && !overflow;++p)
        {
            if(str[p] < '0' || str[p] > '9') break;
            ret *= 10;
            ret += (str[p] - '0');
            if(ret > 2147483648) overflow = true;          // 注意12345678901234567890 这种用例
            else if(ret == 2147483648 && !neg) overflow = true;
        }
        if(overflow)
        {
            if(neg) return -2147483648;
            else return 2147483647;
        }
        else
        {
            if(neg) return (int)(0 - ret);
            else return ret;
        }
    }
};