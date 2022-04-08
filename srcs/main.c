#include "../includes/push_swap.h"


void sa(t_ma_stack *stack)
{
    //---TODO:
    //sa (swap a): Swap the first 2 elements at the top of stack a.
    //Do nothing if there is only one or no elements.
    int temp;
    temp = stack -> a[0];
    stack -> a[0] = stack -> a[1];
    stack -> a[1] = temp;
}

void sb(t_ma_stack *stack)
{
    //---TODO:
    //(swap b): Swap the first 2 elements at the top of stack b.
    //Do nothing if there is only one or no elements.
    int temp;
    temp = stack -> b[0];
    stack -> b[0] = stack -> b[1];
    stack -> b[1] = temp;
}

void ss(t_ma_stack *stack)
{
    //---TODO:
    //(sa and sb at the same time.
    sa(stack);
    sb(stack);
}

void pa(t_ma_stack *stack)
{
    //---TODO:
    //(push a): Take the first element at the top of b and put it at the top of a.
    //Do nothing if b is empty
}

void pb(t_ma_stack *stack)
{
    //---TODO:
    // (push b): Take the first element at the top of a and put it at the top of b.
    //Do nothing if a is empty.
}

void ra(t_ma_stack *stack)
{
    //---TODO:
    //(rotate a): Shift up all elements of stack a by 1.
    //The first element becomes the last one.
    //int top_of_a = stack->a[stack->size_a - 1];
    int i;

    i = 1;
    int first_elem_a = stack->a[0];
    while (stack->a[i])
    {
        stack->a[i - 1] = stack->a[i];
        i++;
    }
    stack->a[stack->size_a - 1] = first_elem_a;
}

void rb(t_ma_stack *stack)
{
    //---TODO:
    // (rotate b): Shift up all elements of stack b by 1.
    //The first element becomes the last one.
    //printf("%d", stack->size_b);
    int i;

    i = 1;
    int first_elem_b = stack->b[0];
    while (stack->b[i])
    {
        stack->b[i - 1] = stack->b[i];
        i++;
    }
    stack->b[stack->size_b - 1] = first_elem_b;
}


void rr(t_ma_stack *stack)
{
    //---TODO:
    //ra and rb at the same time.
    ra(stack);
    rb(stack);
}

void rra(t_ma_stack *stack)
{
    //---TODO:
    // (reverse rotate a): Shift down all elements of stack a by 1.
    //The last element becomes the first one.
}

void rrb()
{
    //---TODO:
    //(reverse rotate b): Shift down all elements of stack b by 1.
    //The last element becomes the first one.
}

void rrr()
{
    //---TODO:
    //rra and rrb at the same time.
}

static int	ft_long_check(const char *str, int i, int x)
{
	long	number;
	long	temp;

	number = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = number;
		number *= 10;
		number += str[i] - '0';
		if (temp > number)
		{
			if (x == -1)
				return (0);
			if (x == 1)
				return (-1);
		}
		i++;
	}
	return (number * x);
}
int	ft_atoi(const char *str)
{
	int		i;
	int		x;

	i = 0;
	x = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			x = -1;
		i++;
	}
	return (ft_long_check(str, i, x));
}

t_ma_stack *init_stack_a(int argc)
{
	t_ma_stack *stack;

	stack = malloc(sizeof(*stack));
    stack->a = malloc(sizeof(int) * argc);
    stack->size_a = argc;
    return stack;
}

void set_values_a(char **argv, t_ma_stack *stack)
{
    int i;

    i = 0;
    while (i < stack -> size_a)
    {
        stack->a[i] = ft_atoi(argv[i]);
        i++;
    }
}

void printa(t_ma_stack *stack)
{
    int i;

    i = 0;
    while (stack->a[i])
    {
        printf("%d \n", stack->a[i]);
        i++;
    }
}

void printb(t_ma_stack *stack)
{
    int i;

    i = 0;
    while (stack->b[i])
    {
        printf("%d \n", stack->b[i]);
        i++;
    }
}


void stackin(t_ma_stack *stack)
{
    stack->a = 0;
    stack->b = 0;

    stack->size_a = 0;
    stack->size_b = 0;
}

int	main(int argc, char **argv)
{
    t_ma_stack *stack = init_stack_a(argc - 1);
    set_values_a(&argv[1], stack);
    /*sa(stack);
    ra(stack);
    pb(stack);
    ra(stack);
    rr(stack);*/
    //pb(stack);
    //pb(stack);
    //pb(stack);
    //rb(stack);
    rra(stack);
    //printa(stack);
    //printb(stack);
}