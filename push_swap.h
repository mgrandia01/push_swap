/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrandia <mgrandia@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:08:24 by mgrandia          #+#    #+#             */
/*   Updated: 2025/05/03 14:53:22 by mgrandia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "LibMarta/Libft/libft.h"
# include "LibMarta/ft_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	int				pos;
}	t_node;

//ft_list
void	ft_append(t_node **head, int value);
void	ft_free_list(t_node *head);
int		ft_size_list(t_node **stack);

//errors
int		ft_manage_errors(t_node *stack_a);
int		ft_input_is_correct(char *str);
int		ft_input_int(char *str);

//ft_positions
void	ft_assign_position(t_node *head);

//ft_optimization
void	ft_optimization(char **result);
void	ft_print_result(char **result);

//push_swap_utils
void	ft_push_a(t_node **from, t_node **to, char **res, int pos);
void	ft_push_b(t_node **from, t_node **to, char **res, int pos);
void	ft_rotate(t_node **stack, char **res, int pos);

//simple_utils
void	ft_push_simple(t_node **from, t_node **to, char c);
void	ft_simple_rotate(t_node **stack);
void	ft_swap(t_node **stack, char c);
void	ft_revers_rotate(t_node **stack);

//simple_numbers
void	ft_three_numbers(t_node **stack, int i);
void	ft_four_numbers(t_node **stack_a, t_node **stack_b);
void	ft_five_numbers(t_node **stack_a, t_node **stack_b);

//radix
void	ft_radix(t_node **stack_a, t_node **stack_b);
int		ft_is_sorted(t_node *stack);

//void	ft_print_list(t_node *head);
//void	ft_print(t_node *head);
//int		ft_compr(int num, int pos);
//void	ft_remove_block(char **result, int first, int last);
//int		ft_is_duplicate(t_node *stack_a);
#endif
