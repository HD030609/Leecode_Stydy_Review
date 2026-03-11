class Solution {
public:
	void dfs(int target, vector<int>& candidates, int idx, vector<int>& combine,
		vector<vector<int>>& ans) {
			if (idx == candidates.size()) {
				return;
			}
			if (target == 0) {
				ans.emplace_back(combine);
				return;
			}
			dfs(target, candidates, idx + 1, combine, ans);
			
			if (target - candidates[idx] >= 0) {
				combine.emplace_back(candidates[idx]);
				dfs(target - candidates[idx], candidates, idx, combine, ans);
				combine.pop_back();
			}
		}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combine;
		dfs(target, candidates, 0, combine, ans);
		return ans;
	}
};
