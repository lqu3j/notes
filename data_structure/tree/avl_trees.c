#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node {
	 int value;
	 int height;                // 该节点的深度
	 struct node *lchild;
	 struct node *rchild;
};

void insert(struct node **root, int value);
void _insert(struct node **root, struct node *pNode);
void ll_rotate(struct node **pointer);
void rr_rotate(struct node **pointer);
void lr_rotate(struct node **pointer);
void rl_rotate(struct node **pointer);
void set_node_height(struct node *pNode);
int cal_banlance_factor(struct node *pNode);
void do_banlance(struct node **pointer);
struct node **search(struct node **root, int value);
void delete (struct node **root, int value);
void preorder_traversal(struct node *tree);
void preorder_traversal_height(struct node *tree);
void both_not_null(struct node* root,struct node* pNode);
void single_null(struct node* pNode);
int main() {
	 struct node *root = NULL;
	 int n;

	 // 插入节点
	 while (1) {
		  printf("Please insert number:");
		  scanf("%d", &n);
		  if (n == 0) {
			   break;
		  }
		  insert(&root, n);
		  printf("tree:");
		  preorder_traversal(root);
		  printf("\n");

		  preorder_traversal_height(root);
		  printf("\n");

	 }
	 printf("\n");

}

void insert(struct node **root, int value) {
	 struct node *pNode = (struct node *)malloc(sizeof(struct node));
	 pNode->lchild = NULL;
	 pNode->rchild = NULL;
	 pNode->value = value;

	 if (*root == NULL) {
		  *root = pNode;
		  return;
	 }

	 _insert(&*root, pNode);
}

void _insert(struct node **root, struct node *pNode) {
	 if (!(*root)) {
		  return;
	 }
	 if ((*root)->value > pNode->value) {
		  if ((*root)->lchild == NULL)
			   (*root)->lchild = pNode;
		  else
			   _insert(&(*root)->lchild, pNode);
	 } else {
		  if ((*root)->rchild == NULL)
			   (*root)->rchild = pNode;
		  else
			   _insert(&(*root)->rchild, pNode);
	 }
	 do_banlance(root);
	 set_node_height(*root);
}

struct node **search(struct node **pointer, int value) {
	 struct node *p = *pointer;

	 if (!p)
		  return NULL;

	 if (p->value > value) {
		  return search(&p->lchild, value);
	 }

	 if (p->value < value) {
		  return search(&p->rchild, value);
	 }
	 return pointer;
}

void delete (struct node **pointer, int value) {
	 if (!(*pointer))
		  return;

	 if ((*pointer)->value > value) {
		  search(&(*pointer)->lchild, value);
		  do_banlance(*pointer);
		  set_node_height(*pointer);
		  return;
	 }
	 if ((*pointer)->value < value) {
		  search(&(*pointer)->rchild, value);
		  do_banlance(*pointer);
		  set_node_height(*pointer);
		  return
	 }

	 struct node *pNode = *pointer;

	 // 左子树为空
	 if (pNode->lchild == NULL) {
		  *pointer = pNode->rchild;
		  do_banlance(*pointer);
		  set_node_height(*pointer);
		  free(pNode);
		  return;
	 }
	 // 右子树为空
	 if (pNode->rchild == NULL) {
		  *pointer = pNode->lchild;
		  do_banlance(*pointer);
		  set_node_height(*pointer);
		  free(pNode);
		  return;
	 }

	 // 左右子树均不为空
	 both_not_null(pNode, &pNode);
}

void both_not_null(struct node* pNode,struct node** pointer){
	 if ((*pointer)->rchild){
		  both_not_null(pNode, &(*pointer)->rchild);
		  do_banlance(*pointer);
		  set_node_height(pNode);
		  return;
	 }
	 pNode->value = (*pointer)->value;
	 struct node *tmp = *pointer;
	 *pointer = (*pointer)->lchild;
	 free(tmp);
}

