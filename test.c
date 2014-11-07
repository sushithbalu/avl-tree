#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	int height;
	struct node* left;
	struct node* right;
};

struct node* newnode(int);
void treeprint(struct node*);

int main(int argc, char *argv[])
{
	struct node *root;
	root = newnode(7);
	root->left = newnode(4);
	root->right = newnode(8);
	root->left->right = newnode(6);
	root->left->left = newnode(3);
	treeprint(root);
	return 0;
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
	if(root == NULL){
		return 0;
	}
	return root->height;
}	 

int balance(struct node* root)
{
	struct node* current = root;
	if(current == NULL){
		return 0;
	}
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

