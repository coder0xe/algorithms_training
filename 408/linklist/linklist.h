// this file is a definition of a linked list
#ifndef LINKLIST_H
#define LINKLIST_H

// 单链表
typedef struct LNode {
  int data;
  struct LNode *next;
} LNode, *LinkList;

void Init_10_NodesList(LinkList &L);
void printList(const LinkList &L);
void delete_x(LinkList &L, int x);
void del_min(LinkList &L);
void reverse(LinkList &L);
void _reverse(LinkList &L);

// 双链表
typedef struct DNode {
  int data;
  struct DNode *prior, *next;
} DNode, *DLinkList;

#endif