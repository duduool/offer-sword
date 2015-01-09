#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int value;
	struct ListNode *next;
}ListNode;

void print_list_reversingly(ListNode *pHead)
{
	if (pHead != NULL) {
		if (pHead->next != NULL) {
			print_list_reversingly(pHead->next);
		}

		printf("%d ", pHead->value);
	}
}

void print_list(ListNode *pHead)
{
	ListNode *pNode = pHead;

	while (pNode != NULL) {
		printf("%d ", pNode->value);
		pNode = pNode->next;
	}
}

void add_tail(ListNode **pHead, int value)
{
	ListNode *pNew = (ListNode *)malloc(sizeof(ListNode));
	pNew->value = value;
	pNew->next = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	} else {
		ListNode *pNode = *pHead;

		while (pNode->next != NULL)
			pNode = pNode->next;

		pNode->next = pNew;
	}

}

void add_head(ListNode **pHead, int value)
{
	ListNode *pNew = (ListNode *)malloc(sizeof(ListNode));
	pNew->value = value;
	pNew->next = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	} else {
		pNew->next = *pHead;
		*pHead = pNew;
	}
}

void add(ListNode **pHead, int *value, int n, void (*fp)(ListNode **, int))
{
	int i = 0;

	for (i = 0; i < n; i++) {
		fp(pHead, value[i]);
	}
}

void reverse(ListNode **pHead)
{
	if (*pHead != NULL) {
		ListNode *pNode = (*pHead)->next, *pTemp;
		(*pHead)->next = NULL;

		while (pNode != NULL) {
			pTemp = pNode->next;
			pNode->next = *pHead;
			*pHead = pNode;
			pNode = pTemp;
		}
	}
}

void delete(ListNode **pHead)
{
	ListNode *pNode = *pHead;

	while (pNode != NULL) {
		pNode = pNode->next;
		free(*pHead);
		*pHead = pNode;
	}
}

int main(int argc, const char *argv[])
{
	ListNode* pHead = NULL;
	int value[] = {1, 2, 3, 4, 5};

	add(&pHead, value, 5, add_head);
	print_list(pHead);
	printf("\n");
	
	delete(&pHead);

	add(&pHead, value, 5, add_tail);
	print_list(pHead);
	printf("\n");
	
	reverse(&pHead);
	print_list(pHead);
	printf("\n");

	//print_list_reversingly(pHead);
	//printf("\n");

	return 0;
}
