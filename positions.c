/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_positions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:07:02 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:48:11 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_stack_size(t_node *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

static int	ft_get_max_value(t_node *head)
{
	int	max;

	max = head->value;
	while (head)
	{
		if (head->value > max)
			max = head->value;
		head = head->next;
	}
	return (max);
}

static int	ft_get_next_min_unassigned(t_node *head, int max)
{
	int	min;

	min = max;
	while (head)
	{
		if (head->pos == -1 && head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}

static void	ft_set_position(t_node *head, int value, int pos)
{
	while (head)
	{
		if (head->value == value)
		{
			head->pos = pos;
			break ;
		}
		head = head->next;
	}
}

void	ft_assign_position(t_node *head)
{
	int	size;
	int	max;
	int	pos;
	int	next_min;

	size = ft_get_stack_size(head);
	max = ft_get_max_value(head);
	pos = 0;
	while (pos < size)
	{
		next_min = ft_get_next_min_unassigned(head, max);
		ft_set_position(head, next_min, pos);
		pos++;
	}
}
