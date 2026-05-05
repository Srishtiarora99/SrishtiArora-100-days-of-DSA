/*Problem: Find Intersection Point of Two Linked Lists - Implement using
linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. 
First common node is intersection.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Helper to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to get length of linked list
int getLength(struct Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

void findIntersection(struct Node* head1, struct Node* head2) {
    int n = getLength(head1);
    int m = getLength(head2);
    
    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Advance the pointer of the longer list
    if (n > m) {
        for (int i = 0; i < (n - m); i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < (m - n); i++) ptr2 = ptr2->next;
    }

    // Traverse both simultaneously
    while (ptr1 && ptr2) {
        if (ptr1->data == ptr2->data) {
            printf("%d\n", ptr1->data);
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("No Intersection\n");
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    // Input List 1
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head1) head1 = tail1 = temp;
        else { tail1->next = temp; tail1 = temp; }
    }

    // Input List 2
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        struct Node* temp = newNode(val);
        if (!head2) head2 = tail2 = temp;
        else { tail2->next = temp; tail2 = temp; }
    }

    findIntersection(head1, head2);

    return 0;
}