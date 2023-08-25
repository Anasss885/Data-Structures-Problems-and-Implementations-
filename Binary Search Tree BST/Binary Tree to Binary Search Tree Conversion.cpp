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
/*
Solution Steps:
1-creation of the array by in-order traversal to store all elements of the tree
2- sort these elements by Quicksort
3-maintain your elements to obey BST properties in function arrayToBST then display them 
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
int count_tree_nodes(node* root) {
    if (root == NULL)return 0;
    return count_tree_nodes(root->left) + count_tree_nodes(root->right) + 1;
}
void store_in_order(node* root, int arr[], int* index) {
    if (root == NULL)return;
    store_in_order(root->left, arr, index);
    arr[*index] = root->data;
    (*index) += 1;
    store_in_order(root->right, arr, index);
}
// Following function is needed for library function qsort()
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
void array_to_BST(node* root, int arr[], int* index) {
    if (root == NULL)return;
    array_to_BST(root->left, arr, index);
    root->data = arr[*index];
    (*index) += 1;
    array_to_BST(root->right, arr, index);
}
void binaryTreeToBST(node* root) {
    int n = count_tree_nodes(root);
    int* arr = new int[n];
    int i = 0;
    store_in_order(root, arr, &i);
    // Sort the array using library function for quick sort
    qsort(arr, n, sizeof(arr[0]), compare);
    i = 0; // re-intialization as it filled already one time due to passing by refernce
    array_to_BST(root, arr, &i);

    delete [] arr; // memory deallocation 


}
void  print_in_order(node* root) {
    if (root == NULL)return; //Base case
    print_in_order(root->left);
    cout <<" "<< root->data;
    print_in_order(root->right);
    
}

int main() {
    ANOOS
        node* n;
    n = new node(10);
    n->left = new node(30);
    n->right = new node(15);
    n->left->left = new node(20);
    n->right->right = new node(5);
    // the all pervious inputs are binary tree that must be converted to BST
    binaryTreeToBST(n);
    print_in_order(n);

    
      

    return 0;
}

    
