class Solution {
public:
	bool IsSame(vector<int>& index, vector<int>& nums) {
		int len = index.size();
		for (int i = 0; i < len; i++) {
			if (index[i] != nums[i]) {
				return false;
			}
		}
		return true;
	}
	void permutecal(vector<int>& nums, vector<vector<int>>& temp,
		vector<vector<int>>& ans, int start) {
			if (start == nums.size()) {
				int flag = true;
				for (auto index : temp) {
					if (IsSame(index, nums)) {
						flag = false;
					}
				}
				if (flag) {
					ans.push_back(nums);
				}
				temp.push_back(nums);
				return;
			}
			for (int i = start; i < nums.size(); i++) {
				swap(nums[start], nums[i]);
				permutecal(nums, temp, ans, start + 1);
				swap(nums[start], nums[i]);
			}
		}
	
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<vector<int>> temp;
		ans.push_back(nums);
		temp.push_back(nums);
		permutecal(nums, temp, ans, 0);
		return ans;
	}
};
