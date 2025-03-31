#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        val = data;
        left = right = nullptr;
    }
};

void Inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    Inorder(root->left);
    cout << root->val << " ";

    Inorder(root->right);
}

void Preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    Preorder(root->left);

    Preorder(root->right);
}

void Postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    // create a Tree with 4 nodes, 1,2,4,5
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    Postorder(root);

    return 0;
}