/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:23:15 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/29 16:30:46 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack_node 	*a;
	t_stack_node 	*b;
	int				i, j;
	char			**result;


	a = NULL;
	b = NULL;
	i = 0;
	j = 1;
	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return (1);
	else if (argc >= 2)
	{
		result = split_mut(argv[j], ' ');
		while (result[i] != NULL)
		{
			init_stack_a(a, result[i]);
		//	printf("argc %s\n", result[i]);
			i++;
		}

	}
	/*
	if (stack_sorted(a) == false)
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if(stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	*/
	return (0);
}
