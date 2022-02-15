#include "push_swap.h"

void swapNodes(Node** head_ref, int x, int y)
{
    if (x == y)
        return;
 
    // Search for x (keep track of prevX and CurrX
    Node *prevX = NULL, *currX = *head_ref;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }
 
    // Search for y (keep track of prevY and CurrY
    Node *prevY = NULL, *currY = *head_ref;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }
 
    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;
 
    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        *head_ref = currY;
 
    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        *head_ref = currX;
 
    // Swap next pointers
    Node* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

void insert_end(Node ** root, int value)
{
    Node * new_node = malloc(sizeof(Node));
    if (new_node == NULL)
        exit(1);
    new_node->next = NULL;
    new_node->data = value;

    if(*root == NULL)
    {
        *root = new_node;
        return;
    }

    Node* curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next =  new_node;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
  
    (*head_ref)    = new_node;
}

void remove_element(Node **root, int value)
{

    struct Node *temp = *root, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == value) {
        *root = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    free(temp); // Free memory
}

void copyLink(Node** gen_link, Node** copy)
{
    for (Node* curr = *gen_link; curr != NULL; curr = curr->next)
        insert_end(copy, curr->data);
}

void rotate(Node** head_ref)
{
    if(head_ref == NULL)
        return;

    int digit;
    digit = (*head_ref)->data;
    // printf("Rotated :%d\n", digit);
    insert_end(head_ref, digit);
    remove_element(head_ref, digit);
    // for (Node* curr = *head_ref; curr != NULL; curr = curr->next)
    //     printf("List: %d\n", curr->data);
    
    return;
}
void rotate_reverse(Node** head_ref)
{
    if(head_ref == NULL)
        return;

    int digit;
    digit = getTail(*head_ref)->data;
    // printf("Rotated reverse:%d\n", digit);
    remove_element(head_ref, digit);
    push(head_ref, digit);
    // for (Node* curr = *head_ref; curr != NULL; curr = curr->next)
    //     printf("List: %d\n", curr->data);
    
    return;
}

void removeData(Node** list)
{
    Node** curr = list;
    int to_rem;

    while ((*curr) != NULL)
    {
        to_rem = (*curr)->data;
        *curr = (*curr)->next;
        remove_element(curr, to_rem);
    }
}

int getCount(Node* head)
{
    int count = 0;  // Initialize count
    Node* current = head;  // Initialize current
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

int getMid(Node* head)
{
    Node *slow_ptr = head;
    Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        return (slow_ptr->data);
    }
    return (0);
}

Node *getLastList(Node** list, int n)
{
    Node* newList = NULL;
    int i = 0;
    while (i < n)
    {
        insert_end(&newList, (*list)->data);
        i++;
        *list = (*list)->next;
    }

    for (Node* curr = newList; curr != NULL; curr = curr->next)
        printf("LastList: %d\n", curr->data);

    return newList;
}

int getSmallestNum(Node* list)
{
    int n = list->data;
    Node *ptr = list;
 
    if (list!=NULL)
    {
        while (ptr != NULL)
        {
            printf("ptr: %d\n", ptr->data);
            if (n > ptr->data)
                n = ptr->data;
            ptr = ptr->next;
        }
    }
    return (n);
}

Node* getParent(Node* node, int val)
{
    while (node->data != val && node != NULL && node->next != NULL)
    {
        if (node->next->data == val)
            return node;
        node = node->next;
    }
    return node;
}
