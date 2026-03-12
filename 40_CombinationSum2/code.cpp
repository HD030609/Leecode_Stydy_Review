class Solution {
public:
	void dfs(int target, vector<int>& candidates, int idx, vector<int>& combine,
		vector<vector<int>>& ans) {
			if (target == 0) {
				ans.emplace_back(combine);
				return;
			}
			if (idx == candidates.size() || target < candidates[idx]) {
				return;
			}
			
			for (int i = idx; i < candidates.size(); i++) {
				if (i > idx && candidates[i] == candidates[i - 1]) {
					continue;
				}
				combine.emplace_back(candidates[i]);
				dfs(target - candidates[i], candidates, i + 1, combine, ans);
				combine.pop_back();
			}
		}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combine;
		sort(candidates.begin(), candidates.end());
		dfs(target, candidates, 0, combine, ans);
		return ans;
	}
};
