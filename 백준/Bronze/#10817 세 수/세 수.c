#include <stdio.h>

int main() {

	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);

	if ((x >= y && y >= z) || (z >= y && y >= x))
		printf("%d", y);
	else if ((y >= x && x >= z) || (z >= x && x >= y))
		printf("%d", x);
	else
		printf("%d", z);
	
		
		return 0;
}