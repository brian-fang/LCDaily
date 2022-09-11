#include "../Templates/TreeNode.hh"
#include <stdlib.h>

/*

Generates a binary tree of arbitrary size 
Runtime: O(1)

Runtime is directly propertional to # of times gen() is called: # of nodes in tree
(nr^n series is convergent for |r| < 1) 

*/


TreeNode* gen() {
	
	if(rand() % 4) return new TreeNode;
	
	return new TreeNode(0, nullptr, gen());
	
}


int main(int argc, char* argv[]) {

}