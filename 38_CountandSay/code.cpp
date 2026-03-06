class Solution {
public:
	string Count(string str) {
		int len = str.size();
		int index = 0;
		int count = 1;
		string result;
		while (index < len) {
			while (str[index] == str[index + 1]) {
				count++;
				index++;
			}
			result.push_back(count+'0');
			result.push_back(str[index]);
			count=1;
			index++;
		}
		return result;
	}
	string Array(int n) {
		if (n == 1) {
			return "1";
		}
		return Count(Array(n - 1));
	}
	
	string countAndSay(int n) { return Array(n); }
};
