#include<iostream>
#include<stack>

using namespace std;

int reverse(int x) {
	bool f = true;
	if (x == -2147483648)return 0;
	if (x < 0) {
		f = false;
		x = -x;
	}
	int a = 0;
	while (x > 0) {

		if (a > 214748364)return 0;
		a = a * 10 + x % 10;
		x /= 10;
	}
	if (f == true)
		return a;
	else return -a;
}
int main() {
	int a;
	cin >> a;
	cout << reverse(a);
}
