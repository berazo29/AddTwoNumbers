#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "main.h"


int main(int argc, char** argv) {
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode *l3 = NULL;

    // Load linked list data structure test
    givenList(&l1,&l2);

    l3 = addTwoNumbers(l1,l2);

    // Format for printing needs to be modified depending the linked list size
    printf("   ");
    printListReverse(l1);
    printf("\n+  ");
    printListReverse(l2);
    printf("\n----------\n ");
    printListReverse(l3);

    freeList(l1);
    freeList(l2);
    freeList(l3);

    return 0;
}

void freeList(struct ListNode *head){

    struct ListNode *ptr = head;

    if (head == NULL){
        return;
    }

    if (head != NULL){
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void reverse(struct ListNode **head){
    struct ListNode* prev = NULL;
    struct ListNode* current = *head;
    struct ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void push(struct ListNode **head, int data){
    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void append(struct ListNode **head, int data){
    assert(data >= 0 && data <= 9);
    struct ListNode *ptr = *head;

    if (ptr == NULL){
        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->data = data;
        new_node->next = *head;
        *head = new_node;
        return;
    }

    struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->data = data;
    new_node->next = NULL;

    struct ListNode *prev;

    while ( ptr != NULL){
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = NULL;
    int carry=0;
    while(l1 != NULL && l2 != NULL){
        if (l2 == NULL){
            break;
        }
        while(l2 != NULL){

            if((l1->data + l2->data + carry) <= 9){
                append(&head, l1->data + l2->data + carry);
                carry=0;
            }else{
                append(&head, ((l1->data + l2->data + carry) % 10));
                carry++;
                if (carry > 1){
                    carry=1;
                }
            }
            break;
        }
        l2 = l2->next;
        l1 = l1->next;
    }
    if (l1 != NULL && l2 == NULL ){
        while (l1 != NULL){
            if((l1->data + carry) <= 9){
                append(&head, l1->data + carry);
                carry=0;
            }else{
                append(&head, ((l1->data + carry) % 10));
                carry++;
                if (carry > 1){
                    carry=1;
                }
            }
            l1 = l1->next;
        }
    }
    if (l2 != NULL && l1 == NULL ){
        while (l2 != NULL){
            if((l2->data + carry) <= 9){
                append(&head, l2->data + carry);
                carry=0;
            }else{
                append(&head, ((l2->data + carry) % 10));
                carry++;
                if (carry > 1){
                    carry=1;
                }
            }
            l2 = l2->next;
        }
    }

    if (carry != 0){
        append(&head, carry);
    }
    return head;
}

void givenList(struct ListNode **l1, struct ListNode **l2){
    append(l1, 5);
    append(l1, 5);
    append(l1, 5);

    append(l2, 5);
    append(l2, 5);
    append(l2, 5);
}

void givenList2(struct ListNode **l1, struct ListNode **l2){
    append(l1, 9);
    append(l1, 9);
    append(l1, 9);
    append(l1, 9);
    append(l1, 9);
    append(l1, 9);
    append(l1, 9);

    append(l2, 9);
    append(l2, 9);
    append(l2, 9);
    append(l2, 9);
}

void givenList3(struct ListNode **l1, struct ListNode **l2){
    append(l1, 2);
    append(l1, 4);
    append(l1, 9);

    append(l2, 5);
    append(l2, 6);
    append(l2, 4);
    append(l2, 9);

}

void printList(struct ListNode *head){
    struct ListNode *ptr = head;
    if (ptr == NULL){
        return;
    }
    while (ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void printListReverse(struct ListNode *head){
    struct ListNode *ptr = head;
    if (ptr == NULL){
        return;
    }
    printListReverse(ptr->next);
    printf("%d ",ptr->data);
}