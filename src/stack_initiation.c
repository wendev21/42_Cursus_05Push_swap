/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:16:42 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/16 16:31:15 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_atol(char *str_n)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	if (str_n[i] == '-')
		sign = -1;
	if (str_n[i] == '+' || str_n[i] == '-')
		i++;
	while (str_n[i] >= '0' && str_n[i] <= '9')
	{
		nbr = nbr + (str_n[i] - '0');
		if (str_n[i + 1] >= '0' && str_n[i + 1] <= '9')
			nbr = nbr * 10;
		i++;
	}
	i++;
	return (nbr * sign);
}

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack_a(t_stack_node **a, char *str_n)
{
	long	nbr;

	if ((error_syntax(str_n)) == 1)
		free_error(a);
	nbr = ft_atol(str_n);
	if ((error_duplicate(a, nbr) == 1))
		free_error(a);
	else if (nbr < INT_MIN || nbr > INT_MAX)
		free_error(a);
	else
		append_node(a, nbr);
}
