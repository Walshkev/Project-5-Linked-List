// #include <stddef.h>
#include "llist.h"
#include <stdlib.h>

#include <stdio.h>
// #include <unistd.h>
#include <string.h>

struct node *node_alloc(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
    printf("%d", newNode->value);
}

void node_free(struct node *n)
{
    free(n);
}

void llist_insert_head(struct node **head, struct node *n)
{
    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        n->next = *head;
        *head = n;
    }
}

struct node *llist_delete_head(struct node **head)
{
    if (*head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp = *head;
        *head = (*head)->next;
        temp->next = NULL;
    }
    return 0;
}

void llist_insert_tail(struct node **head, struct node *n)
{
    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        struct node *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = n;
    }
}
// p

void llist_print(struct node *head)
{
    if (head == NULL)
    {
        printf("[empty] \n");
    }
    else
    {
        struct node *current = head;
        while (current != NULL)
        {
            printf("%d", current->value);
            if (current->next != NULL)
            {
                printf(" -> ");
            }
            current = current->next;
        }
        printf("\n");
    }
}
// f
void llist_free(struct node **head)
{
    if (head != NULL)
    {

        struct node *current = *head;
        struct node *temp; 

        while (current != NULL)
        {

            temp = current;

            // consider what is wrong with the order of these operations
            current = temp->next;
            node_free(temp);
        }
        
        *head = NULL;
    };
}
int main(int argc, char *argv[])
{
    struct node *head = NULL;
    // struct node **head = &head;
    // llist_delete_head(&head);

    for (int i = 1; i < argc; i++)
    {
        // int value = atoi(argv[i + 1]);

        // struct node *newnode = node_alloc(value);
        if (strcmp(argv[i], "ih") == 0)
        {
            struct node *newnode = node_alloc(atoi(argv[i + 1]));
            llist_insert_head(&head, newnode);

            i++;
        }
        else if (strcmp(argv[i], "it") == 0)
        {
            struct node *newnode = node_alloc(atoi(argv[i + 1]));
            llist_insert_tail(&head, newnode);
            i++;
        }
        else if (strcmp(argv[i], "dh") == 0)
        {

            llist_delete_head(&head);
        }
        if (strcmp(argv[i], "f") == 0)
        {
            llist_free(&head);
        }
        if (strcmp(argv[i], "p") == 0)
        {
            llist_print(head);
        }
        else
        {
            continue;
        }
    }
}
