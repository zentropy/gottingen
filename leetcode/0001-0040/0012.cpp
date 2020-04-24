class Solution {
public:
    string intToRoman(int num) {
        static const unsigned int base_count = 4;
        static const unsigned int bases[base_count] = { 1,10,100,1000 };
        static const unsigned int digit_count = 10;
        static const std::string nums[base_count][digit_count]= 
        {
            {"","I","II","III","IV","V","VI","VII","VIII","IX"},
            {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
            {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
            {"","M","MM","MMM","","","","","","" }
        };
        int p = base_count - 1;
        for(;p >= 0 && num < bases[p];--p);
        std::string ret = "";
        for(;p >= 0 && 0 != num;--p)
        {
            int v = num/bases[p];
            num = num - bases[p]*v;
            ret += nums[p][v];
        }
        return ret;
    }
};