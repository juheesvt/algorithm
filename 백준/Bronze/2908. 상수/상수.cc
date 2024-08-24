#include <stdio.h>
#include <string.h>

int main() {

	char a[4] = { 0, };
	char b[4] = { 0, };
	char A, B;

	scanf("%s %s", a,b);

	A = a[0];
	B= b[0];
	a[0] = a[2];
	a[2] = A;
	b[0] = b[2];
	b[2] = B;
	
	if (strcmp(a, b) > 0)
		printf("%s", a);
	else
		printf("%s", b);

	return 0;
}