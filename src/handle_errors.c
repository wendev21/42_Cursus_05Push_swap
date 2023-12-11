/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:25 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 16:58:20 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_n)
{
	int	value;
	int	i;

	value = 0;
	if (!(str_n))
		value = 1;
	if (!(*str_n == '+' || *str_n == '-' || *str_n >= '0' || *str_n <= '9'))
	{
		printf("syntax 1\n");
		value = 1;
	}
	if ((*str_n == '+' || *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
	{
		printf("syntax 2\n");
		value = 1;
	}
	i = 1;
	while (str_n[i])
	{
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			value = 1;
		i++;
	}
	return (value);
}

int	error_duplicate(t_stack_node **a, int n)
{
	t_stack_node	*tmp;

	tmp = *a;
	if (!(a))
		return (0);
	while (tmp)
	{
		if (tmp->nbr == n)
		{
			printf("Error Duplicado");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*tmp;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	stack = NULL;
}

void	free_error(t_stack_node **stack)
{
	free_stack(stack);
	printf("ERROR =( \n");
	exit (1);
}
