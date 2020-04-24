class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& n) {
		vector<int> nums = n;
		std::sort(nums.begin(), nums.end());
		
		typedef std::vector< std::pair<int, size_t> > SORTED_VEC;
		SORTED_VEC sorted(nums.size());
		for (size_t i = 0; i < nums.size(); ++i)
		{
			sorted[i].first = nums[i];
			sorted[i].second = i;
		}
		std::sort(sorted.begin(), sorted.end());
		vector< vector<int> > ret;
		for (size_t i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (size_t k = i + 1; k < nums.size(); ++k)
			{
				if (k > i + 1 && nums[k] == nums[k - 1]) continue;
				int v = nums[i] + nums[k];
				SORTED_VEC::const_iterator itFind = std::lower_bound(sorted.begin(), sorted.end(), std::make_pair(0 - v, k + 1));
				if (itFind == sorted.end()) continue;
				if (v + itFind->first != 0) continue;
				vector<int> ans(3);
				ans[0] = nums[i]; ans[1] = nums[k]; ans[2] = 0 - v;
				ret.push_back(ans);
			}
		}
		return ret;
	}
};