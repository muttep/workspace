#include <stdio.h>

int main()
{
	union a {
		int i;
		char ch[2];
	};

	union a z = {512};
	printf("%d %d", z.ch[0], z.ch[1]);

	return 0;
}