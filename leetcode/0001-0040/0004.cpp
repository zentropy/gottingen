class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
public:
    double help(const vector<int>& nums1, const vector<int>& nums2,size_t b1,size_t e1,size_t b2,size_t e2,bool odd)
    {
		if(odd)
		{
		}
        int m1 = (b1+e1)/2,m2 = (b2 + e2)/2;
        int v1 = nums1[m1],v2 = nums2[m2];
        if(v1 > v2) return help(nums1,nums2,b1,m1,m2,e2);
        if(v1 < v2) return help(nums1,nums2,m1,e1,b2,m2);
        
    }
};