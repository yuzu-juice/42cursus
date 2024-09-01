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

int	has_duplicates(int *elements, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (i + j + 1 < size)
		{
			if (elements[i] == elements[i + j + 1])
				return TRUE;
			j++;
		}
		i++;
	}
	return FALSE;
}

int main(int argc, char *argv[])
{
	int		i;
	int		elements[argc - 1];

	i = 1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		elements[argc - i - 1] = ft_atoi(argv[i]);
		if (elements[i] < INT_MIN || elements[i] > INT_MAX)
		{
			ft_printf("Error\n");
			return (1);	
		}
		i++;
	}
	if (has_duplicates(elements, argc - 1))
	{
		ft_printf("Error\n");
		return (1);
	}
	push_swap(elements, argc - 1);
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

static void sort_two(int *stack_a, int top_a)
{
	if (stack_a[top_a] > stack_a[top_a - 1])
		sa(stack_a, top_a);
	return ;
}
static void sort_three(int *stack_a, int top_a)
{
	if (stack_a[top_a] < stack_a[top_a - 1] && stack_a[top_a - 1] < stack_a[top_a - 2])
		return ;
	if (stack_a[top_a - 1] < stack_a[top_a] && stack_a[top_a] < stack_a[top_a - 2])
	{
		sa(stack_a, top_a);
		return ;
	}
	if (stack_a[top_a] < stack_a[top_a - 2] && stack_a[top_a - 2] < stack_a[top_a - 1])
	{
		rra(stack_a, top_a);
		sa(stack_a, top_a);
		return ;
	}
	if (stack_a[top_a - 1] < stack_a[top_a - 2] && stack_a[top_a - 2] < stack_a[top_a - 1])
	{
		ra(stack_a, top_a);
		return ;
	}
	if (stack_a[top_a - 2] < stack_a[top_a] && stack_a[top_a] < stack_a[top_a - 1])
	{
		rra(stack_a, top_a);
		return ;
	}
	if (stack_a[top_a - 2] < stack_a[top_a - 1] && stack_a[top_a - 1] < stack_a[top_a])
	{
		ra(stack_a, top_a);
		sa(stack_a, top_a);
		return ;
	}
}
static void	push_swap_sort(int *stack_a, int *stack_b, int top_a, int top_b)
{
	int	i;
	int	pivot;
	int	sum;
	int	size;
	int	push_count;

	i = 0;
	sum = 0;
	push_count = 0;
	size = top_a + 1;
	while (i < top_a)
	{
		sum += stack_a[i];
		i++;
	}
	pivot =  sum / top_a;
	i = 0;
	while (i <= size)
	{
		if (stack_a[top_a] < pivot)
		{
			pb(stack_a, stack_b, &top_a, &top_b);
			push_count++;
		}
		else
			ra(stack_a, top_a);
		i++;
	}
	i = 0;
	while (i < push_count)
	{
		pa(stack_a, stack_b, &top_a, &top_b);
		i++;
	}
	if (push_count == 2)
	{
		sort_two(stack_a, top_a);
		print_stack(stack_a, stack_b, top_a, top_b, size);
		return ;
	}
	if (push_count == 3)
	{
		sort_three(stack_a, top_a);
		print_stack(stack_a, stack_b, top_a, top_b, size);
		return ;
	}
	print_stack(stack_a, stack_b, top_a, top_b, 20);
	push_swap_sort(stack_a, stack_b, top_a, top_b);
}

void	push_swap(int *elements, size_t size)
{
	int		stack_a[size];
	int		stack_b[size];
	int		top_a;
	int		top_b;
	size_t	i;
	size_t	j;

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
	ft_qsort(elements, 0, size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (stack_a[j] == elements[i])
			{
				stack_a[j] = i;
				break ;
			}
			j++;
		}
		i++;
	}
	push_swap_sort(stack_a, stack_b, top_a, top_b);
	print_stack(stack_a, stack_b, top_a, top_b, size);
}
