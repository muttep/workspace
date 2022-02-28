#include <stdio.h>

int main()
{
	struct book {
		char name[20];
		int noofpages;
		float price;
	};

	// static struct book b;
	struct book b = { 0 };
	printf("%d %f\n", b.noofpages, b.price);

	return 0;
}