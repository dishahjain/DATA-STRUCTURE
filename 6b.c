6a
include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};
typedef struct node *NODE;

NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    }
    return ptr;
}

NODE delete_first(NODE first){
    NODE temp=first;
    if (first == NULL) {
        printf("Empty\n");
        return NULL;
    }
    first=first->next;
    free(temp);
    return first;
}

NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node;
}

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

int main() {
    int item, choice, deleted_item;
    NODE first = NULL;

    printf("Choose:\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("Enter choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        while (1) {
            printf("\nStack Operations:\n");
            printf("1. Push\n");
            printf("2. Pop\n");
            printf("3. Display stack\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter item to push: ");
                    scanf("%d", &item);
                    first = insert_beginning(first, item);
                    break;
                case 2:
                    if (first != NULL) {
                        deleted_item = first->value;
                        first = delete_first(first);
                        printf("Deleted item from stack: %d\n", deleted_item);
                    } else {
                        printf("Stack is empty\n");
                    }
                    break;
                case 3:
                    printf("Stack: ");
                    display(first);
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choice.\n");
            }
        }
    }
    else if (choice == 2) {
        while (1) {
            printf("\nQueue Operations:\n");
            printf("1. Insert\n");
            printf("2. Delete\n");
            printf("3. Display queue\n");
            printf("4. Exit\n");
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter item to insert: ");
                    scanf("%d", &item);
                    first = insert_end(first, item);
                    break;
                case 2:
                    if (first != NULL) {
                        deleted_item = first->value;
                        first = delete_first(first);
                        printf("Deleted item from queue: %d\n", deleted_item);
                    } else {
                        printf("Queue is empty!\n");
                    }
                    break;
                case 3:
                    printf("Queue: ");
                    display(first);
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Invalid choice.\n");
            }
        }
    }
    else {
        printf("Invalid operation.\n");
    }

    return 0;
    }