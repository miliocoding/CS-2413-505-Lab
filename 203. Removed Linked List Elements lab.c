/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Handle the case where the head node itself contains val
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    // Traverse the list
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next; // Skip the node
            free(temp); // Free memory
        } else {
            current = current->next; // Move forward
        }
    }

    return head;
}

// Helper function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Helper function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Test the function
int main() {
    // Create linked list: 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
    struct ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(6);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(4);
    head->next->next->next->next->next = createNode(5);
    head->next->next->next->next->next->next = createNode(6);

    printf("Original List:\n");
    printList(head);

    int valToRemove = 6;
    head = removeElements(head, valToRemove);

    printf("Updated List after removing %d:\n", valToRemove);
    printList(head);

    return 0;
}
