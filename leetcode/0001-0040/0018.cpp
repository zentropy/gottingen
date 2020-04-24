class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& n, int target) {	// 从0015复制的代码,忘记修改0为target
		vector<int> nums = n;
		std::sort(nums.begin(), nums.end());

		typedef std::vector< std::pair<int, std::pair<size_t,size_t> > > SORTED_VEC;
		SORTED_VEC sorted(nums.size()*(nums.size()-1)/2);
		for (size_t i = 0,p = 0; i < nums.size(); ++i)
		{
			for (size_t k = i + 1; k < nums.size(); ++k,++p)
			{
				sorted[p].first = nums[i] + nums[k];
				sorted[p].second.first = i;
				sorted[p].second.second = k;
			}
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
				SORTED_VEC::const_iterator itFind = std::lower_bound(sorted.begin(), sorted.end(), std::make_pair(target - v, std::make_pair(k + 1,k + 1)));
				if (itFind == sorted.end()) continue;
				if (v + itFind->first != target) continue;
				size_t prev = (size_t)(-1);
				for (SORTED_VEC::const_iterator it = itFind; it != sorted.end() && it->first + v == target; ++it)
				{
					size_t p = it->second.first, q = it->second.second;
					if ((size_t)(-1) != prev && nums[p] == nums[prev]) continue;
					prev = p;

					vector<int> ans(4);
					ans[0] = nums[i]; ans[1] = nums[k];ans[2] = nums[p]; ans[3] = nums[q];
					ret.push_back(ans);
				}
			}
		}
		return ret;
	}
};