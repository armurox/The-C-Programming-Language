#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct Node {
    int val;
    struct Node *next;
} Node;

Node *create_node(int val);
Node *add_node(Node **head, int val);
// void cleanup_list(Node **head);
void print_linked_list(Node *head);
// void print_reversed_linked_list(Node *head);
// void reverse_linked_list(Node **head);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage ./linked [INTEGERS]\n");
        return 1;
    }

    Node *head = NULL;
    for (int i = 1; i < argc; i++)
    {
        if (add_node(&head, atoi(argv[i])) == NULL)
        {
            // cleanup_list(&head);
            printf("Error! Ran out of memory!");
            return 2;
        }

    }

    printf("Non reversed list is: ");
    print_linked_list(head);
    // printf("Reversed linked list is: ");
    // print_reversed_linked_list(head);
    // printf("Actually reversing linked list now...");
    // reverse_linked_list(&head);
    // print_linked_list(head);
    // cleanup_list(&head);
}


Node *create_node(int val)
{
    Node *temp_node = malloc(sizeof(Node));
    if (temp_node == NULL)
        return temp_node;
    temp_node -> val = val;
    temp_node -> next = NULL;
    return temp_node;
}

Node *add_node(Node **head, int val)
{
    Node *temp_node = create_node(val);
    if (temp_node == NULL)
        return temp_node;
    temp_node -> next = *head;
    *head = temp_node;
    return temp_node;
}


void print_linked_list(Node *head)
{
    for (Node *curr = head; curr != NULL; curr = curr -> next)
    {
        printf("%d ", curr -> val);
    }
    printf("\n");
}
