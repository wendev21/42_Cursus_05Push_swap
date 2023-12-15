/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:23:15 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/12/15 17:12:00 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	**a;
	t_stack_node	**b;
	t_stack_node	*tmp_a;
	t_stack_node	*tmp_b;
	int				i;
	int				j;
	char			**result;

	a = malloc(sizeof(t_stack_node *));
	b = malloc(sizeof(t_stack_node *));
	if (!a)
		return (0);
	*a = NULL;
	*b = NULL;
	j = 1;
	if (argc == 1 || (argc == 2 && !(argv[1][0])))
		return ((write(1, "ERROR\n", 6)),1);
	else if (argc >= 2)
	{
		while (argc > j)
		{
			result = split_mut(argv[j], ' ');
			i = 0;
			while (result[i] != NULL)
			{
				init_stack_a(a, result[i]);
				free(result[i]);
				i++;
			}
			j++;
		}
	}
	if (stack_sorted(a) == false)
	{
		if (stack_len(a) == 2)
			sa(a, false);
		else if (stack_len(a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
/*	tmp_a = *a;
	while (tmp_a)
	{
		printf("nbr :%d\n", tmp_a->nbr);
//		printf("pushh_cost :%d\n", tmp_a->push_cost);
//		printf("index :%d\n", tmp_a->index);
		tmp_a = tmp_a->next;
	}
	printf("\n");
		tmp_b = *b;
	while (tmp_b)
	{
		printf("nbr b:%d\n", tmp_b->nbr);
//		printf("push_cost :%d\n", tmp_b->push_cost);
//		printf("index :%d\n", tmp_b->index);
		tmp_b = tmp_b->next;
	}
	printf("\n");*/
	free_stack(a);
	return (0);
}
