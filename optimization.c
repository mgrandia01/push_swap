/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:37:21 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:48:22 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_remove_block(char **result, int first, int last)
{
	int	i;

	i = first;
	while (i <= last)
	{
		free(result[i]);
		i++;
	}
	while (result[last + 1])
	{
		result[first++] = result[last + 1];
		last++;
	}
	result[first] = NULL;
}

void	ft_optimization(char **result)
{
	int	i;

	i = 0;
	while (result[i] && result[i + 1])
	{
		if ((result[i][0] == 'p' && result[i][1] == 'b')
				&& (result[i + 1][0] == 'p' && result[i + 1][1] == 'a'))
		{
			ft_remove_block(result, i, i + 1);
		}
		else
			i ++;
	}
}

void	ft_print_result(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		ft_printf("%s\n", result[i]);
		i ++;
	}
}
