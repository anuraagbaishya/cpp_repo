//WARNING: Lot of recursion ahead.
#include<iostream>
#include<stdio.h>
using namespace std;
class TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    public:
    int ar[20],i;
    TreeNode(){
        val=-1000;
        left=NULL;
        right=NULL;
    }
    TreeNode(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
    TreeNode *create(int inorder[10], int postorder[10], int ist, int ied, int ped) {//create tree from postorder and inorder traversal
            if(ist>ied)
                return NULL;
            TreeNode *res=new TreeNode(postorder[ped]);
            int mid;
            for (int i=ist;i<=ied;i++){
                if (inorder[i]==res->val){mid = i;break;}
            }
            res->right = create(inorder,postorder,mid+1,ied,ped-1);
            res->left = create(inorder,postorder,ist,mid-1, ped-1-ied+mid);
            return res;
    }
    void printLevelOrder(TreeNode* root)//print level order
    {
        int h = height(root);
        int i;
        for(i=1; i<=h; i++)
        printGivenLevel(root, i);
    }
    void printGivenLevel(TreeNode* root, int level)//recursive level printing
    {
        if(root == NULL)
        return;
        if(level == 1)
        printf("%d ", root->val);
        else if (level > 1)
        {
            printGivenLevel(root->left, level-1);
            printGivenLevel(root->right, level-1);
        }
    }
    int height(TreeNode* node)//height of tree
    {
        if (node==NULL)
            return 0;
        else
        {
         /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);

         /* use the larger one */
            if (lheight > rheight)
                return(lheight+1);
            else return(rheight+1);
        }
    }
    void inorder(TreeNode* root)//recursive inorder traversal
    {
        if(root != NULL)
        {
            inorder(root->left);
            ar[i]=root->val;
            i++;
            inorder(root->right);
        }

    }

};
int main()
{
    int inorder[]={2,4,6,5,1,3,8,9,7};
    int postorder[]={6,5,4,2,9,8,7,3,1};
    TreeNode *tree=new TreeNode;
    tree=tree->create(inorder,postorder,0,8,8);
    tree->printLevelOrder(tree);
    cout<<endl;
    tree->inorder(tree);
    int flag=0;
    for(int j=0;j<tree->i-1;j++)
    {
        if(tree->ar[j]>tree->ar[j+1])
        {
            cout<<"Tree is not a BST";
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"Tree is BST";
    return 0;
}
// unsigned int getLeafCount(struct node* node)
// {
//   if(node == NULL)
//     return 0;
//   if(node->left == NULL && node->right==NULL)
//     return 1;
//   else
//     return getLeafCount(node->left)+
//            getLeafCount(node->right);
// }
// bool printAncestors(struct node *root, int target)
// {
//  /* base cases */
//  if (root == NULL)
//     return false;
//
//  if (root->data == target)
//     return true;
//
//  /* If target is present in either left or right subtree of this node,
//     then print this node */
//  if ( printAncestors(root->left, target) ||
//       printAncestors(root->right, target) )
//  {
//    cout << root->data << " ";
//    return true;
//  }
//
//  /* Else return false */
//  return false;
// }
