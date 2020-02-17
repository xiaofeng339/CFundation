#include<stdlib.h>
struct  BiNode {
	char ch;
	struct BiNode* lchild;
	struct BiNode* rchild;
};
//�������ݹ����
void recursion(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	printf("%c ", root->ch);
}

//Ҷ�ӽڵ���
int num = 0;
void cuculateLeafNum(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	if (root->lchild == NULL && root->rchild == NULL) {
		num++;
	}
	cuculateLeafNum(root->lchild);
	cuculateLeafNum(root->rchild);
}

//���ĸ߶�
int getTreeHeight(struct BiNode* root) {
	if (NULL == root) {
		return 0;
	}
	//�������������߶�
	int lheight = getTreeHeight(root->lchild);
	//�������������߶�
	int rlheight = getTreeHeight(root->rchild);

	int height = lheight > rlheight ? lheight + 1 : rlheight + 1;

	return height;
}

//��ӡ������
void showBiTree(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	printf("%c ", root->ch);
	showBiTree(root->lchild);
	showBiTree(root->rchild);
}
//���ƶ�����
struct BiNode *copyBiTree(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	//�ȿ���������
	struct BiNode* lchild = copyBiTree(root->lchild);
	//�ȿ���������
	struct BiNode* rchild = copyBiTree(root->rchild);

	struct BiNode* newnode = malloc(sizeof(struct BiNode));
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->ch = root->ch;
	return newnode;
}
//��ն�����

void freeSpace(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	//�ͷ��������ڴ�
	freeSpace(root->lchild);
	//�ͷ�������
	freeSpace(root->rchild);
	free(root);
}

