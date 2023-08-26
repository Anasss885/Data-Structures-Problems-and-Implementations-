/*
Solution Idea:
1-you have to know that all nodes with small values are stored in the left subtree.
2-what if we traverse through all nodes in the left subtree , aren't we must get the node with small value??
3-well, you know that once we insert a node with a smaller value it will be stored towards left subtree then towrds the left in the following subtree
if it's smaller than its root and so on.
4- now you may recognized that our goal is to reach the leaf node of the left sub-tree in our BST Tree , this is exactly what we will do in the following c++ code.
*/



#include<iostream>
#include <algorithm> 
#include <vector>
#include<string>
#include <set> 
#include <map> 
#include <cstdlib>
#include <utility>
#include <ctime>
#include <cmath>
#include <stack>
using namespace std;
#define ANOOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f


/*
Scratching a Binary Search Tree BST->node->BST class with all of its operations
(insert , update , delete)
*/
class node {
public:
    int data;
    node* left;
    node* right;
    node(int value) {
        data = value;
        left = right = NULL;
    }
};

class BST {
public:
    node* root;
    BST()
    {
        root = NULL;
    }
    
    node* insert(node*rn,int value) {
        if (rn == NULL) { // building the tree from scratch
            node* new_node = new node(value);
            rn = new_node;
        }
        else if (rn->data >= value) {
            rn->left = insert(rn->left, value);
        }
        else rn->right = insert(rn->right, value);
        return rn;
    }
    void insert(int value) { //overolaing function to be more readable and usable than the origingal insert function , trace it 
        root = insert(root, value);
    }

     node * find_min(node * r) {
            if (r == NULL)return NULL; // in case there's no tree
            else if (r->left == NULL)return r; // base case of finding our value 
            else return find_min(r->left); // the recursive case 
        }
};

int main() {
    ANOOS
    BST tree;
    node* r;
    tree.insert(2);
    tree.insert(-2);
    tree.insert(156);
    tree.insert(150);
    tree.insert(-62);
    tree.insert(690);
    tree.insert(132);
    tree.insert(-42);
    tree.insert(99);
    r = tree.find_min(tree.root);
    cout << r->data; // it supposed to output -62 , try it if you want 

    return 0;
}

    
