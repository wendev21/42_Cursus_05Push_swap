/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wecorzo- <wecorzo-@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:08:49 by wecorzo-          #+#    #+#             */
/*   Updated: 2023/11/23 12:57:54 by wecorzo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../01Libftt/libft.h"
# include "../03ft_printf/ft_printf.h"

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


//**Stack initiation

//**Nodes Initiation

//**Stack Utils

//**Commands

//**Algorithm

#endif
