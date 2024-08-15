/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takitaga  <takitaga@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 23:06:49 by takitaga          #+#    #+#             */
/*   Updated: 2024/08/15 14:37:44 by takitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[]) {
	int	i;
	int	*elements;

	i = 1;
	elements = malloc(sizeof(int) * (argc - 1));
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		elements[argc - i - 1] = ft_atoi(argv[i]);
		// implement duplicate check
		// validate if inputs in range of int
		i++;
	}
	push_swap(elements, argc - 1);
	free(elements);
	return (0);
}

static void	print_stack(int *stack_a, int *stack_b, int top_a, int top_b, size_t size)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = TRUE;
	if (top_a == -1)
		ft_printf("stack_a is empty.\n");
	while (i < size)
	{
		if (flag)
			ft_printf("a[%u]: %d", i, stack_a[i]);
		else
			ft_printf("a[%u]:", i);
		if ((size_t)top_a == i)
		{
			ft_printf(" <- top");
			flag = FALSE;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	if (top_b == -1)
		ft_printf("stack_b is empty.\n");
	i = 0;
	flag = TRUE;
	while (i < size)
	{
		if (flag)
			ft_printf("b[%u]: %d", i, stack_b[i]);
		else
			ft_printf("b[%u]:", i);
		if ((size_t)top_b == i)
		{
			ft_printf(" <- top");
			flag = FALSE;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n\n-------------------------\n\n");
}

void	push_swap(int *elements, size_t size)
{
	int		stack_a[size];
	int		stack_b[size];
	int		top_a;
	int		top_b;
	size_t	i;

	ft_memset(stack_a, 0, sizeof(int) * size);
	ft_memset(stack_b, 0, sizeof(int) * size);
	top_a = size - 1;
	top_b = -1;

	i = 0;
	while (i < size)
	{
		stack_a[i] = elements[i];
		i++;
	}
	ft_printf("defalut\n");
	print_stack(stack_a, stack_b, top_a, top_b, size);

	sa(stack_a, top_a);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	pb(stack_a, stack_b, &top_a, &top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	sb(stack_b, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	pb(stack_a, stack_b, &top_a, &top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	sb(stack_b, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	ra(stack_a, top_a);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	rb(stack_b, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);

	rr(stack_a, stack_b, top_a, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);
	
	rrr(stack_a, stack_b, top_a, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);
}
