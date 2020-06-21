/****************************************************
TC: O(n) : (n : length of the linked list)
SC: O(1)
Method:
	1. Two Pointer Method
	2. Move the second pointer by k positions
	3. Move both pointers simultaneously until second->next pointer becomes null
	4. first pointer now points to the node to be removed
	5. special case if first pointer points to the first node
*****************************************************/

#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
  int i = 0;
	LinkedList *first = head, *second = head;
	while(i != k) {
		second = second->next;
		i++;
	}
	if(second != NULL) {
		while(second->next != NULL) {
			first = first->next;
			second = second->next;
		}
		first->next = first->next->next;
	} else {
		head->value = head->next->value;
		head->next = head->next->next;
	}
}
