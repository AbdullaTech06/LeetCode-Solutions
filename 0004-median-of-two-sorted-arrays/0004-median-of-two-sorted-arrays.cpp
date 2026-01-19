class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int i = 0, j = 0;
        vector<int> arr;

        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i++]);
            } else {
                arr.push_back(nums2[j++]);
            }
        }

        while (i < m) arr.push_back(nums1[i++]);
        while (j < n) arr.push_back(nums2[j++]);

        int sz = arr.size();

        if (sz % 2 == 1) {
            return arr[sz / 2];
        } else {
            return (arr[sz / 2 - 1] + arr[sz / 2]) / 2.0;
        }
    }
};
