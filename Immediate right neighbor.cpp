/*

Given a binary tree with parent link, find a node's immediate right neighbor without the root node.


*/

/*

solution: first find the lowest parent that both the node and its immediate neighbor have. Then
recursively find its immediate neighbor in the parent's left subtree.
O(h) time, O(1) space, h is the height of the node.
*/

#include<iostream>
using namespace std;


struct Node {
  int val;
  Node *left;
  Node *right;
  Node *parent;
  
  Node(int v) : val(v), left(NULL), right(NULL), parent(NULL) {}
};


Node *findNeighbor( Node *node, int level ){

    if( node == NULL ) return NULL;
    if( level == 0 )  return node;

    Node *left = findNeighbor(node->left,level+1);
    if( left )  { //always return left child at first such that this node is the immediate right neighbor
		return left;
	} else  {  
		return findNeighbor(node->right,level+1);
	}
} 

Node* rightNeighbor(Node *node ){

    Node *parent = node->parent;

    int level = 0; //records the level of node in order to find the same level neighbor

    while(parent){

        while( parent && parent->left != node ){ //find the lowest parent for node and the its immediate right neighbor
            node = parent;
            parent = node->parent;
            level--;
        }
        if( parent == NULL )
            return NULL;

        Node *local = findNeighbor( parent->right, level); //find the neighbor node with level 0

        if(local) {
            return local;
		} else{
            node = parent;
            parent = node->parent;
            level--;
        }
    }
    return NULL;        
}

int main(){

    Node *root = new Node(0);
    root->left = new Node(1);
    root->left->parent = root;
    root->right = new Node(2);
    root->right->parent = root;
    root->left->left = new Node(3);
    root->left->left->parent = root->left;
    root->left->right = new Node(4);
    root->left->right->parent = root->left;
    root->right->right = new Node(5);
    root->right->right->parent = root->right;
    Node *p1 = root->left->left; //3
    Node *p2 = root->left->right; //4
    cout<<rightNeighbor(p1)->val<<endl;
    cout<<rightNeighbor(p2)->val<<endl;
    return 0;
}
