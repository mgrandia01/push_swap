/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:20:29 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:52:52 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_node **from, t_node **to, char **result, int pos)
{
	t_node	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	result[pos] = ft_strdup("pa");
}

void	ft_push_b(t_node **from, t_node **to, char **result, int pos)
{
	t_node	*temp;

	if (*from == NULL)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	result[pos] = ft_strdup("pb");
}

void	ft_rotate(t_node **stack, char **result, int pos)
{
	t_node	*first;
	t_node	*last;

	result[pos] = ft_strdup("ra");
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
}
