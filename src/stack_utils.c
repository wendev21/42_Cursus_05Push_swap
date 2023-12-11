/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:14 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 17:04:59 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	stack_sorted(t_stack_node **a)
{
	t_stack_node	*tmp;

	tmp = *a;
	if (!a)
		return (0);
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

int	stack_len(t_stack_node **a)
{
	int				i;
	t_stack_node	*tmp;

	i = 0;
	if (!(*a))
		return (0);
	tmp = *a;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack_node	*find_last(t_stack_node **stack)
{
	t_stack_node	*tmp;

	tmp = *stack;
	if (!stack)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack_node	*stack_max(t_stack_node **stack)
{
	long			max;
	t_stack_node	*max_node;
	t_stack_node	*tmp;

	max = LONG_MIN;
	max_node = (*stack);
	tmp = (*stack);
	while (tmp)
	{
		if ((tmp->nbr) > max)
		{
			max = tmp->nbr;
			max_node = (tmp);
		}
		tmp = tmp->next;
	}
	return (max_node);
}

t_stack_node	*stack_min(t_stack_node	**stack)
{
	long			min;
	t_stack_node	*min_node;

	min = LONG_MAX;
	min_node = (*stack);
	while (*stack)
	{
		if (((*stack)->nbr) < min)
		{
			min = (*stack)->nbr;
			min_node = (*stack);
		}
		(*stack) = (*stack)->next;
	}
	return (min_node);
}
