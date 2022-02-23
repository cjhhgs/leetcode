#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int largestPerimeter(vector<int>& A) {
	sort(A.begin(), A.end());

	int n = A.size();
	int i;

	for (i = n - 1; i >= 2; i--) {
		if (A[i] < (A[i - 1] + A[i - 2]))
			return A[i] + A[i - 1] + A[i - 2];
	}
	return A[i] + A[i - 1] + A[i - 2];
}

int main() {

}