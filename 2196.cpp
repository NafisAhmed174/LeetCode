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

const int N = 1e5 + 5;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        vector<pair<int, int>> Tree(N, {-1, -1});
        vector<bool> presentNode(N, 0), isRoot(N, 1);
        for(vector<int> e: descriptions){
            presentNode[e[0]] = presentNode[e[1]] = 1;
            isRoot[e[1]] = false;
            if(e[2] == 1){
                Tree[e[0]].first = e[1];
            }else{
                Tree[e[0]].second = e[1];
            }
        }
        int root = 0;

        for(int i = 1; i < N; i++){
            if(presentNode[i] && isRoot[i]){
                root = i;
                break;
            }
        }
        ;
        function<void(TreeNode*, int)> dfs = [&] (TreeNode* it, int vertex){
            it -> val = vertex;
            if(Tree[vertex].first != -1){
                it->left = new TreeNode();
                dfs(it->left, Tree[vertex].first);
            }
            if(Tree[vertex].second != -1){
                it->right = new TreeNode();
                dfs(it->right, Tree[vertex].second);
            }
        };
        TreeNode* BinTree = new TreeNode();
        dfs(BinTree, root);
        return BinTree;
    }
};