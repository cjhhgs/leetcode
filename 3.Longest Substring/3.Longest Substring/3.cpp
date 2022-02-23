#include<iostream>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {
	short* alphabet;
	alphabet = new short[128];				//字母表检查重复
	for (int k = 0; k < 128; k++)
		alphabet[k] = 0;

	int i = 0, left = 0;
	int len = 0, maxlen = 0;

	while (i < s.size()) {

		alphabet[s[i]]++;

		//遇到重复的情况
		if (alphabet[s[i]] > 1) {

			len = i - left;

			//判断长度大小
			if (i - left > maxlen) {
				maxlen = i - left;
			}

			//point left移动到左边重复字符处
			while (s[left] != s[i]) {
				left++;
			}
			left++;

			for (int k = 0; k < 128; k++) {
				alphabet[k] = 0;
			}
			for (int k = left; k <= i; k++) {
				alphabet[s[k]] = 1;
			}

			//取断开后当前字符串长度
			//point i后移一位
			i++;
			continue;
		}

		//成功读一个字符
		i++;
	}

	if ((i - left) > maxlen)
		maxlen = (i - left);

	return maxlen;

}
int main() {
	;
}