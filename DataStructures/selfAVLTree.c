#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	int ht;
	struct node *left;
	struct node *right;
};
int height(struct node *T){ //O(1)
	int lh,rh;
	if(T==NULL)
		return(0);
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	if(lh>rh)
		return(lh);
	return(rh);
}
struct node* rotateright(struct node *x) //O(1)
{
	struct node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
struct node* rotateleft(struct node *x) //O(1)
{
	struct node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
struct node* RR(struct node *T) //O(1)
{
	T=rotateleft(T);
	return(T);
}
 
struct node* LL(struct node *T) //O(1)
{
	T=rotateright(T);
	return(T);
}
 
struct node* LR(struct node *T) //O(1)
{
	T->left=rotateleft(T->left);
	T=rotateright(T);
	return(T);
}
struct node* RL(struct node *T) //O(1)
{
	T->right=rotateright(T->right);
	T=rotateleft(T);
	return(T);
}
int BF(struct node *T) //O(1)
{
	int lh,rh;
	if(T==NULL)
		return(0);
 
	if(T->left==NULL)
		lh=0;
	else
		lh=1+T->left->ht;
 
	if(T->right==NULL)
		rh=0;
	else
		rh=1+T->right->ht;
	return(lh-rh);
}
void preorder(struct node *T)  //O(n)
{
	if(T!=NULL)
	{
		printf("%d(Bf=%d) ",T->data,BF(T));
		preorder(T->left);
		preorder(T->right);
	}
}
void inorder(struct node *T) //O(n)
{
	if(T!=NULL)
	{
		inorder(T->left);
		printf("%d(Bf=%d) ",T->data,BF(T));
		inorder(T->right);
	}
}
void postorder(struct node *T) //O(n)
{
	if(T!=NULL)
	{
		postorder(T->left);
		postorder(T->right);
		printf("%d(Bf=%d) ",T->data,BF(T));
	}
}
struct node* insert(struct node *T,int x) //O(lgn)
{
	if(T==NULL)
	{
		T=(struct node*)malloc(sizeof(struct node));
		T->data=x;
		T->left=NULL;
		T->right=NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=insert(T->right,x);
			if(BF(T)==-2)
				if(x>T->right->data)
					T=RR(T);
				else
					T=RL(T);
		}
		else
			if(x<T->data) // insert in left subtree
			{
				T->left=insert(T->left,x);
				if(BF(T)==2)
					if(x < T->left->data)
						T=LL(T);
					else
						T=LR(T);
			}
		T->ht=height(T);
		return(T);
}
struct node* Delete(struct node *T,int x)  //O(lgn)
{
	struct node *p;
	if(T==NULL)
	{
		return NULL;
	}
	else
		if(x > T->data)		// insert in right subtree
		{
			T->right=Delete(T->right,x);
			if(BF(T)==2)
				if(BF(T->left)>=0)
					T=LL(T);
				else
					T=LR(T);
		}
		else
			if(x<T->data)
			{
				T->left=Delete(T->left,x);
				if(BF(T)==-2)	//Rebalance during windup
					if(BF(T->right)<=0)
						T=RR(T);
					else
						T=RL(T);
			}
			else
			{
				//data to be deleted is found
				if(T->right!=NULL)
				{	//delete its inorder succesor
					p=T->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					T->data=p->data;
					T->right=Delete(T->right,p->data);
					
					if(BF(T)==2)//Rebalance during windup
						if(BF(T->left)>=0)
							T=LL(T);
						else
							T=LR(T);
				}
				else
					return(T->left);
			}
	T->ht=height(T);
	return(T);
}
int main()
{
	struct node *root=NULL;
	int x,n,i,op;
	do
	{
		printf("\n1)Create");
		printf("\n2)Insert");
		printf("\n3)Delete");
		printf("\n4)Print");
		printf("\n5)Quit");
		printf("\n\nEnter Your Choice: ");
		scanf("%d",&op);
		switch(op)
		{
			case 1: printf("\nEnter no. of elements: ");
					scanf("%d",&n);
					printf("\nEnter tree data: ");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;
				
			case 2: printf("\nEnter a data: ");
					scanf("%d",&x);
					root=insert(root,x);
					break;
					
			case 3: printf("\nEnter a data: ");
					scanf("%d",&x);
					root=Delete(root,x);
					break;
			
			case 4: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n\nPostorder sequence:\n");
					postorder(root);
					printf("\n");
					break;			
		}
	}while(op!=5);
	return 0;
}
