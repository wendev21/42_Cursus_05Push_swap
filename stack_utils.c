/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:14 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/23 16:02:36 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack_node *a)
{
	if (!a)
		return ;
	while (a)
	{
		if (a->nbr > a->next->nbr)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_len(t_struct_node *a)
{
	int	i;

	i = 0;
	if (!a)
		return ;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack_node	find_last(t_stack_node *stack)
{
	if (!stack)
		return ;
	while (stack)
	{
		stack->next
	}
	return (stack);
}
