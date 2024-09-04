/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:55:23 by tlegrand          #+#    #+#             */
/*   Updated: 2024/09/04 21:31:41 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_test	*create_node(char *test_name, t_test_func f)
{
	t_test	*new;

	new = malloc(sizeof(t_test));
	if (new == NULL)
		return (NULL); // add error
	bzero(new, sizeof(t_test));
	if (strlcpy(new->name, test_name, NAME_MAX_LENGHT - 1) > NAME_MAX_LENGHT)
		printf("WARN: name too long -> truncated");
	new->id = 1;
	new->function = f;
	return (new);
}

void	append_node(t_test **head, t_test *node)
{
	t_test	*current;

	if (*head == NULL)
		*head = node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		node->id = current->id + 1;
		current->next = node;
	}
}

void	test_loader(t_test **test_list, char *test_name, t_test_func function)
{
	t_test	*new;

	if (test_list == NULL)
		return ;
	new = create_node(test_name, function);
	if (new == NULL)
		return ;
	// add error
	append_node(test_list, new);
}
