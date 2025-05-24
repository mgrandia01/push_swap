/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:03:50 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:52:45 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_simple(t_node **from, t_node **to, char c)
{
	t_node	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	if (c == 'a')
		ft_printf("pa\n");
	else
		ft_printf("pb\n");
}

void	ft_simple_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	last = (*stack);
	while (last->next != NULL)
	{
		last = last->next;
	}
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

void	ft_swap(t_node **stack, char c)
{
	t_node	*first;
	t_node	*second;
	t_node	*rest_of_list;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	first = (*stack);
	second = (*stack)-> next;
	rest_of_list = second->next;
	*stack = first->next;
	second->next = first;
	first->next = rest_of_list;
	if (c == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	ft_revers_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_printf("rra\n");
}
