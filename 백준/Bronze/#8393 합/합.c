#include <stdio.h>

int main() {

	int i, num;
	int j = 0;

	scanf("%d", &num);

	for (i = 0; i < num + 1; i++)

		j += i;
	printf("%d", j);



	return 0;
}