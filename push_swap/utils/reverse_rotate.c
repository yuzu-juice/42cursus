#include "../push_swap.h"

void	rra(int *stack_a, int top_a)
{
	int	tmp;
	int	i;

	tmp = stack_a[0];
	i = 0;
	while (i < top_a)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[top_a] = tmp;
	ft_printf("rra\n");
}

void	rrb(int *stack_b, int top_b)
{
	int	tmp;
	int	i;

	tmp = stack_b[0];
	i = 0;
	while (i < top_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	stack_b[top_b] = tmp;
	ft_printf("rrb\n");
}

void	rrr(int *stack_a, int *stack_b, int top_a, int top_b)
{
	rra(stack_a, top_a);
	rrb(stack_b, top_b);
}
