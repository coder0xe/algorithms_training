#ifndef TREE_H
#define TREE_H

typedef struct TNode {
  int data;
  struct TNode *lchild, *rchild;
} TNode, *Tree;

// 统计二叉树中度为1的节点的个数
int CountDegreeOne(Tree T);
// 统计二叉树中度为0的节点的个数
int CountDegreeZero(Tree T);
// 统计二叉树中度为2的节点的个数
int CountDegreeTwo(Tree T);

// 二叉树高度
int Height(Tree T);
// 二叉树的宽度 是类似于层序遍历的思路 队列中只保存每一层的节点
int Width(Tree T);
// 删去所有叶节点
int DeleteLeaf(Tree &T);
// 计算指定节点的层次
int Level(Tree T, TNode *p);
// 计算二叉树中各节点中的最大值
int MaxValue(Tree T);
// 交换二叉树中所有节点的左右子树 就是改一下左右指针指向
void SwapChild(Tree T);
// 先序输出二叉树中所有节点的数据值及节点所在的层次
void PreOrderLevel(Tree T, int level = 1);
#endif