#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    struct Node* left;
    struct Node* right;
    Node(int data){
        val = data;
        left = right = nullptr;
    }  
};

void levelOrderTraversal(Node* root){
    
}   

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    levelOrderTraversal(root);
    return 0;
}