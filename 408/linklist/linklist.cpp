#include "linklist.h"
#include <iostream>

void Init_10_NodesList(LinkList &L) {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  LNode *tail = new LNode{-114514, nullptr}; // head node
  L = tail;
  for (int i = 0; i < 10; i++) {
    LNode *x = new LNode{a[i], nullptr};
    tail->next = x;
    tail = x;
  }
}

void printList(const LinkList &L) {
  LNode *tmp = L;
  while (tmp != nullptr) {
    std::cout << tmp->data << ' ';
    tmp = tmp->next;
  }
  std::cout << std::endl;
}

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

void reverse(LinkList &L) {
  // 使用头插法进行逆序 思路是先把头指针与链表断开, 之后遍历链表重新进行头插法
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