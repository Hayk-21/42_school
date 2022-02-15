/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakoyan <hsakoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 18:05:33 by hsakoyan          #+#    #+#             */
/*   Updated: 2021/11/07 20:10:37 by hsakoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count = 0;

int isSorted(Node* cur)
{
    while (cur != NULL && cur->next != NULL)
    {
        if(cur->data < cur->next->data)
            cur = cur->next;
        else
            return (0);
    }
    return 1;
}

int check_errors_and_push(int argc, char *argv[], Node **root)
{
    int digit;
    
    for (int i = 1; i < argc; i++)
    {
        char * token = ft_strtok(argv[i], " ");
        while( token != NULL ) {
            if((*token <= 57 && *token >= 48) || *token == 45)
            {
                digit = atoi(token);
                insert_end(root, digit);
            }
            else
            {
                printf("Error\n");
                return(0);
            }
            token = ft_strtok(NULL, " ");
        }
    }
    return(0);
}
void    sortList(Node** A, Node** sort)
{
    copyLink(A, sort);
    quickSort(sort);
}

void    ReverseList(Node** A, Node** rList)
{
    Node* a = NULL;
    copyLink(A, &a);
        
    for (Node* s = a; s != NULL; s = s->next)
        push(rList, s->data);
}

void    getIndexes(Node** A, Node** sort, Node** id)
{
    for (Node* a = *A; a != NULL; a = a->next)
    {
        int i = 0;
        for (Node* s = *sort; s != NULL; s = s->next)
        {
            if (a->data == s->data)
            {
                insert_end(id, i);
                break;
            }    
            i++;
        }
    }
}

long long convert(int n)
{
  long long bin = 0;
  int rem, i = 1;

  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }

  return bin;
}

Node* makeBin(Node* id)
{
    Node* new = NULL;

    for (Node* curr = id; curr != NULL; curr = curr->next)
        insert_end(&new, convert(curr->data));

    return new;
}

void sort_small_stack(Node** A)
{
    Node* B = NULL;
    int digit;

    while (!isSorted(*A))
    {
        if ((*A)->data > (*A)->next->data)
        {
            swapNodes(A, (*A)->data, (*A)->next->data);
            printf("sa\n");
        }
        else if((*A)->data > getTail(*A)->data)
        {
            printf("rra\n");
            rotate_reverse(A);
        }
        else
        {
            digit = (*A)->data;
            push(&B, digit);
            remove_element(A, digit);
            printf("pb\n");
        }
    }
    if(isSorted(*A) && B == NULL)
        return;
    else
    {
        while (B != NULL)
        {
            printf("pa\n");
            digit = B->data;
            push(A, digit);
            remove_element(&B, digit);
        }
        sort_small_stack(A);
    }
}

int get_i(Node** A, Node* chunk)
{
    int i = 0;
    Node* a = NULL;
    copyLink(A, &a);

    while (i <= getCount(*A)/2)
    {
        for (Node* curr = chunk; curr != NULL; curr = curr->next)
            if(curr->data == a->data)
                return i;
        i++;
        a = a->next;
    }

    return (-1);
}

int get_j(Node** A, Node* chunk)
{
    int j = 1;
    Node* a = NULL;
    copyLink(A, &a);

    while (j <= getCount(*A)/2 + 1)
    {
        for (Node* curr = chunk; curr != NULL; curr = curr->next)
        {
            if(curr->data == getTail(a)->data)
                return j;
        }
        j++;
        remove_element(&a, getTail(a)->data);
    }

    return (-1);
}
void red () 
{
    printf("\033[1;31m");
}

void yellow() 
{
    printf("\033[1;33m");
}

void reset () 
{
    printf("\033[0m");
}

void find_closest_and_push(Node* chunk, Node** A, Node** B, int  stack)
{
    int c = 0;
    while(c < getCount(chunk))
    {

        // for (Node* curr = chunk; curr != NULL; curr = curr->next)
        //     printf("ch: %d\n", curr->data);

        // for (Node* curr = *A; curr != NULL; curr = curr->next)
        //     printf("A: %d\n", curr->data);

        int i = get_i(A, chunk);
        int j = get_j(A, chunk);
        // printf("i: %d\t\t j: %d\n", i, j);
        if((i == -1 && j != -1) || ((i != -1 && j != -1) && (j < i)))
        {
            //rra
            int k = 0;
            if(getCount(*A) != 1)
            {
                while(k < j)
                {
                    printf("rra\n");
                    rotate_reverse(A);
                    k++;
                    count++;
                }
            }    
        }
        else if((i != -1 && j ==-1) || ((i != -1 && j != -1) && (i < j)) || ((i != -1 && j != -1) && i == j))
        {
            //ra
            int k = 0;
            if(getCount(*A) != 1)
            {
                while(k < i)
                {
                    count++;
                    printf("ra\n");
                    rotate(A);
                    k++;
                }
            }
        }
        else
            return;
        
        int elem;
        
        count++;
        elem = (*A)->data;
        remove_element(A, elem);
        push(B, elem);
        c++;
        if(stack)
        {
            printf("pa\n");
            // showStacks(*B, *A);
            // can_be_sorted(A);
        }
        else
        {
            printf("pb\n");
            // showStacks(*A, *B);
        }
    }
}

int get_max(Node* list)
{
    int max = 0;
    
    for (Node* curr = list; curr != NULL; curr = curr->next)
    {
        if (max < curr->data)
            max = curr->data;
    }
    return (max);
}

int get_min(Node* list)
{
    int min = get_max(list);
    
    for (Node* curr = list; curr != NULL; curr = curr->next)
    {
        if (min > curr->data)
            min = curr->data;
    }
    return (min);
}

void get_max_and_push(Node** A, Node** B)
{
    Node* x = NULL;
    int max;
    
    while ((*B) != NULL)
    {
        max = get_max(*B);
        push(&x, max);
        find_closest_and_push(x, B, A, 1);
        // for (Node* curr = *B; curr != NULL; curr = curr->next)
        // { 
        //     printf("B: %d\n", curr->data);
        // }
        remove_element(&x, max);
    }
}

void sort_big_stack(Node** A, Node* sort, Node** B)
{
    int n;

    if (getCount(*A) <= 100)
        n = 5;
    else
        n = 11;

    Node* chunk = NULL;
    int i = 0;
    int len = getCount(*A) / n;
    Node* curr = sort;

    while (curr != NULL)
    {
        while (i < len)
        {
            if(curr != NULL)
            {
                insert_end(&chunk, curr->data);
                curr = curr->next;
            }
            i++;
        }
        find_closest_and_push(chunk, A, B, 0);
        i = 0;
        removeData(&chunk);
        if (can_be_sorted(A) == 1)
            break;
        // printf("sort:%d\t\t A:%d\t\t len:%d\n", curr->data, a->data, len);
    }


    //SECOND PARTH
    get_max_and_push(A, B);
}

void showStacks(Node* A, Node* B)
{
    int lenA = getCount(A);
    int lenB = getCount(B);
    int len;
    if(lenA > lenB)
        len = lenA;
    else
        len = lenB;
    int i = 0;
    Node* a = A;
    Node* b = B;
    while (i < len)
    {
        if(a != NULL)
        {
            printf("A: %d\t  |\t", a->data);
            a = a->next;
        }
        else
        {
            printf("A:\t  |\t");
        }
        if(b != NULL)
        {
            printf("B: %d\n", b->data);
            b = b->next;
        }
        else
        {
            printf("B:\n");
        }
        i++;
    }
    printf("\n");
}
int can_be_sorted(Node** A)
{
    int min = get_min(*A);
    int start = min;
    Node* curr = *A;
    while (curr != NULL)
    {
        if (curr->data == min)
        {
            curr = curr->next;
            min++;
            while (curr != NULL)
            {
                if(curr == NULL || curr->data != min)
                {
                    // printf("NO\n");
                    return (0);
                }
                else
                {
                    curr = curr->next;
                    min++;
                }
            }
            curr = *A;
            while (curr->data != start)
            {
                if(curr->data != min)
                {
                    // printf("NO\n");
                    return (0);
                }
                min++;
                curr = curr->next;                   
            }
            // printf("YES sorted\n");
            curr = *A;
            while (curr->data > getTail(*A)->data)
            {
                rotate(A);
                printf("ra\n");
                curr = *A;
            }
            return (1);
        }
        else
            curr = curr->next;
    }
    return (0);
}

int main(int argc, char *argv[])
{
    Node* A = NULL;
    Node* id = NULL;
    Node* sort = NULL;
    // Node* B = NULL;
    Node* sortId = NULL;

    check_errors_and_push(argc, argv, &A);
    // for (Node* curr = A; curr != NULL; curr = curr->next)
    // { 
    //     printf("A: %d\n", curr->data);
    // }

    //SORTING
    // printf("\n\tSorting...\n");
    sortList(&A, &sort);

    //GET INDEXES
    getIndexes(&A, &sort, &id);
    // printf("\t#IDS\n");
    // for (Node* curr = id; curr != NULL; curr = curr->next)
    //     printf("id: %d\n", curr->data);
    sortList(&id, &sortId);
        sort_small_stack(&id);

    // if (getCount(A) <= 5 && !can_be_sorted(&id))
    //     sort_small_stack(&id);
    // else if (getCount(A) > 5 && !can_be_sorted(&id))
    //     sort_big_stack(&id, sortId, &B);
    
    // //MAKE BINARY NODE
    // // id = makeBin(id);
    // // printf("\t#CONVERT IDS\n");
    // showStacks(id, B);
    return (1);
}
