/*
Problem:Given a binary search tree and a key. Check the given key exists in BST or not without recursion.
*/
//Sol:The Sol mainly is bool Traverse function 

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
        if (rn == NULL) {
            node* new_node = new node(value);
            rn = new_node;
        }
        else if (rn->data >= value) {
            rn->left = insert(rn->left, value);
        }
        else rn->right = insert(rn->right, value);
        return rn;
    }
    void insert(int value) {
        root = insert(root, value);
    }

    bool traverse(node* r, int key) { // First Version of Sol.
        if (!r) { return false; }
        else if (!r->left && !r->right)return r->data==key;
        else {
            while (true) {
                if (key < r->data)r = r->left;
                else if (key > r->data)r = r->right;
                else return true;
                if (!r->left && !r->right) return false;
            }
        }

    }


bool traverse(struct Node* root, int key) // Second Version of Sol.
{
    
    while (root != NULL) {
        
        if (key > root->data)
            root = root->right;
 
       
        else if (key < root->data)
            root = root->left;
        else
            return true; 
    }
    return false;
}
};


int main() {
    ANOOS
             BST tree;
         tree.insert(5);
         tree.insert(16);
         tree.insert(1);
         tree.insert(135);
         tree.insert(-9);
         if (tree.traverse(tree.root, 18))cout << "Found it \n";
         else cout << "Found Nothing , Sad!\n";

    
       
    

      

    return 0;
}
/*
SOLUTIONS DICSUSSION:
1- the first version of my sol simply, i traversed through my BST without using recursion through pointers to check over the value and return our result ,
but the huge negative point in this sol that i used many conditons to handle all cases , and this not good enough .
2- the second version deals with a same way of Solution but it more readable and clarified to be read.
*/
    


