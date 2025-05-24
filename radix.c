/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:46:54 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 15:20:55 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_restore(t_node **s_a, t_node **s_b, char **r, int *j)
{
	while (*s_b != NULL)
	{
		ft_push_a(s_b, s_a, r, *j);
		(*j)++;
	}
}

static void	ft_new_order(t_node **s_a, t_node **s_b, char **r, int size)
{
	t_node	*current;
	int		i;
	int		rep;
	int		j;

	i = 0;
	j = 0;
	while (!ft_is_sorted(*s_a))
	{
		current = *s_a;
		rep = 0;
		while (current != NULL && rep != size + 1)
		{
			if (((*s_a)->pos >> i) & 1)
				ft_rotate(s_a, r, j);
			else
				ft_push_b(s_a, s_b, r, j);
			rep ++;
			j ++;
		}
		ft_restore(s_a, s_b, r, &j);
		i++;
	}
	r[j] = NULL;
}

static void	ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	ft_radix(t_node	**stack_a, t_node **stack_b)
{
	char	**result;
	int		size;

	result = (char **)malloc (sizeof(char *) * 10000);
	size = ft_size_list(stack_a);
	ft_new_order(stack_a, stack_b, result, size);
	while (size >= 0)
	{
		size --;
		ft_optimization(result);
	}
	ft_print_result(result);
	ft_free(result);
}

int	ft_is_sorted(t_node *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->pos > stack->next->pos)
			return (0);
		stack = stack->next;
	}
	return (1);
}
