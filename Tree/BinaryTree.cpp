#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int val){
        this->data = val;
        left = right = nullptr;
    }
};
    
TreeNode * createTree(vector<vector<int>> nodeList){
    TreeNode *root = new TreeNode(nodeList[0][1]);
    queue<TreeNode*> q;
    int n = nodeList.size();
    TreeNode *node;
    q.push(root);
    int i=1; 
    while(i<n){
        node = q.front();
        q.pop();
        if(node->data == nodeList[i][0]){
            node->left = new TreeNode(nodeList[i][1]);
            q.push(node->left);
            i++;
            if(i<n && node->data == nodeList[i][0]){
                node->right = new TreeNode(nodeList[i][1]);
                q.push(node->right);
                i++; 
            }
        }
    }
    cout<<"Tree Generation Done";
    return root;
}

void inOrder(TreeNode *root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(TreeNode *root){
    if(root == nullptr) return;
    cout<<root->data<<" ";
    preOrder(root->left);    
    preOrder(root->right);
}

int main(){
    cout<<"\n\n***************************************************\nHello World!"<<endl;
    vector<vector<int>> nodeList = {{-1,5}, {5,4}, {5,15}, {4,12}, {15, 1}, {15, 3}};
    TreeNode *root = createTree(nodeList);
    cout<<"\nPrinting Tree: InOrder\n";
    inOrder(root);
    cout<<"\nPrinting Tree: PreOrder\n";
    preOrder(root);
    cout<<endl<<endl<<endl;
    return 0;
}  

