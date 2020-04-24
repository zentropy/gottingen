#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		typedef std::pair<int,size_t> pair_t;
        size_t size = nums.size();
        std::vector<pair_t> data(size);
        for(size_t i = 0;i < size;++i)
        {
            data[i].first = nums[i];
            data[i].second = i;
        }
        std::sort(data.begin(),data.end());
        for(size_t i = 0;i < size;++i)
        {
            int v = target - data[i].first;
			std::vector<pair_t>::const_iterator itFind = std::lower_bound(data.begin()+i+1,data.end(),pair_t(v,0));
			if(itFind == data.end()) continue;
			if(itFind->first != v) continue;
			vector<int> ret;
			ret.push_back(data[i].second);			// 第一次提交,太过随手,这里写成ret.push_back(i),错误case:[3,2,4] 6
			ret.push_back(itFind->second);
			return ret;
        }
    }
};