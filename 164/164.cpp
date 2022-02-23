#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maximumGap_2(vector<int>& nums) {			//自带sort
	if (nums.size() < 2)return 0;
	sort(nums.begin(), nums.end());
	int maxlen = 0;
	int x = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if ((nums[i] - x) > maxlen) {
			maxlen = nums[i] - x;
			
		}
		x = nums[i];
	}
	return maxlen;
}

int maximumGap(vector<int>& nums) {				//数组
	if (nums.size() < 2)return 0;

	int max_num = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (max_num < nums[i])max_num = nums[i];
	}
	int* a;
	a = new int[max_num + 1];
	for (int i = 0; i < max_num + 1; i++) {
		a[i] = 0;
	}

	for (int i = 0; i < nums.size(); i++) {
		a[nums[i]]++;
	}

	bool flag = false;
	int max_len = 0, tmp_len;
	int x, y;
	for (int i = 0; i < max_num + 1; i++) {
		if (a[i] > 0) {
			if (flag == false) {
				flag = true;
				x = i;
			}
			else {
				tmp_len = i - x;
				if (tmp_len > max_len)max_len = tmp_len;
				x = i;
			}
		}
		
	}
	return max_len;
}

int main() {
	vector<int> s;
	int t;
	for (int i = 0; i < 4; i++) {
		cin >> t;
		s.push_back(t);
	}

	cout << maximumGap(s);
}