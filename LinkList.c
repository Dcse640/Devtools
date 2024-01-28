#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to print the elements of the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);  // Exit with an error code
    }

    newNode->data = newData;
    newNode->next = head;

    return newNode;
}

// Function to delete a node with a specified value from the linked list
struct Node* deleteNode(struct Node* head, int key) {
    struct Node* current = head;
    struct Node* prev = NULL;

    // Search for the node with the specified value
    while (current != NULL && current->data != key) {
        prev = current;
        current = current->next;
    }

    // If the node is found, remove it
    if (current != NULL) {
        // If the node is the first node
        if (prev == NULL) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        // Free the memory of the deleted node
        free(current);
    }

    return head;
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    // Print the linked list
    printf("Linked List (Before Deletion): ");
    printList(head);

    // Delete a node with value 2
    head = deleteNode(head, 2);

    // Print the linked list after deletion
    printf("Linked List (After Deletion): ");
    printList(head);

    // Free allocated memory (you should free the entire list in a real-world scenario)
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
