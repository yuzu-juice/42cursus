/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:07:04 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 14:35:46 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

void	push_swap(int *elements, size_t size);
void	sa(int *stack, int top);
void	sb(int *stack, int top);
void	ss(int *stack_a, int *stack_b, int top_a, int top_b);
void	pa(int *stack_a, int *stack_b, int *top_a, int *top_b);
void	pb(int *stack_a, int *stack_b, int *top_a, int *top_b);
void	ra(int *stack_a, int top_a);
void	rb(int *stack_b, int top_b);
void	rr(int *stack_a, int *stack_b, int top_a, int top_b);
void	rra(int *stack_a, int top_a);
void	rrb(int *stack_b, int top_b);
void	rrr(int *stack_a, int *stack_b, int top_a, int top_b);

#endif
