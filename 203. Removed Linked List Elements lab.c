/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {

    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }

    
    struct ListNode* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next; 
            free(temp); 
        } else {
            current = current->next; 
        }
    }

    return head;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
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
