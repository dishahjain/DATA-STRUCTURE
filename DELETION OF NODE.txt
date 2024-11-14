#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node* NODE;

NODE get_node() {
    NODE ptr = (NODE)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory not allocated\n");
    }
    return ptr;
}

NODE delete_first(NODE first) {
    NODE temp = first;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    first = first->next;
    free(temp);
    return first;
}

NODE delete_last(NODE first) {
    NODE prev, last;
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }
    prev = NULL;
    last = first;
    while (last->next != NULL) {
        prev = last;
        last = last->next;
    }
    if (prev == NULL) { // Only one node in the list
        free(first);
        return NULL;
    }
    prev->next = NULL;
    free(last);
    return first;
}

NODE delete_value(NODE first, int value_del) {
    if (first == NULL) {
        printf("Linked list is empty\n");
        return NULL;
    }

    NODE prev = NULL;
    NODE current = first;
    while (current != NULL && current->value != value_del) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found\n");
        return first;
    }

    if (prev == NULL) {
        first = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
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
NODE insert_beginning(NODE first, int item) {
    NODE new_node = get_node();
    new_node->value = item;
    new_node->next = first;
    return new_node;
}

int main() {
    NODE head = NULL;
    int choice, item;
    head = insert_beginning(head, 1);
    head = insert_beginning(head, 2);
    head = insert_beginning(head, 3);
    head = insert_beginning(head, 4);


    while (1) {
        printf("1. Delete first\n");
        printf("2. Delete last\n");
        printf("3. Delete value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = delete_first(head);
                break;
            case 2:
                head = delete_last(head);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &item);
                head = delete_value(head, item);
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
