#include<iostream>
#include<string>

using namespace std;

int myAtoi(string s) {
	int i = 0;
	bool f = true;
	int len = s.size();
	char p = s[i];
	while (s[i] == ' '&&i<len) {
		i++;
	}
	if (s[i] == '-') {
		f = false; 
		i++;
	}
	else if (s[i] == '+')i++;
	if (s[i] >= '0' && s[i] <= '9') {
		int res = 0;
		while (s[i] >= '0' && s[i] <= '9'&&i<len) {
			if (res > 214748364) {
				if (f == true)return 2147483647;
				else return -2147483648;
			}
			else if (res == 214748364) {
				if (f == true && s[i] >= '7')return 2147483647;
				else if (f == false && s[i] >= '8')return -2147483648;
			}
			
			res = res*10+(s[i]-'0');
			i++;
		}

		if (f == false)res = -res;
		
		return int(res);
	}
	else return 0;
}
int main() {
	cout << myAtoi("-2147483649");
}