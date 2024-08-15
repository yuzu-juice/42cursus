#include "../push_swap.h"

void	sa(int *stack, int top)
{
	int	tmp;

	if (top < 1)
	{
		ft_printf("sa\n");
		return ;
	}
	tmp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = tmp;
	ft_printf("sa\n");
}

void	sb(int *stack, int top)
{
	int	tmp;

	if (top < 1)
	{
		ft_printf("sb\n");
		return ;
	}
	tmp = stack[top];
	stack[top] = stack[top - 1];
	stack[top - 1] = tmp;
	ft_printf("sb\n");
}

void	ss(int *stack_a, int *stack_b, int top_a, int top_b)
{
	sa(stack_a, top_a);
	sb(stack_b, top_b);
}