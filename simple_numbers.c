/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:56:45 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:31:19 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_numbers(t_node **stack, int i)
{
	t_node	*current;

	while (!ft_is_sorted(*stack))
	{
		current = *stack;
		if (current->pos == 2 + i)
			ft_simple_rotate(stack);
		else if (current->pos == 0 + i && current->next->pos == 2 + i)
			ft_swap(stack, 'a');
		else if (current->pos == 1 + i && current->next->pos == 0 + i)
			ft_swap(stack, 'a');
		else if (current->pos == 1 + i && current->next->pos == 2 + i)
			ft_revers_rotate(stack);
	}
}

static void	ft_find_min(t_node **stack_a)
{
	t_node	*current;
	int		min;
	int		pos;
	int		i;

	current = *stack_a;
	min = current->pos;
	pos = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->pos < min)
		{
			min = current->pos;
			pos = i;
		}
		current = current -> next;
		i ++;
	}
	current = *stack_a;
	while (pos > 0)
	{
		ft_simple_rotate(stack_a);
		pos --;
	}
}

void	ft_four_numbers(t_node **stack_a, t_node **stack_b)
{
	ft_find_min(stack_a);
	ft_push_simple(stack_a, stack_b, 'b');
	ft_three_numbers(stack_a, 1);
	ft_push_simple(stack_b, stack_a, 'a');
}

void	ft_five_numbers(t_node **stack_a, t_node **stack_b)
{
	ft_find_min(stack_a);
	ft_push_simple(stack_a, stack_b, 'b');
	ft_find_min(stack_a);
	ft_push_simple(stack_a, stack_b, 'b');
	ft_three_numbers(stack_a, 2);
	if (ft_is_sorted(*stack_b))
		ft_swap(stack_b, 'b');
	ft_push_simple(stack_b, stack_a, 'a');
	ft_push_simple(stack_b, stack_a, 'a');
}
