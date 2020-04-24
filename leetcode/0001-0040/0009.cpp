class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long ret = 0,v = x;
        for(;v != 0;v /= 10)
        {
            ret *= 10;
            ret += v%10;
        }
        return (ret == x);
    }
};