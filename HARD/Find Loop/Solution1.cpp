/****************************************************
TC: O(N)
SC: O(1)
Method: Find Mathematical Relation 
	1. Use 2 Pointer method (F: move one element; S: move 2 elements)
	e.g:
		0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6
							^   	  |
							9 <- 8 <- 7
		Here, the two pointers will meet at 6.
		Let 0 to 4 be 'D'.
		Let 4 to 6 be 'P'.
		F Travels (D + P)
		Thus, S travels (2D + 2P)
		Let 6 to 4 be 'R'
		Also, S has travelled (D + P + R + P)
		i.e (2D + 2P) = (D + P + R + P)
		***************** Thus, D = R *****************
		Initialize F to head and move F and S one step till they meet which is the node where loop originates
	
	Can also be done with hash table but will take O(n) space.
*****************************************************/

#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  LinkedList *first, *second;
	first = head;
	second = head;
	do {
		first = first->next;
		second = second->next->next;
	} while(first != second);
	first = head;
	while(first != second) {
		first = first->next;
		second = second->next;
	}
  return first;
}
