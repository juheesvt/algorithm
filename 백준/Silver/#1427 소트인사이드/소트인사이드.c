int main() {
	int count[10] = { 0, };
	int in;
	
	scanf("%d", &in);
	for (; in != 0; in /= 10) {
		count[in % 10] += 1;
	}
	for (int i = 9; i >= 0; --i) {
		while (count[i]) {
			count[i]--;
			printf("%d", i);
		}
	}


	return 0;
}