class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int len=nums.size();
		int left=0;
		int right=len-1;
		int mid=left+(right-left)/2;
		int flag=0;
		while(left<=right){
			if(nums[mid]==target){
				flag=1;
				break;
			}
			if(target>nums[mid]){
				left=mid+1;
			}else{
				right=mid-1;
			}
			mid=left+(right-left)/2;
		}
		if(flag==0){
			return {-1,-1};
		}
		else{
			for(int i=mid-1;i>=0;i--){
				if(nums[i]!=target){
					left=i+1;
					break;
				}
				if(i==0){
					left=0;
				}
			}
			for(int i=mid+1;i<len;i++){
				if(nums[i]!=target){
					right=i-1;
					break;
				}
				if(i==len-1){
					right=len-1;
				}
			}
			return {left,right};
		}
	}
};
