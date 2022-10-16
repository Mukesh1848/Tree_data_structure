class Solution {
    private:
         // left part traveresal 
    void traverseLeft(Node* root , vector<int>&ans){
        
        if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return ;
        }
        
        ans.push_back(root->data);
        
        if(root->left){
            traverseLeft(root->left , ans);
        }else{
            traverseLeft(root->right, ans);
        }
    }
    
    // leaf node traverseal
    void traverseLeaf(Node* root , vector<int>&ans){
        
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return ;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right ,ans);
        
    }
    
    // right part traversal 
    void traverseRight(Node* root , vector<int>&ans){
        
         if((root==NULL) || (root->left==NULL && root->right==NULL)){
            return ;
        }
        
        if(root->right){
            traverseRight(root->right , ans);
        }else{
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        
        vector<int>ans;
        
        if(root==NULL){
            return ans;
        }
        
         ans.push_back(root->data);
         
        // trverse left part of tree without contains leaf nodes 
         
         traverseLeft(root->left, ans);
         
         // traverse leaf node of tree
         
         traverseLeaf(root->left, ans);
         traverseLeaf(root->right, ans);
         
         // traverse right part of the tree
         
         traverseRight(root->right,ans);
         
         // return ans;
         return ans;
    }
};
