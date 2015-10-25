#include <iostream>
#include <stdio.h>
using namespace std;
class tree{
	int info;
	tree *right,*left;
public:
	tree(int i){
		info=i;
		right=NULL;
		left=NULL;
	}
	tree(){
        info=-1;
        left=NULL;
        right=NULL;
	}
	tree* create();
	tree* delete_item(int item, tree *root);
	tree* create_optree(char postfix[]);
	void preorder_it(tree*);
	void preorder(tree *);
	void postorder_it(tree*);
	void postorder(tree*);
	void inorder(tree*);
	void inorder_it(tree*);
	void levelorder(tree*);
};
tree* tree::create()
{
	int info;
	tree *temp;
	cout<<"Enter: ";
	cin>>info;
	if(info==-1)
		return NULL;
	temp=new tree(info);
	temp->right=create();
	temp->left=create();
	return temp;
};
void tree::inorder(tree *root)
{
	if(root==NULL)
		return;
	else
	{
		inorder(root->left);
			cout<<root->info<<" ";
		inorder(root->right);
	}
}
void tree::levelorder(tree *root)
{
	tree *q[20], *cur=new tree();
	int f=-1,r=-1;
	cur=root;
	q[++r]=cur;
	while(f<r)
	{
		cur=q[++f];
		cout<<cur->info<<" ";
		if(cur->left!=NULL)
			q[++r]=cur->left;
		if(cur->right!=NULL)
			q[++r]=cur->right;
	}
}
void tree::inorder_it(tree *root)
{
	tree *s[20];
	int a=-1;
	tree *r=root;
	for(;;)
	{
		while(r!=NULL)
        {
            s[++a]=r;
            r=r->left;
        }
		r=s[a--];
		if(r==NULL)
			break;
		cout<<r->info<<" ";
		r=r->right;
	}
}
void tree::preorder_it(tree *root)
{
	tree *s[20];
	int a=-1;
	tree *r=root;
	for(;;)
	{
		while(r!=NULL)
		{
			cout<<r->info<<" ";
			s[++a]=r;
			r=r->left;
		}
		r=s[a--];
		if(r==NULL)
			break;
		r=r->right;
	}
}
void tree::preorder(tree *root)
{
	if(root==NULL)
		return;
	cout<<root->info<<" ";
	preorder(root->left);
	preorder(root->right);
}
void tree::postorder_it(tree *root) {
  if (!root) return;
	tree *r=root;
	tree *s[20];
	int a=-1;
  s[++a]=r;
  tree *prev = NULL;
  while (a!=-1)
	{
    tree *curr = s[a];
    if (!prev || prev->left == curr || prev->right == curr)
		{
      if (curr->left)
        s[++a]=curr->left;
      else if (curr->right)
        s[++a]=(curr->right);
    }
		else if (curr->left == prev)
		{
      if (curr->right)
        s[++a]=(curr->right);
    }
		else
		{
      cout << curr->info << " ";
      a--;
    }
    prev = curr;
  }
}
void tree::postorder(tree *root)
{
		if(root==NULL)
			return;
		postorder(root->left);
		postorder(root->right);
		cout<<root->info<<" ";
}
int main()
{
	tree *root=new tree();
	root=root->create();
	cout<<"Level Order Iterative: ";
	root->levelorder(root);
	cout<<endl<<"Inorder Iterative: ";
	root->inorder(root);
	cout<<endl<<"Inorder Recursive: ";
	root->inorder_it(root);
	cout<<endl<<"Preorder Iterative: ";
	root->preorder_it(root);
	cout<<endl<<"Preorder Recursive: ";
	root->preorder(root);
	cout<<endl<<"Postorder Iterative: ";
	root->postorder_it(root);
	cout<<endl<<"Postorder Recursive: ";
	root->postorder(root);
}
