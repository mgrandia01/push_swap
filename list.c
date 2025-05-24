/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:07:02 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:47:44 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_printf("Error de memoria \n");
		exit(1);
	}
	(new_node->value) = value;
	(new_node->pos) = -1;
	(new_node->next) = NULL;
	return (new_node);
}

void	ft_append(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = ft_create_node(value);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}

int	ft_size_list(t_node **stack)
{
	int		i;
	t_node	*node;

	i = 0;
	node = (*stack);
	while (node->next != NULL)
	{
		i ++;
		node = node->next;
	}
	return (i);
}

void	ft_free_list(t_node *head)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
