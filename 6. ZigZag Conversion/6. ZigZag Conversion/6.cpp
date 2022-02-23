#include<iostream>
#include<string>
#include<vector>

using namespace std;

string convert(string s, int numRows) {
	vector<vector<char>> vec(numRows);
	int k=0,m=s.size();
	while (1) {
		for (int i = 0; i < numRows; i++) {
			if(k<m)
				vec[i].push_back(s[k++]);
			else break;
		}
		for (int i = numRows - 2; i > 0; i--) {
			if(k<m)
				vec[i].push_back(s[k++]);
			else break;
		}
		if (k >= m)break;
	}
	string r;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < vec[i].size(); j++)
			r.push_back(vec[i][j]);
	}
	return r;
}

int main() {
	string s="PAYPALISHIRING", r;
	int n = 3;
	r = convert(s, n);
}