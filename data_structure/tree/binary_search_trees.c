#include <stdio.h>
#include <stdlib.h>

struct node {
	 int value;
	 struct node* lchild;
	 struct node* rchild;
};

void insert(struct node** root, int value);
void _insert(struct node* root, struct node *pNode);
struct node** search(struct node** root, int value);
void delete(struct node** root, int value);
void preorder_traversal(struct node* tree);


int main(){
	 struct node* root = NULL;
	 int n;

	 // 插入节点
	 while(1){
		  printf("Please insert number:");
		  scanf("%d", &n);
		  if (n == 0){
			   break;
		  }
		  insert(&root, n);
		  preorder_traversal(root);
		  printf("\n");
	 }
	 printf("\n");

	 // 删除节点
	 while(1){
		  printf("Please delete number:");
		  scanf("%d", &n);
		  if (n == 0){
			   break;
		  }
		  delete(&root, n);
		  preorder_traversal(root);
		  printf("\n");
	 }
}

void insert(struct node** root, int value){
	 struct node* pNode = (struct node*)malloc(sizeof(struct node));
	 pNode->lchild = NULL;
	 pNode->rchild = NULL;
	 pNode->value = value;

	 if (*root == NULL){
		  *root = pNode;
		  return;
	 }

	 _insert(*root, pNode);
}

void _insert(struct node* root, struct node *pNode){
	 if (!root){
		  return;
	 }
	 if (root->value > pNode->value){
		  if (root->lchild == NULL)
			   root->lchild = pNode;
		  else
			   _insert(root->lchild, pNode);
	 }else{
		  if (root->rchild == NULL)
			   root->rchild = pNode;
		  else
			   _insert(root->rchild, pNode);
	 }
}

struct node** search(struct node** pointer, int value){
	 struct node* p = *pointer;

	 if (!p)
		  return NULL;

	 if (p->value > value){
		  return search(&p->lchild, value);
	 }

	 if (p->value < value){
		  return search(&p->rchild, value);
	 }
	 return pointer;
}

void delete(struct node** pointer, int value){
	 struct node** p = search(pointer, value);

	 if (!p)
		  return;

	 struct node *pNode = *p;
	 // 左子树为空
	 if (pNode->lchild == NULL){
		  *p = pNode->rchild;
		  free(pNode);
		  return;
	 }
	 // 右子树为空
	 if (pNode->rchild == NULL){
		  *p = pNode->lchild;
		  free(pNode);
		  return;
	 }
	 // 左右子树均不为空
	 struct node **lMaxChildPointer = &pNode->lchild;
	 while((*lMaxChildPointer)->rchild)
		  lMaxChildPointer = &(*lMaxChildPointer)->rchild;
	 pNode->value = (*lMaxChildPointer)->value;

	 struct node* tmp = *lMaxChildPointer;
	 *lMaxChildPointer = (*lMaxChildPointer)->lchild;
	 free(tmp);
}


void preorder_traversal(struct node* tree){
	 if (!tree){
		  return;
	 }
	 printf("%d,", tree->value);
	 preorder_traversal(tree->lchild);
	 preorder_traversal(tree->rchild);
}
