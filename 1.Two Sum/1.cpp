#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> cp = nums;
	vector<int> result;
	sort(cp.begin(), cp.end());
	int x = 0;
	int y = cp.size()-1;
	int sum;
	while (x != y) {
		sum = cp[x] + cp[y];
		if (sum == target) {

			break;
			result.push_back(x);
			result.push_back(y);
			return result;
		}
		else if (sum > target) {
			y--;
		}
		else x++;
	}

	int a = cp[x], b = cp[y];
	bool fx = false, fy = false;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == a&&fx==false) { 
			x = i;
			fx = true;
			continue;
		}
		else if (nums[i] == b&&fy==false) { 
			y = i; 
			fy = true;
			continue;
		}
		
	}
	if (x > y) {
		result.push_back(y);
		result.push_back(x);
	}
	else {
		result.push_back(x);
		result.push_back(y);
	}

	return result;
}

int main() {
	vector<int> s;
	int x;
	int tar;
	for (int i = 0; i < 3; i++) {
		cin >> x;
		s.push_back(x);
	}
	cin >> tar;
	vector<int> t = twoSum(s,tar);
	for (int i = 0; i < 2; i++)
		cout << t[i];

}