class Solution
{
    public:
        vector<int> postorderTraversal(TreeNode *root)
        {
            vector<int> postorder;
            if (root == NULL) return postorder;
            
            stack<TreeNode*> st;
            TreeNode *curr = root;
            TreeNode *lastVisited = nullptr;
            
            while (!st.empty() || curr != NULL)
            {
                // Go to the leftmost node
                if (curr != NULL)
                {
                    st.push(curr);
                    curr = curr->left;
                }
                else
                {
                    TreeNode *topNode = st.top();
                    
                    // If right child exists and traversing node from left child, move right
                    if (topNode->right != NULL && lastVisited != topNode->right)
                    {
                        curr = topNode->right;
                    }
                    else
                    {
                        // Otherwise, process the node and move up the tree
                        postorder.push_back(topNode->val);
                        lastVisited = topNode;
                        st.pop();
                    }
                }
            }
            
            return postorder;
        }
};