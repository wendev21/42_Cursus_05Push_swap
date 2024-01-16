/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:25 by wecorzo-          #+#    #+#             */
/*   Updated: 2024/01/16 17:36:37 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n || str_n[i] == '\0'))
		return (write(2, "Error\n", 6), 1);
	while (str_n[i])
	{
		if (i == 0 && (str_n[i] == '-' || str_n[i] == '+'))
			i++;
		if (!(str_n[i] >= '0' && str_n[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
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
			return (1);
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
	free(stack);
	stack = NULL;
}

void	free_error(t_stack_node **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit (1);
}
