/****************************************************
TC: O(D) : D is the depth of the lowest descendant
SC: O(1)
Method:
	1. Find the Depth of both the descendants
	2. Bring both the descendants to the same level
	3. Move up until the ancestors become the same
*****************************************************/

#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = NULL;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {
  int d1 = 0, d2 = 0;
	AncestralTree *t1, *t2;
	t1 = descendantOne;
	t2 = descendantTwo;
	while(t1 != NULL) {
		d1++;
		t1 = t1->ancestor;
	}
	while(t2 != NULL) {
		d2++;
		t2 = t2->ancestor;
	}
	t1 = descendantOne;
	t2 = descendantTwo;
	int diff;
	if(d1 > d2) {
		diff = d1 - d2;
		while(diff > 0) {
			t1 = t1->ancestor;
			diff--;
		}
	} else if(d1 < d2) {
		diff = d2 - d1;
		while(diff > 0) {
			t2 = t2->ancestor;
			diff--;
		}
	}
	while(t1 != t2) {
		t1 = t1->ancestor;
		t2 = t2->ancestor;
	}
  return t1;
}
