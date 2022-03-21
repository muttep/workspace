#include <stdio.h>

int main()
{
	// int arr[]={5,2,9,1,3,7,6};		// no duplicate elements
	int arr[]={5,2,9,1,2,5,6};		// one duplicate element

	int i,j;
	int size=sizeof(arr)/sizeof(arr[0]);
	int duplicate=0,duplicate_count=0;
	int count_inner=0,count_outer=0;

	printf("array size : %d\n",size);

	for(i=0;i<size-1;i++) {
		++count_outer;
		for(j=i+1;j<size;j++) {
			++count_inner;
			// printf("j : %d\n",j);
			if(arr[i]==arr[j]) {
				duplicate=arr[i];
				duplicate_count++;				
			}
		}
	}

	printf("count_outer : %d\n",count_outer);
	printf("count_inner : %d\n",count_inner);

	if(duplicate!=0) {
		printf("duplicate element : %d\n",duplicate);
		printf("duplicate_count : %d\n",duplicate_count);
	} else {
		printf("no duplicate element found\n");
	}

	return 0;
}