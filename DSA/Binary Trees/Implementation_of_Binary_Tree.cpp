#include <iostream>

using namespace std;

//defining the structure of a single structure called Node
struct Node
{
    int data;
     Node *left; //Node named left, self refering structing
     Node *right;//Node named right, self refering structing
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }
};

int main(){
    struct Node *root = new Node(1); //initialization of root node by calling the Node constructor of structure Node.
     root->left = new Node(2);
     root->right = new Node(3);
    return 0;

}