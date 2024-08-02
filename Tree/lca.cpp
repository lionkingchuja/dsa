#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* lowestcommonancestor(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL or root==p or root==q){
        return root;
    }
    TreeNode* left=lowestcommonancestor(root->left,p,q);
    TreeNode* right=lowestcommonancestor(root->right,p,q);

    //result
    if(left==NULL){
        return right;
    }
    else if(right==NULL){
        return left;
    }
    else{//both left and right are not null, we found our result
        return root;
    }
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    
    TreeNode* p = root->left->left; // Node 4
    TreeNode* q = root->left->right; // Node 5

    TreeNode* lca = lowestcommonancestor(root, p, q);
    if (lca != NULL) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
}