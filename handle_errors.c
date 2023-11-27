/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:25 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/27 12:43:34 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	int	value;

	value = 0;
	if (!(*str_n))
		value = 1;
	if (!(*str_n == '+' || *str_n == '-'
			|| *str_n >= '0' || *str_n <= '9'))
		value = 1;
	if (*str_n == '+' || *str_n == '-'
		&& !(str_n[1] >= '0' && str_n[1] <= 9))
		value = 1;
	while (*str_n)
	{
		str_n++;
		if (!(*str_n >= 0 && *str_n <= 9))
			value (1);
	}
	return (value);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!(a))
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_stack(t_struct_node *stack)
{
	t_struct_node	*current;
	t_struct_node	*tmp;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_error(t_struct_node *stack)
{
	free_stack(stack);
	ft_printf("ERROR =( \n");
	exit (1);
}
