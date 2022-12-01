#include <stdio.h>
#include "stack.h"

int main()
{
	Stack s1;
	CreateEmptyStack(&s1);

	for (int i = 0; i < 5; i++)
	{
		PushStack(&s1, i);
		printf("is full: %d\n", IsFullStack(s1));
		printf("is empty: %d\n", IsEmptyStack(s1));
		printf("top : %d\n", TopStack(s1));
		printf("infotop: %d\n", InfoTopStack(s1));
		printf("t ke i :%d\n", s1.T[i]);
	}

	PrintStack(s1);

	Stack s2 = InverseStack(s1);

	PrintStack(s2);

	int val;
	for (int i = 0; i < 5; i++)
	{
		PopStack(&s1, &val);
		printf("%d\n", val);
		printf("%d\n", IsEmptyStack(s1));
	}
	return 0;
}