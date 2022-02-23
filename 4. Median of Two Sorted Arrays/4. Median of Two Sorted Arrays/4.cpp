#include<iostream>
#include<string>
#include<vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int m = nums1.size();
	int n = nums2.size();

	int mid = (m + n - 1) / 2;
	bool flag = true;//ÆæÊý
	if ((m + n) % 2 == 0)flag = false;//Å¼Êý

	int pos;

	int pos1 = 0, pos2 = 0;
	for (int i = 0; i < mid; i++) {

		if (pos1 == m) {
			
			pos2++; continue;
		}
		if (pos2 == n) {
			pos1++; continue;
		}

		if (nums1[pos1] > nums2[pos2]) {
			pos2++;
		}
		else pos1++;
	}

	double result;

	if (pos1 == m) { result = (double)nums2[pos2]; pos2++; }
	else if (pos2 == n) { result = (double)nums1[pos1]; pos1++; }
	else if (nums1[pos1] < nums2[pos2]) { result = (double)nums1[pos1]; pos1++; }
	else {result = (double)nums2[pos2]; pos2++; }

	if (flag == true)return result;
	else {
		double tmp;
		if (pos1 == m) { tmp = (double)nums2[pos2]; pos2++; }
		else if (pos2 == n) { tmp = (double)nums1[pos1]; pos1++; }
		else if (nums1[pos1] < nums2[pos2]) { tmp = (double)nums1[pos1]; pos1++; }
		else { tmp = (double)nums2[pos2]; pos2++; }

		result = (result + tmp) / 2;
		return result;
	}

}