/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
 int postindex;
Node* build(int in[],int post[],int stindx,int endindx)
{
   
    if(stindx>endindx)
      return NULL;
       Node* treenode= new Node(post[postindex--]);
   //cout<<treenode->data<<" ";
   if(stindx==endindx)
      return treenode;
   int index=-1;
   for(int i=stindx;i<=endindx;i++)
   {
       if(in[i]==(treenode->data))
       {
           index=i;
           break;
       }
   }
   
   treenode->right= build(in,post,index+1,endindx);
   treenode->left=build(in,post,stindx,index-1);
   return treenode;
}
Node *buildTree(int in[], int post[], int n) {
     postindex=n-1;
   return build(in,post,0,n-1);
}
