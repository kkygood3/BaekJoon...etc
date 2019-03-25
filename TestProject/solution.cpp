#include <stdio.h>
#include <string.h>

int main(void) {

	char a[100];

	scanf("%s", a);	

	int size = strlen(a);

	printf("%s\n", a);
	while (size > 1) {
		for (int i = 0; i < size - 1; i++)
		{
			char tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
		}
		printf("%s\n", a);
		size--;
	}

	return 0;
}