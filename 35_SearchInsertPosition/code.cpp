class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int len = nums.size();
		if (target <= nums[0]) {
			return 0;
		}
		int left = 0;
		int right = len - 1;
		int mid = 0;
		while (left <= right) {
			mid = left + (right - left) / 2;
			if (nums[mid] == target) {
				return mid;
			}
			if (target < nums[mid]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		if (mid <= (left + right) / 2) {
			return mid + 1;
		} else {
			return mid;
		}
	}
};
