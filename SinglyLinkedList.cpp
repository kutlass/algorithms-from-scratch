#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * pNext;
} Node;

Node* pHead = NULL;
Node* pTail = NULL;

//
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
// remove(value):
// --------------
//
//     // initialize traversal decals
//     pCurrent  ← pHead
//     pPrevious ← NULL
//     pFound    ← NULL
//
//     // walk the list until we find the node or reach the end
//     while (pFound == NULL AND pCurrent != NULL):
//         if (value == pCurrent.value):
//             pFound ← pCurrent
//         else:
//             pPrevious ← pCurrent
//             pCurrent  ← pCurrent.pNext
//         end if
//     end while
//
//     // perform removal only if a matching node was found
//     if (pFound != NULL):
//
//         // CASE 1: removing the head
//         if (pFound == pHead):
//             pHead ← pHead.pNext
//             // if list becomes empty, repair tail
//             if (pHead == NULL):
//                 pTail ← NULL
//             end if
//
//         else:
//
//             // CASE 2: removing the tail
//             if (pFound == pTail):
//                 pTail ← pPrevious
//                 pTail.pNext ← NULL
//
//             // CASE 3: removing a middle node
//             else:
//                 pPrevious.pNext ← pFound.pNext
//             end if
//
//         end if
//
//         // free the removed node
//         free(pFound)
//
//     end if
void remove_(int value) {

    // Decals (imposters)
    Node* pCurrent  = pHead;
    Node* pPrevious = NULL;

    // Explicit pointer to the found node
    Node* pFound = NULL;

    // Traverse the centipede
    while (NULL == pFound && NULL != pCurrent) {

        if (value == pCurrent->value) {
            pFound = pCurrent;
        } else {
            pPrevious = pCurrent;
            pCurrent  = pCurrent->pNext;
        }
    }

    // Decide what to do based on pFound
    if (NULL != pFound) {

        // CASE 1: Removing the head
        if (pFound == pHead) {
            pHead = pHead->pNext;

            // If list becomes empty, repair tail
            if (NULL == pHead) {
                pTail = NULL;
            }

        } else {

            // CASE 2: Removing the tail
            if (pFound == pTail) {
                pTail = pPrevious;
                pTail->pNext = NULL;

            } else {

                // CASE 3: Removing a middle node
                pPrevious->pNext = pFound->pNext;
            }
        }

        // Free the node after all rewiring
        free(pFound);
    }

    // If pFound == NULL, nothing happens (target not found)
}

//
// bool search(value):
// -------------------
//
//     // initialize traversal decals
//     pCurrent ← pHead
//     fFound   ← false
//
//     // walk the list until we find the value or reach the end
//     while (pCurrent != NULL AND fFound == false):
//         if (value == pCurrent.value):
//             fFound ← true
//         end if
//         pCurrent ← pCurrent.pNext
//     end while
//
//     // report whether the value was found
//     return fFound
bool search(int value) {
    // Initialize traversal decals
    Node* pCurrent = pHead;
    bool fFound    = false;

    // Walk the list until we find the value or reach the end
    while (NULL != pCurrent && false == fFound) {
        if (value == pCurrent->value) {
            fFound = true;
        }

        // Shift traversal cursor
        pCurrent = pCurrent->pNext;
    }
    return fFound;
}

//
// printList():
// ------------
//
//     pCurrent ← pHead
//
//     while pCurrent ≠ NULL:
//         print pCurrent.value
//         pCurrent ← pCurrent.pNext
//
//     print "NULL"
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
    const int SEARCH_NUMBER = 69;
    append(SEARCH_NUMBER);
    prepend(5);

    printList();

    if ( true == search(SEARCH_NUMBER) ) {
        printf("search() found %d\n", SEARCH_NUMBER);
    } else {
        printf("search() found %d\n", SEARCH_NUMBER);
    }

    remove_(69);

    printList();
    if ( true == search(SEARCH_NUMBER) ) {
        printf("search() found %d\n", SEARCH_NUMBER);
    } else {
        printf("search() did NOT find %d\n", SEARCH_NUMBER);
    }

    return 0;
}
