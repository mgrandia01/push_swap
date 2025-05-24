/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 14:49:00 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:47:31 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_duplicate(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack_a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_manage_errors(t_node *stack_a)
{
	if (ft_is_duplicate(stack_a))
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	ft_input_is_correct(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_input_int(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	if (ft_strlen(str + i) > 10)
		return (0);
	if (ft_strlen(str + i) == 10)
	{
		if ((sign == 1 && ft_strncmp(str + i, "2147483647", 10) > 0)
			|| (sign == -1 && ft_strncmp(str + i, "2147483648", 10) > 0))
		{
			return (0);
		}
	}
	return (1);
}
