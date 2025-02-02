#include <iostream>
using namespace std;
#include<queue>

class binarysearch {
public:
    int data ;
    binarysearch *left; 
    binarysearch *right;
    
    binarysearch(int d) {
        this->data = d;
        this->right = right;
        this->left = left;
    }
};
//from scratch i.e from the root
binarysearch *buildtree(binarysearch *root) {
        cout<<"enter the data  : "<<endl;
        int data;
        cin>>data;
        root = new binarysearch(data);
        
        if(data == -1) {
            return NULL;
        }
        cout<<"enter the data for inserting in left of  "<<data<<" - "<<endl;
        root->left = buildtree(root->left) ; 
        
        cout<<"enter the data for inserting in right of "<<data<<" - "<<endl;
        root->right = buildtree(root->right) ;
        
        return root;
}
//levelwise traversal from left->right
void levelwisetraversal(binarysearch *root) {
    queue<binarysearch *>q;    //FIFO order 
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        binarysearch *temp = q.front();
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
void inordertraversal(binarysearch *root) {
    if(root==NULL) {
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);
}
void preordertraversal(binarysearch *root) {
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void postordertraversal(binarysearch *root) {
    if(root==NULL){
        return ;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

int main() {
    binarysearch *root = NULL;
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
    
}


