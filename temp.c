#include "push_swap.h"

#include <stdio.h>

void print_stack(t_node *head) 
{
    t_node *current = head;
    
    if (current == NULL) {
        ft_printf("Stack is empty.\n");
        return;
    }
    while (current != NULL) {
        ft_printf("%d -> ", current->nbr);
        current = current->next;
    }
    ft_printf("NULL\n"); // Indicate the end of the stack
}
