#include <stdio.h>

#include "stack.h"

int main(){
	Stack s1;
	CreateEmpty(&s1);

	for (int i = 0; i < 5; i++){
		Push(&s1, i);
		printf("%d\n", IsFull(s1));
		// printf("top : %d\n", Top(s1));
		// printf("infotop: %d\n", InfoTop(s1));
		// printf("t ke i :%d\n", s1.T[i]);
	}

	// int val;
	// for (int i = 0; i < 5; i++){
	// 	Pop(&s1, &val);
	// 	printf("%d\n", val);
	// 	// printf("%d\n", IsEmpty(s1));
	// }
	return 0;
}