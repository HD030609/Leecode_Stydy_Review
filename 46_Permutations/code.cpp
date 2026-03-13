class Solution {
public:
	void permutecal(vector<int>& nums, vector<vector<int>> & ans, int start) {
		if (start == nums.size()) {
			ans.push_back(nums);
			return;
		}
		for(int i=start;i<nums.size();i++){
			swap(nums[start],nums[i]);
			permutecal(nums,ans,1+start);
			swap(nums[start],nums[i]);
		}
	}
	
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		permutecal(nums, ans, 0);
		return ans;
	}
};
