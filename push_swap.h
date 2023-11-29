/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:49 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/29 15:23:41 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

//# include "../01Libftt/libft.h"
//# include "../03ft_printf/ft_printf.h"

typedef struct s_stack_node
{
	int					nbr;
//	int					index;
//	int					push_cost;
//	bool				above_median;
//	bool				cheapest;
//	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}t_stack_node;

//**Handles errors
int				error_syntax(char *str_n);
int 			error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node *stack);
void			free_error(t_stack_node *stack);

//**Stack initiation
void			init_stack_a(t_stack_node *a, char *str_n);
//**Nodes Initiation

//**Stack Utils
t_stack_node	*find_last(t_stack_node *stack);
char			**split_mut(char *str_n, char c);
//**Commands

//**Algorithm

#endif
