#include "linklist.h"
#include <cstddef>

void reverse(LinkList &L) {
  // 使用头插法进行逆序 思路是先把头指针与链表断开,之后遍历链表重新进行头插法
  LNode *p = L->next, *r = NULL;
  L->next = NULL;
  while (p != NULL) {
    r = p->next;
    p->next = L->next;
    L->next = p;
    p = r;
  }
}

void _reverse(LinkList &L) {
  // 这个解法的思路是将指针反向
  LNode *now = L->next, *pre_now = L, *post_now = now->next;
  pre_now = NULL;
  while (now != NULL) {
    now->next = pre_now;
    pre_now = now;
    now = post_now;
    post_now = (!post_now) ? NULL : post_now->next;
  }
  L->next = pre_now;
}

int main() {
  LinkList L;
  Init_10_NodesList(L);
  printList(L);
  reverse(L);
  _reverse(L);
  printList(L);
  return 0;
}