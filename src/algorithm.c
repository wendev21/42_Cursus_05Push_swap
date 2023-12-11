/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:07:03 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/11 16:58:05 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int				len_a;
	t_stack_node	*tmp;

	len_a = stack_len(a);
	if (len_a-- < 3 && !stack_sorted(a))
		pb(b, a, false);
	if (len_a-- < 3 && !stack_sorted(a))
		pb(b, a, false);
	while (len_a-- < 3 && !(stack_sorted(a)))
	{
		init_a_b(a, b);
		move_a_b(a, b);
	}
	sort_three(a, b);
	tmp = *b;
	while (tmp)
	{
		init_b_a(b, a);
		move_b_a(b, a);
		tmp = tmp->next;
	}
	current_index(a);
	min_on_top(a);
}
