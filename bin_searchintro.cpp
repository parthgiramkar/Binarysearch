#include <iostream>
using namespace std;

class node {
public:
    int data ;
    node *left;
    node *right;
    
    node(int d) {
        this->data = d;
        this->right = right;
        this->left = left;
    }
};
//from scratch i.e from the root
node *buildtree(node *root) {
        cout<<"enter the data  : ";
        int data;
        cin>>data;
        root = new node(data);
        if(data == -1) {
            return NULL;
        }
        cout<<"enter the data for inserting in left of  "<<data<<" - "<<endl;
        root->left = buildtree(root->left) ; 
        
        cout<<"enter the data for inserting in right of "<<data<<" - "<<endl;
        root->right = buildtree(root->left) ;
        return root;
}
//levelwise traversal from left->right
node *

int main() {
    node *root = NULL;
    //create a node
    root = buildtree(root);
    cout<<" ";
    
}
