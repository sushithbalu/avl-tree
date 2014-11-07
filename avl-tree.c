#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node* left;
	struct node* right;
};

struct node* insert(struct node* root, int value);
struct node* rightrotate(struct node* );
struct node* leftrotate(struct node* );
struct node* newnode(int );
void treeprint(struct node* );
int heightof(struct node* );
struct node* insert(struct node* , int );
int balance(struct node* );
int compare(int, int );
int b;	

int main(int argc, char *argv[])
{
	struct node *root = NULL;
	root = insert(root, 12);
	root = insert(root, 54);
	root = insert(root, 8);
	root = insert(root, 33);
	treeprint(root);
	printf("\n");
	root = insert(root, 25);
	treeprint(root);
	printf("\n");
	root = insert(root, 1);
	treeprint(root);
	printf("\n");
	root = insert(root, 11);
	treeprint(root);
	printf("\n");
	root = insert(root, 17);
/*
	root = newnode(7);
	root->left = newnode(4);
	root->right = newnode(8);
	root->left->right = newnode(6);
	root->left->left = newnode(3);
*/
	return 0;
}

struct node* insert(struct node* root, int value)
{

	if(root == NULL){
		return newnode(value);
	}
	if(value < root->data){
		root->left = insert(root->left, value);
	} else {
		root->right = insert(root->right, value);
	}
	root->height = compare(heightof(root->left), heightof(root->right)) + 1;
	
	b = balance(root);
	if(b > 1){ 
		if(value < root->left->data){		//left left
			return rightrotate(root);
		} else {				//left right
			root->left = leftrotate(root->left);
			return rightrotate(root);
		}
	}
	if(b < -1){
		if(value > root->right->data){		//right right
			return leftrotate(root);
		} else {				//right left
			root->right = rightrotate(root->right);
			return leftrotate(root);
		}
	}
	return root;		 
}

/*              -2
             |root|                     |sub|
right         / \*       ---->           / \*			
rotation 1|sub|   |c|                 |a|  |root|
  ,~7      / \*          <---               / \
 (      |a|   |b|                        |b|   |c|
  `-    
*/

struct node* rightrotate(struct node *root)
{
	int compare(int, int);
	struct node *sub = root->left;
	struct node *b = sub->right;

	sub->right = root;
	root->left = b;
	root->height = compare(heightof(root->left), heightof(root->right)) + 1;
	sub->height = compare(heightof(sub->left), heightof(sub->right)) + 1;
	return sub;
}

struct node* leftrotate(struct node *sub)
{
	int compare(int, int);
	struct node *root = sub->right;
	struct node *b = root->left;
	
	root->left = sub;
	sub->right = b;
	sub->height = compare(heightof(sub->left), heightof(sub->right)) + 1;
	root->height = compare(heightof(root->left), heightof(root->right)) + 1;
	return root;
}

int compare(int a, int b)
{
	return (a > b) ? a : b;
}

struct node *newnode(int value)
{
	struct node *current = malloc(sizeof(struct node));
	current->data = value;
	current->left = NULL;
	current->right = NULL;
	current->height = 1;
	return current;
}

int heightof(struct node* root)
{
	if(root == NULL)
		return 0;
	return root->height;
}

int balance(struct node* root)
{
	struct node* current = root;
	if(current == NULL)
		return 0;
	return heightof(current->left) - heightof(current->right);
}

void treeprint(struct node *root)
{
	struct node *current = root;
	if(current == NULL){
		return ;
	} else {
		printf("%d ", current->data);
		treeprint(current->left);
		treeprint(current->right);
	}
}
