/*
A height balanced binary tree is a binary tree in which the height of the left subtree 
and right subtree of any node does not differ by more than 1 and both the left and right subtree are also height balanced.
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

int height(node* r) { // height of the tree is max num of edges to reach the leaf node
    if (!r) return 0; // no node so no edge presented 
    else return 1 + max(height(r->left), height(r->right)); 
}

bool isBalanced(node* r) {
    if (!r)return true; //(Base case) empty tree is Balanced , i.e : have 0 nodes left and right so Balanced

    int lh, rh;
    lh = height(r->left);
    rh = height(r->right);

    if (abs(lh - rh) <= 1 && isBalanced(r->left) && isBalanced(r->right)) return true;
    else return false;

}

int main() {
    ANOOS
        node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(8);
    if (isBalanced(root))cout << "Balanced Elhmdullah\n";
    else cout << "Not Balanced y3mmm \n";




    return 0;
}
