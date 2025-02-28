#include "linklist.h"
#include <cstddef>
#include <cstdlib>

void delete_x(LinkList &L, int x) {
  LNode *a = L;
  while (a->next != NULL) {
    if (a->next->data == x) {
      LNode *tmp = a->next;
      a->next = a->next->next;
      free(tmp);
    } else
      a = a->next;
  }
}

int main() {
  LinkList L;
  Init_10_NodesList(L);
  printList(L);
  delete_x(L, 4);
  printList(L);
}