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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<pair<int, int>> par(100000 + 10);
        vector<int> depth(100000 + 10);

        fill(par.begin(), par.end(), make_pair(-1, -1));
        fill(depth.begin(), depth.end(), 0);
        
        function<void(TreeNode*)> dfs = [&] (TreeNode* it){
            if(it -> left != nullptr){
                par[it->left->val].first = it->val;
                par[it->left->val].second = 0;
                depth[it->left->val] = depth[it->val] + 1;
                dfs(it->left);
            }
            if(it -> right != nullptr){
                par[it->right->val].first = it->val;
                par[it->right->val].second = 1;
                depth[it->right->val] = depth[it->val] + 1;
                dfs(it->right);
            }
        };  

        TreeNode* it = root;

        dfs(it);

        deque<char> d1, d2;
        
        while(startValue != destValue){

            if(depth[startValue] > depth[destValue]){
                startValue = par[startValue].first;
                d1.push_back('U');
            }else{
                if(par[destValue].second == 0){
                    d2.push_front('L');
                }else{
                    d2.push_front('R');
                }
                destValue = par[destValue].first;
            }
        }
        string res;
        while(!d1.empty()){
            res.push_back(d1.front());
            d1.pop_front();
        }
        while(!d2.empty()){
            res.push_back(d2.front());
            d2.pop_front();
        }
        return res;
    }
};