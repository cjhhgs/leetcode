#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(const int &x, const int &y) {
	return x>y;
}
/*
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	int len1 = nums1.size(), len2 = nums2.size();
	vector<int> result;
	vector<int> tmp1,tmp2;
	for (int i = 0; i < k; i++) {
		//nums1取i个数，nums2取k-i个数
		int begin=0;
		for (int j = 0; j < i; j++) {
			for (int a = begin; a < len1 - i; a++) {
				if (nums1[a] >= nums1[a + 1]) { tmp1[j] = nums1[a]; begin = a + 1; }
				else { tmp1[j] = nums1[a + 1]; begin = a + 2; }
			}
		}
	}

	return result;
}
*/
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
	int len1 = nums1.size(), len2 = nums2.size();
	vector<int> result;
	vector<vector<int>> s1, s2;
	
	//存入nums1中取i个序列存入s1[i]


	vector<int> tmp1, tmp2;
	for (int i = 0; i < k; i++) {
		//nums1取i个数，nums2取k-i个数
		int begin = 0;
		for (int j = 0; j < i; j++) {
			for (int a = begin; a < len1 - i; a++) {
				if (nums1[a] >= nums1[a + 1]) { tmp1[j] = nums1[a]; begin = a + 1; }
				else { tmp1[j] = nums1[a + 1]; begin = a + 2; }
			}
		}
	}

	return result;
}
int main() {
	vector<int>n1, n2;
	maxNumber(n1, n2, 3);
}