#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int n = A.size();
	int result = 0;

	unordered_map<int, int> ab;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ab[A[i] + B[j]]++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(ab[-(C[i] + D[j])])
			result += ab[-(C[i] + D[j])];
		}
	}


	return result;
}
int main() {

}