class Solution {
public:
	int search(vector<int>& nums, int target) {
		size_t size = nums.size();
		if (0 == size) return -1;
		if (1 == size)
		{
			if (nums[0] == target) return 0;
			return -1;
		}
		if (nums[0] < nums[size - 1]) return find_value(nums, target, 0, size);
		int pos = find_max(nums);
		if (target >= nums[0]) return find_value(nums, target, 0, pos + 1);
		else return find_value(nums, target, pos + 1, size);
	}
private:
	int find_value(const vector<int>& nums, int target, int lo, int hi)
	{
		for (; lo < hi;)
		{
			int mid = (lo + hi) / 2;
			if (nums[mid] == target) return mid;
			if (nums[mid] > target) hi = mid;
			else lo = mid + 1;
		}
		return -1;
	}
private:
	int find_max(const vector<int>& nums)
	{
		int lo = 0, hi = nums.size();
		for (; lo < hi;)
		{
			int mid = (lo + hi) / 2;
			if (nums[mid] > nums[lo]) lo = mid;
			else hi = mid;
		}
		return lo;
	}
};