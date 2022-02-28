#if 1
#include <stdio.h>

int main()
{

	int i;

	// int *ptr=&i;


	printf("%u\n", (int *)&i);
	printf("%u\n", (int *)&i+1);

	printf("szie of :%ld\n", ((char *)(&i+1)-(char *)&i));
	printf("sizeof : %ld\n", sizeof(i));

}
#endif

#if 0
#include <stdio.h>
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
main(void) {
   int x = 10;
   char y = 'f';
   double z = 254748.23;
   printf("size of x: %ld\n", my_sizeof(x));
   printf("size of y: %ld\n", my_sizeof(y));
   printf("size of z: %ld\n", my_sizeof(z));
}
#endif