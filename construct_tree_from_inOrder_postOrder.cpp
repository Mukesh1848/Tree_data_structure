int findPosition(int in[] ,int n , int element ){

    for(int i=0; i<n ; i++){
            if(in[i] == element)
                return i;
           }
       return -1;
    }

    Node* solve(int in[] , int post[] , int &index ,int inOrderStart , int inOrderEnd , int n){

        // base case 
        if(index >= n || inOrderStart > inOrderEnd ){
            return NULL;
        }

        // create root element 
        int element = post[index--];
        Node* root = new Node(element);

        int position = findPosition(in ,n ,element); 
        // recursive call 
        root->right = solve(in , post , index , position +1 , inOrderEnd ,n);
        root->left = solve(in , post , index, inOrderStart , position-1,n);

        return root;
    }


Node *buildTree(int in[], int post[], int n) {
    
       int postOrderIndex =n-1;

       Node* ans = solve(in , post, postOrderIndex , 0 , n-1, n);

       return ans;
}
