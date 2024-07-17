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
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;

        vector<int> del(1001, 0);
        for(auto x: to_delete) del[x] = 1;

        function<int(TreeNode*)> dfs=[&](TreeNode* it){

            if(it->left != nullptr){
                if(dfs(it->left)){
                    it->left = nullptr;
                }
            }

            if(it->right != nullptr){
                if(dfs(it->right)){
                    it->right = nullptr;
                }
            }

            if(del[it -> val]){
                if(it -> left != nullptr){
                    res.push_back(it->left);
                }
                if(it -> right != nullptr){
                    res.push_back(it->right);
                }
                return 1;
            }
            return 0;
        };

        TreeNode* it = root;

        if(!dfs(it)){
            res.push_back(root);
        }
        return res;
    }
};