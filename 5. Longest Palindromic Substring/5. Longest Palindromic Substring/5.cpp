#include<iostream>
#include<string>
#include<vector>

using namespace std;

//DP solution
string longestPalindrome(string s) {
	int n = s.size();
	vector<vector<bool>> p(n, vector<bool>(n,false));
	int x=0, y=0, maxlen;
	maxlen = -1;
	
	for (int j = 0; j < n; j++) {
		for (int i = j; i >=0; i--) {
			if (i == j) {
				p[i][j] = true;
			}
			else {
				if ((j == i + 1) && s[i] == s[j])
					p[i][j] = true;
				if (j>i+1&&p[i + 1][j - 1] == true && s[i] == s[j]) {
					p[i][j] = true;
				}
				
			}

			if (p[i][j]&&j - i > maxlen) {
				maxlen = j - i;
				x = i, y = j;
			}
		}
	}
	string res;
	for (int i = x; i <= y; i++) {
		res.push_back(s[i]);
	}
	
	return res;
}
int main() {
	string s;
	cin >> s;
	cout << longestPalindrome(s);
}