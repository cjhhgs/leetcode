#include<iostream>
#include<vector>

using namespace std;
bool isPalindrome(int x) {
	vector<int> vec;
	
	if (x < 0)return false;
	int a = x;
	while (a > 0) {
		vec.push_back(a % 10);
		a /= 10;
	}
	int len = vec.size();
	for (int i = 0; i < len / 2; i++) {
		if (vec[i] != vec[len -1- i]) {
			return false;
		}
	}
	return true;
}