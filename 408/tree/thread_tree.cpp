#include "thread_tree.h"
#include <deque>
#include <iostream>

void InitTheadTree(ThreadTree &T) {
  for (int i = 1; i <= 10; i++) {
    ThreadNode *newNode = new ThreadNode{i, nullptr, nullptr, 0, 0};
    if (T == nullptr)
      T = newNode;
    else {
      ThreadNode *current = T;
      ThreadNode *parent = nullptr;
      while (current != nullptr) {
        parent = current;
        if (i < current->data)
          current = current->leftChild;
        else
          current = current->rightChild;
      }
      if (i < parent->data)
        parent->leftChild = newNode;
      else
        parent->rightChild = newNode;
    }
  }
}

void VisitNode(const ThreadNode *node) { std::cout << node->data << ' '; }

void PreOrder(const ThreadTree T) {
  if (T != nullptr) {
    VisitNode(T);
    PreOrder(T->leftChild);
    PreOrder(T->rightChild);
  }
}

void InOrder(const ThreadTree T) {
  if (T != nullptr) {
    InOrder(T->leftChild);
    VisitNode(T);
    InOrder(T->rightChild);
  }
}

void PostOrder(const ThreadTree T) {
  if (T != nullptr) {
    PostOrder(T->leftChild);
    PostOrder(T->rightChild);
    VisitNode(T);
  }
}

void LevelOrder(const ThreadTree T) {
  std::deque<ThreadNode *> queue;
  queue.push_back(T);
  ThreadNode *tmp = nullptr;
  while (!queue.empty()) {
    tmp = queue.front();
    VisitNode(tmp);
    queue.pop_front();
    if (tmp->leftChild)
      queue.push_back(tmp->leftChild);
    if (tmp->rightChild)
      queue.push_back(tmp->rightChild);
  }
}

// 中序线索二叉树
void CreateInThread(ThreadTree T) {
  if (!T) {
    std::cout << "Error! Empty Tree!" << std::endl;
    return;
  }
  ThreadTree pre = nullptr;
  InThread(T, pre);
  pre->rightChild = nullptr;
  pre->rtag = 1;
}

void InThread(ThreadTree &p, ThreadTree &pre) {
  if (p) {
    InThread(p->leftChild, pre);
    if (!p->leftChild) {
      p->leftChild = pre;
      p->ltag = 1;
    }
    if (pre && !pre->rightChild) {
      pre->rightChild = p;
      pre->rtag = 1;
    }
    pre = p;
    InThread(p->rightChild, pre);
  }
}

// 中序遍历中最左下的节点是第一个访问的节点
ThreadNode *FirstNode(const ThreadTree T) {
  ThreadNode *tmp = T;
  while (tmp->ltag == 0)
    tmp = tmp->leftChild;
  return tmp;
}

ThreadNode *NextNode(const ThreadTree T) {
  if (T->rtag == 1)
    return T->rightChild;
  else
    return FirstNode(T->rightChild); // 右子树第一个访问的节点
}

void ThreadInOrder(const ThreadTree T) {
  for (ThreadNode *first = FirstNode(T); first != nullptr;
       first = NextNode(first))
    VisitNode(first);
}

// 中序遍历中最右下的节点是最后一个访问的节点
ThreadNode *LastNode(const ThreadTree T) {
  ThreadNode *tmp = T;
  while (tmp->rtag == 0)
    tmp = tmp->rightChild;
  return tmp;
}

ThreadNode *PreNode(const ThreadTree T) {
  if (T->ltag == 1)
    return T->leftChild;
  else
    return LastNode(T->leftChild); // 左子树最后一个访问的节点
}

void RevThreadInOrder(const ThreadTree T) {
  for (ThreadNode *last = LastNode(T); last != nullptr; last = PreNode(last))
    VisitNode(last);
}

// 前序线索二叉树
void CreatePreThread(ThreadTree T) {
  if (!T) {
    std::cout << "Error! Empty Tree!" << std::endl;
    return;
  }
  ThreadNode *pre = nullptr;
  PreThread(T, pre);
  pre->rightChild = nullptr;
  pre->rtag = 1;
}

void PreThread(ThreadTree &p, ThreadTree &pre) {
  if (p) {
    if (!p->leftChild) {
      p->leftChild = pre;
      p->ltag = 1;
    }
    if (pre && !pre->rightChild) {
      pre->rightChild = p;
      pre->rtag = 1;
    }
    pre = p;
    // 这里要判断tag==0 tag==0保证了访问的是实际的节点 而不是前驱/后继
    // 防止循环调用
    if (p->ltag == 0)
      PreThread(p->leftChild, pre);
    if (p->rtag == 0)
      PreThread(p->rightChild, pre);
  }
}

// 先序遍历第一个访问的就是当前节点
ThreadNode *FirstNode_pre(const ThreadTree T) { return T; }

// 先序遍历下一个访问的就是当前节点的左孩子或右孩子同样需要判断tag来保证访问的是实际的孩子而不是前驱/后继
ThreadNode *NextNode_pre(const ThreadTree T) {
  if (T->ltag == 0) {
    return T->leftChild;
  } else if (T->rtag == 0) {
    return T->rightChild;
  } else {
    return T->rightChild;
  }
}

void ThreadPreOrder(const ThreadTree T) {
  for (ThreadNode *first = FirstNode_pre(T); first != nullptr;
       first = NextNode_pre(first))
    VisitNode(first);
}

// ThreadNode *LastNode_pre(const ThreadTree T) {}

// ThreadNode *PreNode_pre(const ThreadTree T) {}

// void RevThreadPreOrder(const ThreadTree T) {
//   for (ThreadNode *last = LastNode_pre(T); last != nullptr;
//        last = PreNode_pre(last))
//     VisitNode(last);
// }

// 后序线索二叉树
void CreatePosThread(ThreadTree T) {
  if (!T) {
    std::cout << "Error! Empty Tree!" << std::endl;
    return;
  }
  ThreadNode *pre = nullptr;
  PosThread(T, pre);
  pre->rightChild = nullptr;
  pre->rtag = 1;
}

void PosThread(ThreadTree &p, ThreadTree &pre) {
  if (p) {
    if (p->ltag == 0)
      PosThread(p->leftChild, pre);
    if (p->rtag == 0)
      PosThread(p->rightChild, pre);
    if (!p->leftChild) {
      p->leftChild = pre;
      p->ltag = 1;
    }
    if (pre && !pre->rightChild) {
      pre->rightChild = p;
      pre->rtag = 1;
    }
    pre = p;
  }
}

ThreadNode *FirstNode_pos(const ThreadTree T) {
  ThreadNode *tmp = T;
  while (true) {
    if (tmp->ltag == 0) {
      tmp = tmp->leftChild;
    } else if (tmp->rtag == 0) {
      tmp = tmp->rightChild;
    } else {
      break;
    }
  }
  return tmp;
}

ThreadNode *NextNode_pos(const ThreadTree T) {
  if (T->rtag == 1) {
    return T->rightChild;
  } else {
    ThreadNode *parent = T->rightChild;
    if (parent && parent->leftChild == T) {
      return parent;
    } else {
      return FirstNode_pos(parent);
    }
  }
}

void ThreadPosOrder(const ThreadTree T) {
  for (ThreadNode *first = FirstNode_pre(T); first != nullptr;
       first = NextNode_pre(first))
    VisitNode(first);
}