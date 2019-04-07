#include<stdio.h>
#include<malloc.h>
#define max(a,b) ((a>b)?(a):(b))
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
void insert(struct node **root,int val) // Avg: O(lg n) , Worst: O(n) 
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->left=NULL;
	newnode->right=NULL;
	if(*root==NULL)
	*root=newnode;
	else
	if(val<=(*root)->data)
	insert(&((*root)->left),val);
	else
	if(val>(*root)->data)
	insert(&((*root)->right),val);
}
struct node* search(struct node *root,int val) // Avg: O(lg n) , Worst: O(n) 
{
	if(root==NULL)
	return NULL;
	if(root->data==val)
	return root;
	else if(val>root->data)
	return search(root->right,val);
	else if(val<root->data)
	return search(root->left,val);
}
struct node* searchMin(struct node *root) // Avg: O(lg n) , Worst: O(n) 
{
	if(root==NULL)
	return NULL;
	if(root->left!=NULL)
	return searchMin(root->left);
	else
	return (root);
}
void inorder(struct node *root) //O(n)=  worst,best case
{
	if(root==NULL)
	return;
	else
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)  //O(n)=  worst,best case
{
	if(root==NULL)
	return;
	else
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root) // O(n)=  worst,best case
{
	if(root==NULL)
	return;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void Delete(struct node **root,int val) // Avg: O(lg n) , Worst: O(n) 
{
	if(*root==NULL)
	printf("Tree is Empty\n");
	else if(val > (*root)->data)
	Delete(&((*root)->right),val);
	else if (val < (*root)->data)
	Delete(&((*root)->left),val);
	else if (val == (*root)->data)
	{
		struct node *temp;
		if((*root)->left==NULL && (*root)->right==NULL) //no child case
		{
			temp=*root;
			*root=NULL;
			free(temp);
		}
		else if((*root)->left==NULL) //no left child case 
		{
			temp=*root;
			*root=(*root)->right;
			free(temp);
		}
		else if((*root)->right==NULL) // no right child case
		{
			temp=*root;
			*root=(*root)->left;
			free(temp);
		}
		else //has both child present
		{
			 temp = searchMin((*root)->right); // inorder successor
			(*root)->data=temp->data;
			Delete(&((*root)->right),temp->data);
		}
	}
}
int getHeight(struct node *root) // Avg: O(lg n) , Worst: O(n)
{
	if(root==NULL)
	return -1;
	else
	return max(getHeight(root->left),getHeight(root->right))+1;
}
struct node* largest(struct node *root) // Avg: O(lg n) , Worst: O(n)
{
	if(root==NULL)
	return NULL;
	if(root->right!=NULL)
	return largest(root->right);
	else
	return (root);
}
int main()
{
	int choice,val;
	struct node *root=NULL;
	do
	{
		printf("\n\nMenu:-\n01. Insert\n02. Delete\n03. Display\n04. Search\n05. getHeight\n06. Largest\n");
		printf("07. Exit\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter data:\n");
				scanf("%d",&val);
				insert(&root,val);
			break;
			case 2:
				printf("Enter data:\n");
				scanf("%d",&val);
				Delete(&root,val);
			break;
			case 3:
				printf("Inorder  : ");
				inorder(root);
				printf("\nPreorder : ");
				preorder(root);
				printf("\nPostorder: ");
				postorder(root);
				printf("\n");
			break;
			case 4:
				printf("Enter data:\n");
				scanf("%d",&val);
				if(search(root,val)!=NULL)
				printf("Found : %d\n",val);
				else
				printf("Not Found : %d\n",val);
			break;
			case 5:
				printf("Height of Tree is: %d\n",getHeight(root));
			break;
			case 6:
				printf("Largest: %d\n",largest(root)->data);
			break;
		}
	}while(choice!=7);
	return 0;
}
