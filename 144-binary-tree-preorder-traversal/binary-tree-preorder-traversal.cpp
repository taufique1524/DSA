class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        if(root==NULL) return ans;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->right!=NULL){
                st.push(node->right);
            }
            if(node->left!=NULL){
                st.push(node->left);
            }
        }
        return ans;
    }
};