#include <iostream>
#include <vector>
#include <queue>
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
// In_order_Traversal : left, root then left
vector<vector<int>> levelOrderTraversal(Node *node)
{
    vector<vector<int>> ans;
    if (node == NULL)
    {
        return ans;
    }
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            level.push_back(node->data);
        }
        ans.push_back(level);
    }
    return ans;
};
int main()
{
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
    vector<vector<int>> res;
    vector<vector<int>>::iterator it;

    // level order traversal
    res = levelOrderTraversal(root);
    cout<<"Result: "<<endl;
    for (const auto&level:res) //const: This keyword makes level a constant reference, auto tells to automatically deduce the type of level, & indicated that level is refernce to the actual elements in the container, avoids copying
    {
        for(int x: level){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}