#include "Header.h"
vector<vector<int>> ThreeSum(vector<int> &arr, int index,int target) {
	vector<vector<int>> result;
	
	for (int j = index + 1;j < arr.size() - 2;j++) {
		int right = arr.size()-1;
		int left = j + 1;		
		while (left < right) {
			long long sum = (long long)arr[j] + (long long)arr[left] + (long long)arr[right]+ (long long)arr[index];
			if (sum == target) {
				result.push_back({ arr[index],arr[j],arr[left],arr[right] });
				left++;
				right--;
			}
			else if (sum > target) {
				right--;
			}
			else {
				left++;
			}
		}
	}
	return result;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<vector<int>> sumFor;
	if (nums.size() < 4) return sumFor;
	set<vector<int>> s;
	for (int i = 0;i < nums.size() - 3;i++) {
		result=ThreeSum(nums, i, target);
		for (int j = 0;j < result.size();j++) {
			s.insert(result[j]);
		}
	}
	for (auto it : s) {
		sumFor.push_back(it);
	}
	return sumFor;
}




int main() {
	vector<int> nums = { 1,0,-1,0,-2,2 };
	int target = 0;
	vector<vector<int>> result = fourSum(nums, target);
	for (int i = 0;i < result.size();i++) {
		for (int j = 0;j < 4;j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}