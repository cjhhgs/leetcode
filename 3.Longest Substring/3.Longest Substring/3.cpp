#include<iostream>
#include<string>

using namespace std;

int lengthOfLongestSubstring(string s) {
	short* alphabet;
	alphabet = new short[128];				//��ĸ�����ظ�
	for (int k = 0; k < 128; k++)
		alphabet[k] = 0;

	int i = 0, left = 0;
	int len = 0, maxlen = 0;

	while (i < s.size()) {

		alphabet[s[i]]++;

		//�����ظ������
		if (alphabet[s[i]] > 1) {

			len = i - left;

			//�жϳ��ȴ�С
			if (i - left > maxlen) {
				maxlen = i - left;
			}

			//point left�ƶ�������ظ��ַ���
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

			//ȡ�Ͽ���ǰ�ַ�������
			//point i����һλ
			i++;
			continue;
		}

		//�ɹ���һ���ַ�
		i++;
	}

	if ((i - left) > maxlen)
		maxlen = (i - left);

	return maxlen;

}
int main() {
	;
}