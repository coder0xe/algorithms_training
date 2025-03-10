#include "tree.h"
#include <iostream>
#include <math.h>
#include <queue>

int CountDegreeOne(Tree T) {
  if (T == nullptr) {
    return 0;
  }
  if ((T->lchild == nullptr && T->rchild != nullptr) ||
      (T->lchild != nullptr && T->rchild == nullptr)) {
    return 1 + CountDegreeOne(T->lchild) + CountDegreeOne(T->rchild);
  } else {
    return CountDegreeOne(T->lchild) + CountDegreeOne(T->rchild);
  }
}

int CountDegreeZero(Tree T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    return 1;
  } else {
    return CountDegreeZero(T->lchild) + CountDegreeZero(T->rchild);
  }
}

int CountDegreeTwo(Tree T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild != nullptr && T->rchild != nullptr) {
    return 1 + CountDegreeTwo(T->lchild) + CountDegreeTwo(T->rchild);
  } else {
    return CountDegreeTwo(T->lchild) + CountDegreeTwo(T->rchild);
  }
}

int Height(Tree T) {
  if (T == nullptr) {
    return 0;
  }
  int left = Height(T->lchild);
  int right = Height(T->rchild);
  return left > right ? left + 1 : right + 1;
}

int Width(TNode *root) {
  if (root == nullptr) {
    return 0;
  }

  std::queue<TNode *> q;
  q.push(root);
  int maxWidth = 0;

  while (!q.empty()) {
    int count = q.size();
    maxWidth = std::max(maxWidth, count);

    while (count--) {
      TNode *node = q.front();
      q.pop();

      if (node->lchild != nullptr) {
        q.push(node->lchild);
      }
      if (node->rchild != nullptr) {
        q.push(node->rchild);
      }
    }
  }

  return maxWidth;
}

int DeleteLeaf(Tree &T) {
  if (T == nullptr) {
    return 0;
  }
  if (T->lchild == nullptr && T->rchild == nullptr) {
    delete T;
    T = nullptr;
    return 1;
  } else {
    return DeleteLeaf(T->lchild) + DeleteLeaf(T->rchild);
  }
}

int Level(Tree T, TNode *p) {
  if (T == nullptr || p == nullptr) {
    return 0;
  }
  if (T == p) {
    return 1;
  }
  int left = Level(T->lchild, p);
  int right = Level(T->rchild, p);
  return left > right ? left + 1 : right + 1;
}

int MaxValue(Tree T) {
  if (T == nullptr) {
    return 0;
  }
  int left = MaxValue(T->lchild);
  int right = MaxValue(T->rchild);
  return std::max(std::max(left, right), T->data);
}

void SwapChild(Tree T) {
  if (T == nullptr) {
    return;
  }
  TNode *tmp = T->lchild;
  T->lchild = T->rchild;
  T->rchild = tmp;
  SwapChild(T->lchild);
  SwapChild(T->rchild);
}

void PreOrderLevel(Tree T, int level) {
  if (T == nullptr) {
    return;
  }
  std::cout << T->data << " at level " << level << std::endl;
  PreOrderLevel(T->lchild, level + 1);
  PreOrderLevel(T->rchild, level + 1);
}