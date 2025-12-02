/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
int height(TreeNode* root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
void matrix(vector<vector<string>>& res, TreeNode* node, int r, int c, int ht){
    if(node==nullptr) return;
    res[r][c] = to_string(node->val);
    if(node->left){
        matrix(res, node->left, r+1, c-pow(2, ht-r-1), ht);
    }
    if(node->right){
        matrix(res, node->right, r+1, c+pow(2, ht-r-1), ht);
    }
}
public:
    vector<vector<string>> printTree(TreeNode* root) {
         
        int ht = height(root)-1;
        
        int n = pow(2, ht+1)-1, m = ht+1;
        vector<vector<string>> res(m, vector<string>(n, ""));

        matrix(res, root, 0, (n-1)/2, ht);
        return res;
    }
};