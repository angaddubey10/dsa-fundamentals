#include<bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int data;
    vector<TreeNode*> children;
    TreeNode(int val){
        this->data = val;
    }
};
    
TreeNode * createTree(vector<vector<int>> nodeList){
    TreeNode *root = new TreeNode(nodeList[0][1]);
    queue<TreeNode*> q;
    int n = nodeList.size();
    TreeNode *node, *newNode;
    q.push(root);
    int i=1; 
    while(i<n){
        node = q.front();
        q.pop();
        while(i<n && node->data == nodeList[i][0]){
            newNode = new TreeNode(nodeList[i][1]);
            node->children.push_back(newNode);
            q.push(newNode);
            i++;
        }
    }
    cout<<"\nTree Generation Successful\n";
    return root;
}

void levelOrder(TreeNode *root){
    queue<TreeNode*>q;
    q.push(root);
    TreeNode *node;
    while (!q.empty()){
       node = q.front();
       q.pop();
       cout<<node->data<<" ,";
       for(int i=0; i<node->children.size(); i++){
            q.push(node->children[i]);
       }
    }
    
}

int main(){
    cout<<"\n\n***************************************************\nHello World!"<<endl;
    vector<vector<int>> nodeList = {{-1,5}, {5,4}, {5,15}, {5,150}, {5,40}, {4,12}, {15, 1}, {15, 3}};
    TreeNode *root = createTree(nodeList);
    cout<<"\nPrinting Tree: Level Order\n";
    levelOrder(root);
    // cout<<"\nPrinting Tree: PreOrder\n";
    // preOrder(root);
    cout<<endl<<endl<<endl;
    return 0;
}  

