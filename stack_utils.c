/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:14 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/30 12:46:24 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	stack_len(t_stack_node *a)
{
	int	i;

	i = 0;
	if (!a)
		return (0);
	while (a)
	{
		i++;
		a = a->next;
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
