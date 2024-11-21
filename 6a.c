6b
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node *NODE;

// Function to allocate memory for a new node
NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        exit(1);  // Exit the program if memory allocation fails
    }
    return ptr;
}

// Function to delete the first node (for stack pop or queue dequeue)
NODE delete_first(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    first = first->next;
    free(temp);  // Free the memory of the node that was deleted
    return first;
}

// Function to insert a new node at the beginning (for stack push)
NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node;
}

// Function to insert a new node at the end (for queue enqueue)
NODE insert_end(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = NULL;
    if (first == NULL) {
        return new_node;
    }
    NODE temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return first;
}

// Function to display the list
void display(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free the entire list (for memory cleanup)
void free_list(NODE first) {
    NODE temp;
    while (first != NULL) {
        temp = first;
        first = first->next;
        free(temp);  // Free each node
    }
}

int main() {
    int item, choice, deleted_item;
    NODE first = NULL;

    printf("Choose:\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("Enter choice (1/2): ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;  // Exit if the choice is invalid
    }

    if (choice == 1) {  // Stack Operations
        while (1) {
            printf("\nStack Operations:\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display stack\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input.\n");
                continue;  // Skip to the next iteration on invalid input
            }

            switch (choice) {
                case 1:  // Push operation
                    printf("Enter item to push: ");
                    if (scanf("%d", &item) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    first = insert_beginning(first, item);
                    break;

                case 2:  // Pop operation
                    if (first != NULL) {
                        deleted_item = first->value;
                        first = delete_first(first);
                        printf("Deleted item from stack: %d\n", deleted_item);
                    } else {
                        printf("Stack is empty\n");
                    }
                    break;

                case 3:  // Display stack
                    printf("Stack: ");
                    display(first);
                    break;

                case 4:  // Exit
                    free_list(first);  // Free the entire list before exit
                    exit(0);

                default:
                    printf("Invalid choice.\n");
            }
        }
    } else if (choice == 2) {  // Queue Operations
        while (1) {
            printf("\nQueue Operations:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display queue\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            if (scanf("%d", &choice) != 1) {
                printf("Invalid input.\n");
                continue;  // Skip to the next iteration on invalid input
            }

            switch (choice) {
                case 1:  // Enqueue operation
                    printf("Enter item to insert: ");
                    if (scanf("%d", &item) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    first = insert_end(first, item);
                    break;

                case 2:  // Dequeue operation
                    if (first != NULL) {
                        deleted_item = first->value;
                        first = delete_first(first);
                        printf("Deleted item from queue: %d\n", deleted_item);
                    } else {
                        printf("Queue is empty!\n");
                    }
                    break;

                case 3:  // Display queue
                    printf("Queue: ");
                    display(first);
                    break;

                case 4:  // Exit
                    free_list(first);  // Free the entire list before exit
                    exit(0);

                default:
                    printf("Invalid choice.\n");
            }
        }
    } else {
        printf("Invalid operation.\n");
    }

    return 0;
}
