#include "push_swap.h"

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

void print_string_array(char **array)
{
    if (array == NULL)
    {
        ft_printf("Array is NULL\n");
        return;
    }

    for (int i = 0; array[i] != NULL; i++)
    {
        ft_printf("%s\n", array[i]);
    }
}
