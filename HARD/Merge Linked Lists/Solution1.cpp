/****************************************************
TC: O(N) : (Total number of elements)
SC: O(1)
Method: (Iterative) 3 pointer method - adjust the pointer by comparing the value of the nodes
*****************************************************/

#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = NULL;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
	LinkedList *p1, *p2, *prev;
	p1 = headOne;
	p2 = headTwo;
	prev = NULL;
	while(p1 != NULL && p2 != NULL) {
		if(p1->value < p2->value) {
			prev = p1;
			p1 = p1->next;
		} else {
			if(prev != NULL)
				prev->next = p2;
			prev = p2;
			p2 = p2->next;
			prev->next = p1;
		}
	}
	if(p1 == NULL)
		prev->next = p2;
	else prev->next = p1;
	if(headOne->value < headTwo->value)
		return headOne;
	else return headTwo;
}
