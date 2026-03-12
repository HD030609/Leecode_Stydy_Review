class Solution {
public:
	int jump(vector<int>& nums) {
		int step = 0;
		int position = nums.size() - 1;
		while (position > 0) {
			for (int i = 0; i < position; i++) {
				if (nums[i] + i >= position) {
					position = i;
					step++;
					break;
				}
			}
		}
		return step;
	}
};
