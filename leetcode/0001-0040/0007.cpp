class Solution {
public:
    int reverse(int x) {
        long long ret = 0,v = x;
        for(;v != 0;v /= 10)
        {
            ret *= 10;
            ret += v%10;
        }
		// 注意0 2147483647 -2147483648等特殊情况
        if(ret >= 2147483647 || ret < -2147483648) ret = 0;
        return (int)ret;
    }
};