class Solution {
public:
	bool isValidBox(vector<char> nums) {
		int len = nums.size();
		int a[10] = {0};
		char so;
		for (int i = 0; i < len; i++) {
			so = nums[i];
			switch (so) {
			case '1':
				a[0]++;
				if (a[0] > 1) {
					return false;
				}
				break;
			case '2':
				a[1]++;
				if (a[1] > 1) {
					return false;
				}
				break;
			case '3':
				a[2]++;
				if (a[2] > 1) {
					return false;
				}
				break;
			case '4':
				a[3]++;
				if (a[3] > 1) {
					return false;
				}
				break;
			case '5':
				a[4]++;
				if (a[4] > 1) {
					return false;
				}
				break;
			case '6':
				a[5]++;
				if (a[5] > 1) {
					return false;
				}
				break;
			case '7':
				a[6]++;
				if (a[6] > 1) {
					return false;
				}
				break;
			case '8':
				a[7]++;
				if (a[7] > 1) {
					return false;
				}
				break;
			case '9':
				a[8]++;
				if (a[8] > 1) {
					return false;
				}
				break;
			default:
				break;
			}
		}
		return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<char> nums;
		int row = board.size();
		int column = board[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				nums.push_back(board[i][j]);
			}
			if (!isValidBox(nums)) {
				return false;
			}
			nums.clear();
		}
		
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < row; j++) {
				nums.push_back(board[j][i]);
			}
			if (!isValidBox(nums)) {
				return false;
			}
			nums.clear();
		}
		
		for (int i = 0; i < row; i += 3) {
			for (int j = 0; j < column; j += 3) {
				for (int m = 0; m < 3; m++) {
					for (int n = 0; n < 3; n++) {
						nums.push_back(board[i + m][j + n]);
					}
				}
				if (!isValidBox(nums)) {
					return false;
				}
				nums.clear();
			}
		}
		return true;
	}
};
