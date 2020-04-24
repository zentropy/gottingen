// 后缀数组O(n)算法,一般动态规划O(n^2)

// "cbbd"	->			"bb"		dps[curr][k].from = (0 == dps[prev][k - 1].value)?i:dps[prev][k - 1].from;
// "aacdefcaa" ->		"aa"
// "aaaa" -> 			"aaaa"
class Solution {
public:
	string longestPalindrome(string s) {
		if (0 == s.size()) return "";
		vector<bool> dps[2][2];
		dps[0][0].resize(s.size(), false); dps[0][1].resize(s.size(), false);
		dps[1][0].resize(s.size(), false); dps[1][1].resize(s.size(), false);
		size_t prev = 0, curr = 1, odd = 1, even = 0, maxfrom = 0, maxvalue = 1;
		for (int i = 0; i < s.size(); ++i)
		{
			dps[prev][odd][i] = true;
			dps[prev][even][i] = false;
			if (i + 1 < s.size()) dps[prev][even][i] = (s[i] == s[i + 1]);
			if (dps[prev][even][i])
			{
				maxvalue = 2;
				maxfrom = i;
			}
		}
		for (int i = 1; i < s.size(); ++i)
		{
			for (int k = 0; k < s.size(); ++k)
			{
				dps[curr][odd][k] = updateOdd(s, k, i, dps[prev][odd][k], maxfrom, maxvalue);
			}
			for (int k = 0; k < s.size(); ++k)
			{
				dps[curr][even][k] = updateEven(s, k, i, dps[prev][even][k], maxfrom, maxvalue);
			}
			prev ^= curr; curr ^= prev; prev ^= curr;
		}
		assert(maxfrom + maxvalue <= s.size());
		return s.substr(maxfrom, maxvalue);
	}
private:
	struct data_t
	{
		size_t from;
		size_t value;
	public:
		data_t() :value(0), from(0) { ; }
	};
private:
	bool updateOdd(const string& s, int pos, int len, bool prev, size_t& maxfrom, size_t& maxvalue)
	{
		bool ret = false;
		if (pos < len || pos + len >= s.size()) ret = false;
		else if (s[pos - len] == s[pos + len]) ret = prev;
		else ret = false;
		if (ret)
		{
			maxvalue = len * 2 + 1;
			maxfrom = pos - len;
		}
		return ret;
	}
	bool updateEven(const string& s, size_t pos, size_t len, bool prev, size_t& maxfrom, size_t& maxvalue)
	{
		bool ret = false;
		if (pos < len || pos + len + 1 >= s.size()) ret = false;
		else if (s[pos - len] == s[pos + len + 1]) ret = prev;
		else ret = false;
		if (ret)
		{
			maxvalue = len * 2 + 2;
			maxfrom = pos - len;
		}
		return ret;
	}
private:
	string longestCommonSubstr(const string& s, const string& t)
	{
		vector<data_t> dps[2];
		dps[0].resize(t.size()); dps[1].resize(t.size());
		size_t prev = 0, curr = 1, maxfrom = 0, maxvalue = 0;
		for (size_t i = 0; i < t.size(); ++i)
		{
			initValue(s[0], t[i], 0, dps[prev][i]);
			updateMax(dps[prev][i], maxfrom, maxvalue);
		}
		for (size_t i = 1; i < s.size(); ++i)
		{
			initValue(s[i], t[0], i, dps[curr][0]);
			updateMax(dps[curr][0], maxfrom, maxvalue);
			for (size_t k = 1; k < t.size(); ++k)
			{
				if (s[i] != t[k])
				{
					dps[curr][k].from = 0;
					dps[curr][k].value = 0;
				}
				else
				{
					dps[curr][k].value = dps[prev][k - 1].value + 1;
					dps[curr][k].from = (0 == dps[prev][k - 1].value) ? i : dps[prev][k - 1].from;
				}
				updateMax(dps[curr][k], maxfrom, maxvalue);
			}
			prev ^= curr; curr ^= prev; prev ^= curr;
		}
		if (0 == maxvalue) return "";
		assert(maxfrom + maxvalue <= s.size());
		return s.substr(maxfrom, maxvalue);
	}
private:
	void initValue(char s, char t, int pos, data_t& u)
	{
		if (s != t)
		{
			u.from = pos;
			u.value = 0;
		}
		else
		{
			u.value = 1;
			u.from = pos;
		}
	}
private:
	void updateMax(const data_t& u, size_t& maxfrom, size_t& maxvalue)
	{
		if (u.value > maxvalue)
		{
			maxvalue = u.value;
			maxfrom = u.from;
		}
	}
};