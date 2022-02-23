#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* head = new ListNode;
	ListNode* p=head, * q;
	int i, j, sum,carry=0;
	while (l1 != NULL || l2 != NULL) {
		if (l1 == NULL) { i = 0; }
		else { i = l1->val; l1 = l1->next; }

		if (l2 == NULL) { j = 0; }
		else { j = l2->val; l2 = l2->next; }
		
		sum = i+j+carry;
		carry = sum / 10;
		sum = sum % 10;

		q = new ListNode(sum);
		p->next = q; p = q;
	}
	if (carry>0) {
		q = new ListNode(carry);
		p->next = q;
	}

	p = head->next;
	delete head;
	return p;
}

/*
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	long i, j,sum;
	sum = 0; i = 1;
	while (l1 != NULL) {
		sum += l1->val * i;
		i*=10;
		l1 = l1->next;
	}

	i = 1;
	while (l2 != NULL) {
		sum += l2->val * i;
		i *= 10;
		l2 = l2->next;
	}

	if (sum == 0) {
		ListNode* head = new ListNode(0);
		return head;
	}

	ListNode* head = new ListNode;
	ListNode* p = head,*q;
	while (sum > 0) {
		j = sum % 10;
		q = new ListNode(j);
		p->next = q;
		p = q;
		sum /= 10;
	}

	p = head->next;
	delete head;
	return p;
}
*/
int main() {

}