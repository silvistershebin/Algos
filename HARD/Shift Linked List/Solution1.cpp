/****************************************************
TC: O(N)
SC: O(1)
Method: 
	1. Find length of the linked list
	2. Find offset (k can be negative - set offset accordingly)
	3. Detach the offset part and attach to the beginning of the linked list
*****************************************************/

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
	int length = 0;
	LinkedList *temp = head;
	while(temp->next != NULL) {
		length++;
		temp = temp->next;
	}
	length++;
	int offset = abs(k) % length;
	if(offset == 0)
		return head;
	temp->next = head;
	LinkedList *ptr1;
	ptr1 = head;
	int t2 = k > 0 ? length - offset : offset;
	while(t2 > 1) {
		t2--;
		ptr1 = ptr1->next;
	}
	head = ptr1->next;
	ptr1->next = NULL;
  return head;
}
