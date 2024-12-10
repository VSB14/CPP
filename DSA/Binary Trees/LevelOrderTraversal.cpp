#include <iostream>
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
// pre_order_Traversal : root, left, then left
vector<vector<int>> level_order_Traversal(Node *node)
{
    vector<vector<int>> res;
    vector<int> level;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            struct Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            level.push_back(curr->data);
        }
        res.push_back(level);
    }
    return res;
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
    vector<vector<int>> ans;
    // In-order traversal
    ans = level_order_Traversal(root);
    for (const auto &level : ans)
    {
        for (auto x : level)
        {
            cout << x<<" ";
        }
        cout << endl;
    }
    return 0;
}