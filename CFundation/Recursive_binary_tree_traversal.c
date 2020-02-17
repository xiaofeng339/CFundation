#include<stdlib.h>
struct  BiNode {
	char ch;
	struct BiNode* lchild;
	struct BiNode* rchild;
};
//二叉树递归遍历
void recursion(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	printf("%c ", root->ch);
}

//叶子节点数
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

//树的高度
int getTreeHeight(struct BiNode* root) {
	if (NULL == root) {
		return 0;
	}
	//求树的左子树高度
	int lheight = getTreeHeight(root->lchild);
	//求树的右子树高度
	int rlheight = getTreeHeight(root->rchild);

	int height = lheight > rlheight ? lheight + 1 : rlheight + 1;

	return height;
}

//打印二叉树
void showBiTree(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	printf("%c ", root->ch);
	showBiTree(root->lchild);
	showBiTree(root->rchild);
}
//复制二叉树
struct BiNode *copyBiTree(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	//先拷贝左子树
	struct BiNode* lchild = copyBiTree(root->lchild);
	//先拷贝左子树
	struct BiNode* rchild = copyBiTree(root->rchild);

	struct BiNode* newnode = malloc(sizeof(struct BiNode));
	newnode->lchild = lchild;
	newnode->rchild = rchild;
	newnode->ch = root->ch;
	return newnode;
}
//清空二叉树

void freeSpace(struct BiNode* root) {
	if (NULL == root) {
		return;
	}
	//释放左子树内存
	freeSpace(root->lchild);
	//释放右子树
	freeSpace(root->rchild);
	free(root);
}

