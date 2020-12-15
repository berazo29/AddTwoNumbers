//
// Created by Bryan Erazo on 12/12/20.
//

#ifndef CTESTING_MAIN_H
#define CTESTING_MAIN_H

// LinkedList Data Structure
struct ListNode{
    int data;
    struct ListNode *next;
};

// Linked List Operations
void reverse(struct ListNode **head);
void push(struct ListNode **head, int data);
void append(struct ListNode **head, int data);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
void printListReverse(struct ListNode *head);
void freeList(struct ListNode *head);

// TEST
void givenList(struct ListNode **l1, struct ListNode **l2);
void givenList2(struct ListNode **l1, struct ListNode **l2);
void givenList3(struct ListNode **l1, struct ListNode **l2);

#endif //CTESTING_MAIN_H
