#include "libunit.h"

t_test  create_node(char* test_name, t_test_func f)
{
    t_test* new;

    new = malloc(sizeof(t_test));
    if (new == NULL)
        return(NULL); // add error 
    bzero(new, sizeof(t_test));
    if (strlcpy(new->name, test_name, NAME_MAX_LENGHT - 1) > NAME_MAX_LENGHT)
        printf("WARN: name too long -> truncated");
    new->id = 1;
    new->function = f;
    return (new)
}

void    append_node(t_test** head, t_test* node)
{
    if (*head == NULL)
        *head = new;
    else
    {
        t_list* current = *head;
        while (*current->next)
            current = current->next;
        new->id = current->id + 1;
        current->next = new;
    }
}

void    test_loader(t_test** test_list, char* test_name, t_test_func function)
{
    if (test_list == NULL)
        return ;
    t_test* new = create_node(test_name, function);
    if (new == NULL)
        return ; //add error
    append_node(test_list, new);

};