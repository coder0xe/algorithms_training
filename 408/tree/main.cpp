#include "thread_tree.h"
#include <iostream>

int main() {
  ThreadTree T = nullptr;
  InitTheadTree(T);
  CreatePosThread(T);
  ThreadPosOrder(T);
  std::cout << std::endl;
  return 0;
}