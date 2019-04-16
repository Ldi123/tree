#include <stdio.h>
#include <stdlib.h>
#define max 100
/**���������ݽṹ����**/
typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *left;
    struct BiTreeNode *right;
}BiTreeNode,*BiTree;
/**�������Ľ���--��������ʽ����--����**/
void CreateBiTree(BiTree *T)
{
    char val;
    scanf("%c",&val);
    if(val == '#')
        *T = NULL;  //null��ʾΪ��֦
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data = val;
        CreateBiTree(&(*T)->left);
        CreateBiTree(&(*T)->right);
    }
}
/**�������  ������**/
void PreOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    printf("%c ",T->data);
    PreOrderTravel(T->left);
    PreOrderTravel(T->right);
}
/**������� �����**/
void InOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    InOrderTravel(T->left);
    printf("%c ",T->data);
    InOrderTravel(T->right);
}
/**������� ���Ҹ�**/
void TailOrderTravel(BiTree T)
{
    if(T==NULL)
        return;
    TailOrderTravel(T->left);
    TailOrderTravel(T->right);
    printf("%c ",T->data);
}
//���Ҹ����ڵ� 
void searchFather(BiTree T,char k){

	if(T==NULL)
	return ; 
	if(T->left!=NULL){
			if(T->left->data==k){
	printf("�����ڵ�ĸ��ڵ��ֵΪ:%c\n",T->data);
    if(T->left!=NULL)
	printf("�ø��׽ڵ��������ֵ��%c ",T->left->data);
	if(T->right!=NULL)
	printf("�ø��׽ڵ��������ֵ��%c",T->right->data);
	}
}
	
	if(T->right!=NULL){
			if(T->right->data==k){
		printf("�����ڵ�ĸ��ڵ��ֵΪ: %c\n",T->data);
    if(T->left!=NULL)
	printf("�ø��׽ڵ������ֵ��%c ",T->left->data);
	if(T->right!=NULL)
	printf("�ø��׽ڵ���Һ���ֵ��%c",T->right->data);
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
	printf("�ýڵ������ֵ��%c ",T->left->data);
	if(T->right!=NULL)
	printf("�ýڵ���Һ���ֵ��%c",T->right->data);
	}
	searchNode(T->left,c);
	searchNode(T->right,c);
}
main() 
{	
    BiTree T,p;
    char a,b,c,d;
    printf("�����������������ʽ�����������ֵ(�ս��Ϊ#):\n");
    CreateBiTree(&T); 
    printf("\n����ʽ���������");
    PreOrderTravel(T);

    printf("\n����ʽ���������");
    InOrderTravel(T);
 
    printf("\n����ʽ���������");
    TailOrderTravel(T);
    while(1){
    printf("\n������Ҫ���Ҹ��ڵ�ĵĽ�㣺");
    scanf("%c\n ",&b);
    printf("��ȷ��һ�飺"); 
    scanf("%c\n",&a);
    searchFather(T,a);
    
    printf("\n������Ҫ���ҵĽ�㣺");
    scanf("%c\n",&c);
    printf("��ȷ��һ�飺"); 
    scanf("%c\n ",&d);
    printf("���ҵ��Ľ���ֵ�ǣ�"); 
    searchNode(T,d);
}
}

