class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            // Edge cases (avoid out-of-bounds)
            if (n == 1) return nums[0];
            if (mid == 0 && nums[mid] != nums[mid + 1]) return nums[mid];
            if (mid == n - 1 && nums[mid] != nums[mid - 1]) return nums[mid];

            // Check for single element safely
            if (mid > 0 && mid < n - 1 &&
                nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Binary search logic
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return -1; // Should never reach here
    }
};
