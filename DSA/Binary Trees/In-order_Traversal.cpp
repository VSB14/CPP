#include <iostream>

using namespace std;

struct Node
{
    int data;
     Node *left;
     Node *right;
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};
//In_order_Traversal : left, root then left
void In_order_Traversal(Node *node){
    if(node == NULL){
        return;
    }
    In_order_Traversal(node->left);
    cout<<node->data<<endl;
    In_order_Traversal(node->right);
    
};
int main(){
    struct Node *root = new Node(1);
     root->left = new Node(2);
     root->right = new Node(3);
     root->left->left = new Node(4);
     root->left->right = new Node(5);
     root->right->left = new Node(7);
     root->right->right = new Node(8);
     root->right->right->left = new Node(9);
     root->right->right->right = new Node(10);
     root->left->right->left = new Node(6);

    //In-order traversal
    In_order_Traversal(root);
    return 0;

}