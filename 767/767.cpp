#include<iostream>
#include<string>
#include<vector>

using namespace std;



string reorganizeString(string S) {
	short ch[27] = { 0 };
	for (int i = 0; i < S.size(); i++) {
		ch[S[i]-'a']++;
	}
	int count[27] = { 0 };
	char letter[27] = {0};
	int begin=0, end = 0;

	
	for (int i = 0; i < 26; i++) {
		if (ch[i] > 0) {
			count[end] = ch[i];
			letter[end] = 'a' + i;
			end++;
		}
	}
	
	//调整为最大堆
	for (int k = (end - 2) / 2; k >= 0; k--) {
		int i = k;
		int j = 2 * i + 1;
		int t_count = count[i];
		int t_letter = letter[i];
		while (j < end) {
			if (j - 1 < end && count[j] <= count[j + 1]) {
				j++;
			}
			if (count[i] < count[j]) {
				count[i] = count[j]; letter[i] = letter[j];
				i = j; j = 2 * i + 1;
			}
			else break;
		}
		count[i] = t_count; letter[i] = t_letter;
	}



	string result;
	//每次取堆顶
	while (end > begin+1) {
		if (count[0] > (S.size() + 1) / 2)return "";

		result.push_back(letter[0]);
		count[0]--;
		int tmp;
		if (count[1] >= count[2]) tmp = 1;
		else tmp = 2;
		result.push_back(letter[tmp]);
		count[tmp]--;
		

		//letter[tmp]下移
		int i = tmp;
		int t_count = count[i];
		int t_letter = letter[i];
		int j = 2*i+1;
		while (j < end) {
			if (j - 1 < end && count[j] <= count[j + 1]) {
				j++;
			}
			if (count[i] < count[j]) {
				count[i] = count[j]; letter[i] = letter[j];
				i = j; j = 2 * i + 1;
			}
			else break;
		}
		count[i] = t_count; letter[i] = t_letter;

		//堆顶下移
		i = 0;
		t_count = count[i];
		t_letter = letter[i];
		j = 2 * i + 1;
		while (j < end) {
			if (j + 1 < end && count[j] <= count[j + 1]) {
				j++;
			}
			if (count[i] < count[j]) {
				count[i] = count[j]; letter[i] = letter[j];
				i = j; j = 2 * i + 1;
			}
			else break;
		}
		count[i] = t_count; letter[i] = t_letter;
		
		//消去计数为0的
		while (count[end - 1] == 0) {
			end--;
		}

	}

	if (count[0] > 1)return "";
	else {
		result.push_back(letter[0]);
		return result;
	}

}

int main() {
	string S;
	cin >> S;
	cout << reorganizeString(S);
}
//wfndrin