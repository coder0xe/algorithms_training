#include "linklist.h"
#include <cstddef>
#include <cstdlib>

void del_min(LinkList &L) {
  LNode *pre_flag = NULL, *flag = NULL, *pre_now = L, *now = L->next;
  int min = 0x7fffffff;
  while (now != NULL) {
    if (now->data < min) {
      flag = now;
      pre_flag = pre_now;
      min = now->data;
    }
    pre_now = now;
    now = now->next;
  }
  pre_flag->next = flag->next;
  free(flag);
}

int main() {
  LinkList L;
  Init_10_NodesList(L);
  printList(L);
  del_min(L);
  printList(L);
  return 0;
}