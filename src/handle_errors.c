/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:25 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/15 16:19:22 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_syntax(char *str_n)
{
	int	i;

	i = 0;
	if (!(str_n || str_n[i] == '\0'))
		return (write(1, "ERROR\n", 6), 1);
	i++;
	while (str_n[i])
	{
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
