/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorth_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 17:25:38 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 17:00:36 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*max_node;

	if (!(*stack))
		return ;
	max_node = stack_max(stack);
	if ((*stack) == max_node)
		ra(stack, false);
	else if (((*stack)->next) == max_node)
		rra(stack, false);
	if (((*stack)->nbr) > ((*stack)->next->nbr))
		sa(stack, false);
}
