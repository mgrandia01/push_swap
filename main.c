/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:07:02 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/05 17:07:21 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort(t_node *stack_a, t_node *stack_b, int size)
{
	ft_assign_position(stack_a);
	if ((size > 5 || size == 2) && !ft_is_sorted(stack_a))
		ft_radix(&stack_a, &stack_b);
	else if (size == 3 && !ft_is_sorted(stack_a))
		ft_three_numbers(&stack_a, 0);
	else if (size == 4 && !ft_is_sorted(stack_a))
		ft_four_numbers(&stack_a, &stack_b);
	else if (size == 5 && ! ft_is_sorted(stack_a))
		ft_five_numbers(&stack_a, &stack_b);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
}

static int	ft_error_miss(t_node *stack_a)
{
	ft_free_list(stack_a);
	ft_printf("Error\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		content;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!ft_input_is_correct(argv[i]) || !ft_input_int(argv[i]))
			return (ft_error_miss(stack_a));
		content = ft_atoi(argv[i]);
		ft_append(&stack_a, content);
		i ++;
	}
	if (!ft_manage_errors(stack_a))
	{
		ft_free_list(stack_a);
		return (0);
	}
	ft_sort(stack_a, stack_b, i - 1);
	return (0);
}