void preorder_traversal(struct node *tree) {
	 if (!tree) {
		  return;
	 }
	 printf("%d,", tree->value);
	 preorder_traversal(tree->lchild);
	 preorder_traversal(tree->rchild);
}

void preorder_traversal_height(struct node *tree) {
	 if (!tree) {
		  return;
	 }
	 printf("%d,", tree->height);
	 preorder_traversal_height(tree->lchild);
	 preorder_traversal_height(tree->rchild);
}

void ll_rotate(struct node **pointer){
	 struct node* first = *pointer;
	 struct node* second = first->lchild;

	 *pointer = second;
	 first->lchild = second->rchild;
	 second->rchild = first;


	 set_node_height(first);
	 set_node_height(second);
}

void rr_rotate(struct node **pointer){
	 struct node* first = *pointer;
	 struct node* second = first->rchild;

	 *pointer = second;
	 first->rchild = second->lchild;
	 second->lchild = first;

	 set_node_height(first);
	 set_node_height(second);
}


void lr_rotate(struct node **pointer){
	 struct node* first = *pointer;
	 struct node* second = first->lchild;
	 struct node* third = second->rchild;

	 first->lchild = third;
	 third->lchild = second;
	 second->rchild = NULL;

	 set_node_height(second);
	 set_node_height(third);
	 set_node_height(first);

	 ll_rotate(pointer);
}

void rl_rotate(struct node **pointer){
	 struct node* first = *pointer;
	 struct node* second = first->rchild;
	 struct node* third = second->lchild;

	 first->rchild = third;
	 third->rchild = second;
	 second->lchild = NULL;

	 set_node_height(second);
	 set_node_height(third);
	 set_node_height(first);

	 rr_rotate(pointer);
}

int cal_banlance_factor(struct node *pNode){
	 if (pNode->lchild == NULL && pNode->rchild != NULL)
		  return - pNode->rchild->height - 1;
	 if (pNode->lchild != NULL && pNode->rchild == NULL)
		  return  pNode->lchild->height + 1;
	 if (pNode->lchild != NULL && pNode->rchild != NULL)
		  return pNode->lchild->height - pNode->rchild->height;
	 return 0;
}

void set_node_height(struct node *pNode){
	 if (pNode->lchild == NULL && pNode->rchild != NULL)
		  pNode->height = pNode->rchild->height + 1;
	 else if (pNode->lchild != NULL && pNode->rchild == NULL)
		  pNode->height = pNode->lchild->height + 1;
	 else if (pNode->lchild != NULL && pNode->rchild != NULL)
		  pNode->height =  pNode->lchild->height > pNode->rchild->height ? pNode->lchild->height + 1 :  pNode->rchild->height + 1;
	 else
		  pNode->height = 0;
}

void do_banlance(struct node **pointer){
		 // ll
	 if (cal_banlance_factor(*pointer) == 2 && cal_banlance_factor((*pointer)->lchild) == 1){
			  printf("ll平衡前:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  ll_rotate(pointer);

			  printf("ll平衡后:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  return;
	 }
	 // rr
	 if (cal_banlance_factor(*pointer) == -2 && cal_banlance_factor((*pointer)->rchild) == -1){
			  printf("rr平衡前:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  rr_rotate(pointer);

			  printf("rr平衡后:");
			  preorder_traversal(*pointer);
			  printf("\n");
			  return;
	 }
	 // lr
	 if (cal_banlance_factor(*pointer) == 2 && cal_banlance_factor((*pointer)->lchild) == -1){
			  printf("lr平衡前:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  lr_rotate(pointer);

			  printf("lr平衡后:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  return;
	 }
====	 // rl
	 if (cal_banlance_factor(*pointer) == -2 && cal_banlance_factor((*pointer)->rchild) == 1){
			  printf("rl平衡前:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  rl_rotate(pointer);

			  printf("rl平衡后:");
			  preorder_traversal(*pointer);
			  printf("\n");

			  return;
	 }
}
