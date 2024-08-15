#include "../push_swap.h"

void	pa(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	if (*top_b == -1)
		return ;
	stack_a[++*top_a] = stack_b[*top_b--];
	ft_printf("pa\n");
}

void	pb(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	if (*top_a == -1)
		return ;
	(*top_b)++;
	stack_b[*top_b] = stack_a[*top_a];
	(*top_a)--;
	ft_printf("pb\n");
}
