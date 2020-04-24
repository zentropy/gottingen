static const size_t digit_size = 10;
static const std::string digit_reps[digit_size] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
	vector<string>			_ret;
	vector<unsigned int>	_values;
	vector<unsigned int>	_limits;
	std::string				_digits;
public:
	vector<string> letterCombinations(string digits) {
		size_t len = digits.size();
		_values.resize(len, 0); _limits.resize(len);
		_digits = digits;
		for (size_t i = 0; i < len; ++i) _limits[i] = digit_reps[digits[i] - '0'].size();
		generate(0, len);
		return _ret;
	}
private:
	void generate(size_t pos,size_t len)
	{
		if (pos == len)
		{
			std::string ans;
			for (size_t i = 0; i < len; ++i) ans.push_back(digit_reps[_digits[i] - '0'][_values[i]]);
			if(0 != len) _ret.push_back(ans);               // 注意""
			return;
		}
		for (size_t i = 0; i < _limits[pos]; ++i)
		{
			_values[pos] = i;
			generate(pos + 1, len);
		}
	}
};