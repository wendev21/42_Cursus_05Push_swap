/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initiation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:16:42 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/23 16:01:50 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_struct));
	if (!node)
		return ;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
		node->next = NULL
	}else
	{
		last_node = find_last(*stacki);
		last_node->next = node;
		last_node->prev = last_node;
	}
}
