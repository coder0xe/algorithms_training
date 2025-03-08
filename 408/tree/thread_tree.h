#ifndef TREE_H
#define TREE_H

typedef struct ThreadNode {
  int data;
  struct ThreadNode *leftChild, *rightChild;
  int ltag, rtag;
} ThreadNode, *ThreadTree;

void InitTheadTree(ThreadTree &T);
void PreOrder(const ThreadTree T);
void InOrder(const ThreadTree T);
void PostOrder(const ThreadTree T);
void LevelOrder(const ThreadTree T);
void VisitNode(const ThreadNode *node);

void CreateInThread(ThreadTree T);
void InThread(ThreadTree &p, ThreadTree &pre);
ThreadNode *FirstNode(const ThreadTree T);
ThreadNode *NextNode(const ThreadTree T);
ThreadNode *PreNode(const ThreadTree T);
ThreadNode *LastNode(const ThreadTree T);
void ThreadInOrder(const ThreadTree T);
void RevThreadInOrder(const ThreadTree T);

void CreatePreThread(ThreadTree T);
void PreThread(ThreadTree &p, ThreadTree &pre);
ThreadNode *FirstNode_pre(const ThreadTree T);
ThreadNode *NextNode_pre(const ThreadTree T);
ThreadNode *PreNode_pre(const ThreadTree T);
ThreadNode *LastNode_pre(const ThreadTree T);
void ThreadPreOrder(const ThreadTree T);
void RevThreadPreOrder(const ThreadTree T);

void CreatePosThread(ThreadTree T);
void PosThread(ThreadTree &p, ThreadTree &pre);
ThreadNode *FirstNode_pos(const ThreadTree T);
ThreadNode *NextNode_pos(const ThreadTree T);
ThreadNode *PreNode_pos(const ThreadTree T);
ThreadNode *LastNode_pos(const ThreadTree T);
void ThreadPosOrder(const ThreadTree T);
void RevThreadPosOrder(const ThreadTree T);
#endif