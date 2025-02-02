#include <iostream>
using namespace std;
#include<queue>

class binarytree {
public:
    int data ;
    binarytree *left; 
    binarytree *right;
    
    binarytree(int d) {
        this->data = d;
        this->right = right;
        this->left = left;
    }
};
//from scratch i.e from the root
binarytree *buildtree(binarytree *root) {
        cout<<"enter the data  : "<<endl;
        int data;
        cin>>data;
        root = new binarytree(data);
        
        if(data == -1) {
            return NULL;
        }
        cout<<"enter the data for inserting in left of  "<<data<<" - "<<endl;
        root->left = buildtree(root->left) ; 
        
        cout<<"enter the data for inserting in right of "<<data<<" - "<<endl;
        root->right = buildtree(root->right) ;
        
        return root;
}
//levelwise traversal from left->right using recursion
void levelwisetraversal(binarytree *root) {
    queue<binarytree *>q;    //FIFO order 
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        binarytree *temp = q.front();
        q.pop();
        if(temp==NULL) {  //means the whole level has been traversed
            cout<<endl; //shift to new line
            
            if(!q.empty()){    //has some children left means at the end null of parent level
                q.push(NULL);
            }
        }else {
            cout << temp -> data<<" ";
            if(temp ->left) {
                q.push(temp ->left);
            }
            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}
void inordertraversal(binarytree *root) {
    if(root==NULL) {   //follows LNR
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
void preordertraversal(binarytree *root) {
    if(root==NULL){           //follows NLR
        return ;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(binarytree *root) {
    if(root==NULL){    //follows LRN
        return ;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
/*
    1 
   3 5 
  7 11 17  - into tree without recursion
*/ 
void buildlevelordertree(binarytree *&root) {
    queue<binarytree*>q;
    cout<<"Enter the data for root node - "<<endl;
    int data;
    cin>>data;
    root = new binarytree(data);
    q.push(root);
    while(!q.empty()) {
        binarytree *temp = q.front();
        q.pop();
        cout<<"enter the data for left node of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata != -1) {
            temp->left = new binarytree(leftdata);
            q.push(temp->left);
        }
        cout<<"enter the data for right node of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata != -1) {
            temp->right = new binarytree(rightdata);
            q.push(temp->right);
        }
    }
}

int main() {
    binarytree *root = NULL;
    buildlevelordertree(root);
    
    /*
    //create a node
    root = buildtree(root);
    
    cout<<"Printing the level wise traversal output - "<<endl;
    levelwisetraversal(root); 
    
    cout<<"The inorder traversal - "<<endl;
    inordertraversal(root);
    cout<<endl;
    
    cout<<"The preorder traversal - "<<endl;
    preordertraversal(root);
    cout<<endl;
    
    cout<<"The postorder traversal - "<<endl;
    postordertraversal(root);
    cout<<endl;
    */
    
}
