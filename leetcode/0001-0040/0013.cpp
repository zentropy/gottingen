class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(size_t i = 0,len = s.size();i < len;++i)
        {
			char c = s[i],next = ' ';
			if(i + 1 < len) next = s[i+1];
            if(c == 'I')
            {
                if(next == 'V') ret += 4,++i;
                else if(next == 'X') ret += 9,++i;
                else ret += 1;
            }
            else if(c == 'V') ret += 5;
            else if(c == 'X')
            {
                if(next == 'L') ret += 40,++i;
                else if(next == 'C') ret += 90,++i;
                else ret += 10;
            }
            else if(c == 'L') ret += 50;
            else if(c == 'C')
            {
                if(next == 'D') ret += 400,++i;
                else if(next == 'M') ret += 900,++i;
                else ret += 100;
            }
            else if(c == 'D') ret += 500;
            else if(c == 'M') ret += 1000;
        }
        return ret;
    }
};