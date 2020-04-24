class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0 == nums.size()) return 0;
        int tor = 1;
        for(;tor < nums.size() && nums[tor] != nums[tor-1];++tor);
        if(tor == nums.size()) return tor;
        int tow = tor;++tor;
        for(;tor < nums.size();++tor)
        {
            if(nums[tor] != nums[tor-1])
            {
                nums[tow] = nums[tor];
                ++ tow;
            }
        }
        return tow;
    }
};