#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * pNext;
} Node;

Node* pHead = NULL;
Node* pTail = NULL;

// append(value):
// ---------------
//
//     newTail ← allocate new node
//     newTail.value ← value
//     newTail.pNext ← NULL
//
//     if Head = NULL:
//         // List is empty; apply the "only one node" invariant
//         Head ← newTail
//         Tail ← newTail
//     else:
//         // List is not empty
//         oldTail ← Tail
//         oldTail.pNext ← newTail
//         Tail ← newTail
//
void append(int value) {
    // New node is created regardless of
    // whether list is empty or not
    Node* pNewNode = malloc(sizeof(Node));
    pNewNode->value = value;
    pNewNode->pNext = NULL;

    // Determine where the new node should live
    if (pHead == NULL) {
        // Linked list is empty
        pHead = pNewNode;  // So I am the head
        pTail = pNewNode;  // and I am also the tail!
    } else {
        // Linked list is not empty
        pTail->pNext = pNewNode; // Attach new node to old tail
        pTail = pNewNode;        // Update old tail
    }
}

//
// prepend(value):
// ---------------
//     oldHead ← Head
//
//     newHead ← allocate new node
//     newHead.value ← value
//     newHead.pNext ← oldHead
//
//     Head ← newHead
//
//     if Tail = NULL:
//         Tail ← newHead
//
void prepend(int value) {
    // Take note of old head
    Node* pOldHead = pHead;

    // Allocate new node
    Node* pNewHead = malloc(sizeof(Node));
    pNewHead->value = value;
    pNewHead->pNext = pOldHead;

    // Make our new head official
    pHead = pNewHead;

    // If no tail exists, the list is empty
    if (NULL == pTail) {
        // Apply the "only one node in list" invariant
        pTail = pNewHead;
    }
}

//
// printList():
// ------------
//
//     current ← Head
//
//     while current ≠ NULL:
//         print current.value
//         current ← current.pNext
//
//     print "NULL"
//
void printList() {
    Node* pCurrent = pHead;

    while (NULL != pCurrent) {
        printf("Node value: %d\n", pCurrent->value);

        // Shift cursor
        pCurrent = pCurrent->pNext;
    }

    printf("NULL\n");
}

int main(void) {
    printf("Hello, World!\n");

    append(10);
    append(20);
    prepend(5);
    printList();

    return 0;
}
