class Solution {
public:
	bool IsHighest(vector<int> nums) {
		bool flag = true;
		int length = nums.size();
		for (int i = 0; i < length - 1; i++) {
			if (nums[i] < nums[i + 1]) {
				flag = false;
				break;
			}
		}
		return flag;
	}
	
	void nextPermutation(vector<int>& nums) {
		int length = nums.size();
		if (length == 1) {
			return;
		}
		if (IsHighest(nums)) {
			int temp = 0;
			for (int i = 0; i < length / 2; i++) {
				temp = nums[i];
				nums[i] = nums[length - i - 1];
				nums[length - i - 1] = temp;
			}
			return;
		}
		
		for (int i = length - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				//找要和nums[i]交换的元素
				int index=-1;
				for(int j=length-1;j>i;j--){
					if(nums[j]>nums[i]){
						index=j;
						break;
					}
				}
				int temp = nums[i];
				nums[i] = nums[index];
				nums[index] = temp;
				for (int j = i+1; j < length - 1; j++) {
					for (int k = j + 1; k < length; k++) {
						if (nums[k] < nums[j]) {
							int temp = nums[j];
							nums[j] = nums[k];
							nums[k] = temp;
						}
					}
				}
				break;
			}
		}
	}
};
