/****************************************************
TC: O(N) : (N: number of elements)
SC: O(1)
Method: Simple - 3 pointer method
*****************************************************/

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *p1, *p2, *p3;
	p1 = NULL;
	p2 = head;
	while(p2 != NULL) {
		p3 = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p3;
	}
  return p1;
}
