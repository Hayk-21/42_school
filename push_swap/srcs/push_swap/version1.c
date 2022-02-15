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

Node* sort_id = NULL;
int CicleCount = 1;

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

int getFirst(Node* node)
{
    if(node == NULL)
        return 0;

    int min = node->data;

    while (node->next != NULL)
    {
        if(min > node->next->data)
            min = node->next->data;
        node = node->next;
    }
    return min;
}

int getIndex(Node* node, int first)
{
    int index = 0;

    while (node != NULL)
    {
        if(node->data == first)
            return index;
        index++;
        node = node->next;
    }
    return index;
}

void inPlace(Node** A, Node** B)
{
    int first = getFirst(*A);
    if (first == (*A)->data)//Is first in place?
    {//YES
        //PUSH B
        printf("pb\n");
        push(B, first);
        remove_element(A, first);
        inPlace(A, B);
    }
    else
    {//NO
        ComeBackFirst(A, B, first);
    }
}

void ComeBackFirst(Node** A, Node** B, int first)
{
    int index = getIndex(*A, first);
    int length = getCount(*A);
    int i = index;
    int j = length - index;
    if (i < j)
    {
        int k = 0;
        while (k < i)
        {//ra
            printf("ra\n");
            rotate(A);
            k++;
        }
    }
    else
    {
        int k = 0;
        while (k < j)
        {//rra
            printf("rra\n");
            rotate_reverse(A);
            k++;
        }
    }
    sorting(A, B);
}

void collectList(Node** A, Node** B)
{
    while (*B != NULL)
    {
        printf("pa\n");
        push(A, (*B)->data);
        remove_element(B, (*B)->data);
    }
}

void sorting(Node **A, Node **B)
{
    if(isSorted(*A))//Is list sorted?
        collectList(A, B);//YES
    else
        inPlace(A, B);//NO
}

int main(int argc, char *argv[])
{
    Node* A = NULL;
    Node* B = NULL;

    check_errors_and_push(argc, argv, &A);
    // for (Node* curr = A; curr != NULL; curr = curr->next)
    // {
    //     printf("A: %d\n", curr->data);
    // }
    // printf("\tSorting...\n");

    sorting(&A, &B);
    // printf("\tEND...\n\t#A\n");
    // for (Node* curr = A; curr != NULL; curr = curr->next)
    //     printf("A: %d\n", curr->data);

    // printf("\t#B\n");
    
    // for (Node* curr = B; curr != NULL; curr = curr->next)
    // {
    //     printf("B: %d\n", curr->data);
    // }
    
    return (1);
}
