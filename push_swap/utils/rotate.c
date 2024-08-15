#include "../push_swap.h"

void	ra(int *stack_a, int top_a)
{
	int	tmp;
	int	i;

	tmp = stack_a[top_a];
	i = top_a;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = tmp;
	ft_printf("ra\n");
}

void	rb(int *stack_b, int top_b)
{
	int	tmp;
	int	i;

	tmp = stack_b[top_b];
	i = top_b;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = tmp;
	ft_printf("rb\n");
}

void	rr(int *stack_a, int *stack_b, int top_a, int top_b)
{
	ra(stack_a, top_a);
	rb(stack_b, top_b);
}
