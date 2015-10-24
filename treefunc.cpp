/*c function to delete an item from the tree*/
tree delete_item(int item, tree root)
{
	tree cur, parent , suc, q;
	if(root == NULL)
	{
		printf(“tree is empty”);
		return root;
	}
	/* traverse the tree until item found or not found*/
	parent=NULL;
	cur=root;
	while(cur!=NULL && item!=cur->info)
	{
		parent =cur;		/*keep track of parent node*/
		if(item<cur->info)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(cur==NULL)		
	{
		printf(“item not found”);
		return root;
	}
	/* item found and check for case 1*/

	if(cur->llink==NULL)	/*node to be deleted has empty left subtree. So get the address of right q=cur->rlink; subtree */
			

	else if(cur->rlink==NULL) /*node to be deleted has empty right subtree. So get the address of left q=cur->llink; subtree */
			

	/*case 2*/
	else
	{
		suc=cur->rlink;		/*get the address of the right node 				   of the node to be deleted*/
		while(suc->llink!=NULL)
			suc=suc->llink;	/*then move to the leftmost node 				   of the node visited in previous 				   step*/
		suc->llink=cur->llink;	/* attach left subtree of node to be 				   deleted to the left of the leftmost 			              node reached in previous step*/
	 	q=cur->rlink;		/*obtain address of the right 					   subtree of the node to be 					   deleted*/
	}
	if(parent ==NULL)	// if parent does not exist, return q as root*/
		return q;			  
	if(cur==parent->llink)	//* if root to be deleted is left of parent, connect left of parent to q*
					 
		parent->llink=q;		 
	else
		parent->rlink=q;		/*else connect right of parent to q*/

	free(cur);
return root;
}
/* C function to create a binary tree for postfix expression*/
NODEPTR create_tree( char postfix[])
{
	NODEPTR temp;
	NODEPTR stack[20];
	int i=0, k=0;
	char symbol;
	while(symbol=postfix[i]!=‘\0’)
	{
		temp=getnode();
		temp->info=symbol;
		temp->llink=temp->rlink=NULL;
		if(isalnum(symbol))		/* if operand push it*/
			stack[k++]=temp;
		 else				//else pop element add it to the 	
		{				    //right of operator node. Pop 	 	
			temp->rlink=stack[--k];  //next element and add  to		 				     	
			temp->llink=stack[--k];  //left. Push operator node*/	
			stack[++k]=temp
		}
	}
return(stack[--k])			/* return root*/	
}
/*function for iterative preorder traversal*/
Void preorder(NODEPTR root)
{
	NODEPTR cur;
	NODEPTR stack[20];
	int top=-1;
	if(root==NULL)
	{
		printf(“tree is empty”);
		return;
	}
	cur=root;
}
for(; ;)
{
	while(cur!=NULL)
	{
		printf(“%d”, cur->info);
		push(cur,&top,s)		/*push the node to stack*/
		cur=cur->llink;
	}
	if(!stack_empty(top))		/*more nodes existing*/
	{
		cur=pop(&top,s);		/* pop most recent node*/
		cur=cur->rlink;		/*traverse right*/
	}
	else return;
}}
cur=root;
/*function for iterative inorder traversal*/
Void inorder(NODEPTR root)
{
	NODEPTR cur;
	NODEPTR stack[20];
	int top=-1;
	if(root==NULL)
	{
		printf(“tree is empty”);
		return;
	}

for(; ;)
{
	while(cur!=NULL)
	{
		push(cur,&top,s)		/*push the node to stack*/
		cur=cur->llink;
	}
	if(!stack_empty(top))		/*more nodes existing*/
	{
		cur=pop(&top,s);		/* pop most recent node*/
		printf(“%d”, cur->info);
		cur=cur->rlink;		/*traverse right*/
	}
	else return;
}}
/*function for iterative postorder traversal*/
Void postorder(NODEPTR root)
{
	struct stack
	{
		NODEPTR node;
		int flag;
	}; 
	NODEPTR cur;
	struct stack  s[20];
	int top=-1;
	if(root==NULL)
	{
		printf(“tree is empty”);
		return;
	}
	cur=root;
	for(; ;)
	{
		while(cur!=NULL)
		{					//traverse left of tree and push
			s[++top].node=cur;	   	   //the nodes to the stack and
			s[top].flag=1;			   //set flag to 1*/	
			cur=cur->llink;
		}
		while(s[top].flag<0)
		{
			cur=s[top--].node;	//if flag is –ve, right subtree 
			printf(“%d”, cur->info);	   //is visited and hence node 	
							   //is poped and printed*/ 	
			if(stack_empty(top))		//if stack is empty, traversal
				return;			   //is complete*/	
		}
			cur= s[top].node;	//after left subtree is 
		cur=cur->rlink;		   //traversed, move to right and
		s[top].flag=-1;		   //set its flag to -1 to indicate					   right subtree is traversed*/			
	}
}