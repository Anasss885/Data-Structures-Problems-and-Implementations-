


/*
HIGHLY RECOMMENDED ADVICE: Before starting to deal with the probelm , think for 3-5 mins about inorder representaion and do it with a small BST sample 
and look at the resulted sequnce of numbers for a while , mostly you will get the problem idea 
*/







//----------------------------------------------------------------------------------------------------------------------------

/*
Solution Idea:
1- since that inorder represenation display the whole nodes in the BST as Left-Root-Right
2- therefore, if you do an inorder represenation to the and integers BST you will note a good obseravetion
3- the observation is the inorder represenation somehow sort your BST Ascendingly 
4- finally the striaght-forward solution is to sort the array to get the inorder represenation
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

bool check_inOrder(int arr []  , int n) {
    if (n == 0 || n == 1)return 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])return 0;
    }
    return 1;
}
int main() {
    ANOOS
        int arr[] = { 1,3,6,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (check_inOrder(arr, n))cout << "Yes , inorder";
    else cout << "No , Not inorder";

    return 0;
}

    
