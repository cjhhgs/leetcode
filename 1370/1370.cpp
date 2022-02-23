#include<iostream>
#include<string>
#include<queue>

using namespace std;

string sortString_better(string s) {
	string result;
	int ch[26] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		ch[s[i] - 'a']++;
	}
	char c;
	bool direct = false;
	bool flag = true;
	while (flag) {
		flag = false;
		if (direct == false) {

			for (int i = 0; i < 26; i++) {
				if (ch[i] > 0) {
					c = 'a' + i;
					result.push_back(c);
					flag = true;
					ch[i]--;
				}
			}

			direct = true;
		}

		else {
			for (int i = 25; i >= 0; i--) {
				if (ch[i] > 0) {
					c = 'a' + i;
					result.push_back(c);
					flag = true;
					ch[i]--;
				}
			}

			direct = false;
		}
	}

	return result;

}

string sortString_my(string s) {
	string result;
	struct node {
		char data;
		node* next;
		node(char c='\0') :next(NULL),data(c) {};
	};

	int ch[128] = { 0 };	//��¼���ַ�����

	node* head,*p,*q;
	head = new node;
	q = head;

	for (int i = 0; i < s.size(); i++) {	//Դ�ַ�����������
		ch[s[i]]++;
		p = new node(s[i]);
		q->next = p;
		q = p;
	}

	bool direct = false;	//�����־
	char t;	
	while (head->next != NULL) {	//Դ�ַ���û�б����
	
		if (direct == false) {	//��С��ʼ��
			
			node* pointer = head->next;

			int i = 0;
			bool flag = false;
			while (i < 128) {
				for (; i < 128; i++) {		//�ҵ���С��t
					if (ch[i] > 0) {	
						char c = i;
						t = c;
						result.push_back(c);
						ch[i]--;
						i++;
						break;
					}
				}

				if (i > 127)break;
				//ɾ��t
				
				pointer = head;
				while (pointer->next != NULL) {
					if (pointer->next->data == t) {
						p = pointer->next;
						pointer->next = p->next;
						delete p;
						break;
					}
					else {
						pointer = pointer->next;
					}
				}

			}

			direct = true;
		}

		else {					//�Ӵ�ʼ��

			node* pointer = head->next;

			int i = 127;
			bool flag = false;
			while (i >= 0) {
				for (; i >= 0; i--) {		//�ҵ�����t
					if (ch[i] > 0) {
						char c = i;
						t = c;
						result.push_back(c);
						ch[i]--;
						i--;
						break;
					}
				}

				if (i == -1)break;
				//ɾ��t
				pointer = head;
				while (pointer->next != NULL) {
					if (pointer->next->data == t) {
						p = pointer->next;
						pointer->next = p->next;
						delete p;
						break;
					}
					else {
						pointer = pointer->next;
					}
				}	


			}

			direct = false;
		}
	}

	return result;
	
}

int main() {
	string s;
	cin >> s;
	cout << sortString_better(s);
}