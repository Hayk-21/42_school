/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsakoyan <hsakoyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:39 by hsakoyan          #+#    #+#             */
/*   Updated: 2021/11/07 20:05:34 by hsakoyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <unistd.h>
# include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef struct Node Node;
struct Node
{
  int data;
  struct Node *next;
};

char	*ft_itoa(int nb);
int           	check_errors_and_push(int argc, char *argv[], Node **root);
int	        ft_atoi(const char *str);
void		sorting(Node **A, Node **B);
void		*ft_strdup(const char *str);
char	        *ft_strtok(char *str, const char *sep);
char	        *ft_strtok_r(char *str, const char *sep, char **lasts);
char	        *ft_strchr(const char *s, int c);
size_t        	ft_strlen(const char *str);
int 		getMid(Node* head);
void          	insert_end(Node ** root, int value);
void          	remove_element(Node **root, int value);
Node* quickSort(Node** headRef);
Node* quickSortRecur(Node* head, Node* end);
Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd);
Node* getTail(Node* cur);
void copyLink(Node** gen_link, Node** copy);
void swapNodes(Node** head_ref, int x, int y);
void rotate(Node** head_ref);
int getCount(Node* head);
void push(Node** head_ref, int new_data);
int isSorted(Node* cur);
Node *getLastList(Node** list, int n);
int getSmallestNum(Node* list);
void rotate_reverse(Node** head_ref);
Node* getParent(Node* node, int val);
int getFirst(Node* node);
void inPlace(Node** A, Node** B);
void ComeBackFirst(Node** A, Node** B, int first);
int getIndex(Node* node, int first);
void    sortList(Node** A, Node** sort);
void    getIndexes(Node** A, Node** sort, Node** id);
long long convert(int n);
void removeData(Node** list);
int get_max(Node* list);
int get_min(Node* list);
void showStacks(Node* A, Node* B);
int can_be_sorted(Node** A);