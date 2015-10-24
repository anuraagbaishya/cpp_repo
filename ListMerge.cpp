#include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
	node *create(node *,int);
	node *trav(node *);
	node *mergelist(node *,node *);
	node *merge(node *,node *);
};
node* node::create(node *first,int a)
{
    node *cu=first;
    if(cu==NULL)
    {
        cu=new node;
        cu->data=a;
        cu->next=NULL;
        return cu;
    }
    else
    {
        while(cu->next!=NULL)
            cu=cu->next;
        node *temp=new node;
        temp->data=a;
        temp->next=NULL;
        cu->next=temp;
    }
    return first;
}
node* node::trav(node *first)
{
	node *cur=first;
	if(cur!=NULL)
	{
		while(cur!=NULL)
		{
			cout<<cur->data;
			if(cur->next!=NULL)
				cout<<"--";
			cur=cur->next;
		}
		cout<<endl;
	}
	else
		cout<<"Empty list\n";
}
node* node::mergelist(node *first,node *second)
{
    node *result=NULL;
    if(first==NULL)
        return second;
    else if(second==NULL)
        return first;
    if(first->data<second->data)
    {
        result=first;
        result->next=mergelist(first->next,second);
    }
    else
    {
        result=second;
        result->next=(mergelist(second->next,first));
    }
    return result;
}
// node* node::merge(node *l1,node *l2)
// {
//    	node *temp,*pre_node,*pptr,*qptr;
//   	int data;
//    	node *res=temp;
//    	pptr=l1;
//    	qptr=l2;
//    	temp=pre_node=temp=NULL;
//    	while(pptr!=NULL && qptr!=NULL)
//    	{
//       	if(pptr->data<=qptr->data)
//       	{
// 	 			data=pptr->data;
// 	 			pptr=pptr->next;
//       	}
//       	else
//       	{
// 	 		data=qptr->data;
// 	 		qptr=qptr->next;
//       	}
//   		temp=new node;
//   		temp->data=data;
//   		temp->next=NULL;
//       	if(pre_node==NULL)
// 	 		pre_node=temp;
//       	else
//       	{
// 	 		pre_node->next=temp;
//         	pre_node=temp;
//         }
//    	}
//    	if(pptr==NULL)
//    	{
//       	while(qptr!=NULL)
//       	{
// 	 		temp=new node;
// 	 		temp->data=qptr->data;
// 	 		temp->next=NULL;
// 	 		if(pre_node==NULL)
// 	    		pre_node=temp;
// 	 		else
// 	 		{
// 	    		pre_node->next=temp;
// 	 			pre_node=temp;
// 	 		}
// 	 		qptr=qptr->next;
//    	   }
//    	}
//    	else if(qptr==NULL)
//    	{
//       	while(pptr!=NULL)
//       	{
// 	 		temp=new node;
// 	 		temp->data=pptr->data;
// 	 		temp->next=NULL;
// 	 		if(pre_node==NULL)
// 	    		pre_node=temp;
// 	 		else
// 	 		{
// 	    		pre_node->next=temp;
// 	 			pre_node=temp;
// 	 		}
// 	 		pptr=pptr->next;
//     	}
//  	}
//    return res;
// }
int main()
{
	node *first1=NULL, *first2=NULL,*third=NULL,*fourth=NULL;
	node l;
	int n,i=0,data;
	do{
		cout<<"Enter list no.: ";
		cin>>n;
		cout<<"Data: ";
		cin>>data;
		if(n==1)
			first1=l.create(first1,data);
		else
			first2=l.create(first2,data);
		i++;
	}while(i!=6);
	l.trav(first1);
	l.trav(first2);
	third=l.mergelist(first1,first2);
	l.trav(third);
	fourth=l.merge(first1,first2);
	l.trav(fourth);

}
