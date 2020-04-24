class Solution {
public:
	int threeSumClosest(vector<int>& n, int target) {
		size_t size = n.size();
		if (size < 3) return 0;
		vector<int> nums = n;
		std::sort(nums.begin(), nums.end());

		int ret = nums[0] + nums[1] + nums[2] - target;
		for (size_t i = 0; i < size; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (size_t k = i + 1; k + 1 < size; ++k)
			{
				if (k > i + 1 && nums[k] == nums[k - 1]) continue;
				int v = nums[i] + nums[k];

				vector<int>::const_iterator itFind = std::lower_bound(nums.begin() + k + 1, nums.end(), target - v);
				if (itFind != nums.end())
				{
					int result = v + *itFind;
					if (result == target) return target;
					assert(result > target);
					if (result - target < abs(ret)) ret = result - target;
					if (nums.begin() + k + 1 != itFind)
					{
						int loresult = v + *(itFind - 1);
						assert(loresult < target);
						if (target - loresult < abs(ret)) ret = loresult - target;
					}
				}
				else
				{
					int result = v + nums[size - 1];
					assert(result < target);
					if (target - result < abs(ret)) ret = result - target;
				}
			}
		}
		return ret + target;
	}
};