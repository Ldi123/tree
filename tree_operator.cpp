#include <stdio.h>
#include <stdlib.h>
#define max 100
/**二叉树数据结构定义**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode,*BiTree;
/**二叉树的建立--按照先序方式建立--插入**/
void CreateBiTree(BiTree *T)
{
    char val;
    scanf("%c",&val);
    if(val == '#')
        *T = NULL;  //null表示为空枝
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data = val;
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}
/**先序遍历  根左右**/
void PreOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c ",T->data);
    PreOrderTravel(T->left);
    PreOrderTravel(T->right);
}
/**中序遍历 左根右**/
void InOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTravel(T->left);
    printf("%c ",T->data);
    InOrderTravel(T->right);
}
/**后序遍历 左右根**/
void TailOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    TailOrderTravel(T->left);
    TailOrderTravel(T->right);
    printf("%c ",T->data);
}
//查找给定节点 
void searchFather(BiTree T,char k){

	if(T==NULL)
	return ; 
	if(T->left!=NULL){
			if(T->left->data==k){
	printf("给定节点的父节点的值为:%c\n",T->data);
    if(T->left!=NULL)
	printf("该父亲节点的左子树值：%c ",T->left->data);
	if(T->right!=NULL)
	printf("该父亲节点的右子树值：%c",T->right->data);
	}
}
	
	if(T->right!=NULL){
			if(T->right->data==k){
		printf("给定节点的父节点的值为: %c\n",T->data);
    if(T->left!=NULL)
	printf("该父亲节点的左孩子值：%c ",T->left->data);
	if(T->right!=NULL)
	printf("该父亲节点的右孩子值：%c",T->right->data);
}
}
searchFather(T->left,k);
searchFather(T->right,k);
}
BiTree searchNode(BiTree T,char c){
	if(T==NULL)
	return NULL;
	if(T->data==c){
	printf("%c\n",T->data);
    if(T->left!=NULL)
	printf("该节点的左孩子值：%c ",T->left->data);
	if(T->right!=NULL)
	printf("该节点的右孩子值：%c",T->right->data);
	}
	searchNode(T->left,c);
	searchNode(T->right,c);
}
main() 
{	
    BiTree T,p;
    char a,b,c,d;
    printf("请给二叉树按照先序方式依次输入结点的值(空结点为#):\n");
    CreateBiTree(&T); 
    printf("\n先序方式遍历结果：");
    PreOrderTravel(T);

    printf("\n中序方式遍历结果：");
    InOrderTravel(T);
 
    printf("\n后序方式遍历结果：");
    TailOrderTravel(T);
    while(1){
    printf("\n请输入要查找父节点的的结点：");
    scanf("%c\n ",&b);
    printf("请确认一遍："); 
    scanf("%c\n",&a);
    searchFather(T,a);
    
    printf("\n请输入要查找的结点：");
    scanf("%c\n",&c);
    printf("请确认一遍："); 
    scanf("%c\n ",&d);
    printf("查找到的结点的值是："); 
    searchNode(T,d);
}
}

