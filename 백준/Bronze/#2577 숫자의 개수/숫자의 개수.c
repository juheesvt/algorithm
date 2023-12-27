#include <stdio.h>


int main() {


	int a, b, c, d;

	char x[10];
	int e[10] = { 0, };
	scanf("%d %d %d", &a, &b, &c);

	d = a * b*c;  // d=17301300
	sprintf(x, "%d", d);

	for (int i = 0; i < 9; i++)
		e[x[i] - 48] += 1;


	for (int k = 0; k <10; k++)
		printf("%d\n", e[k]);

		return 0;
	}