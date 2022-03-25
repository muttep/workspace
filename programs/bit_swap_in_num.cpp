#include <iostream>
#include <bitset>
using namespace std;

bitset<32> toBinary(unsigned int n) {
	return bitset<32>(n);
}


#if 1
// This function swaps bit at positions p1 and p2 in an integer n
int swapBits(unsigned int n, unsigned int p1, unsigned int p2)
{
    /* Move p1'th to rightmost side */
    unsigned int bit1 =  (n >> p1) & 1;
    cout<<"bit1 : "<<toBinary(bit1)<<endl;
 
    /* Move p2'th to rightmost side */
    unsigned int bit2 =  (n >> p2) & 1;
    cout<<"bit2 : "<<toBinary(bit2)<<endl;
 
    /* XOR the two bits */
    unsigned int x = (bit1 ^ bit2);
    cout<<"x : "<<toBinary(x)<<endl;
 
    /* Put the xor bit back to their original positions */
    x = (x << p1) | (x << p2);
    cout<<"x : "<<toBinary(x)<<endl;
 
    /* XOR 'x' with the original number so that the
       two sets are swapped */
    unsigned int result = n ^ x;
    cout<<"result : "<<toBinary(result)<<endl;
    return result;
}
#else
int swapBits(int n, int p1, int p2)	// It failes for swapBits(0xF000FFFF,0,30) , pos2=31 or 30
{
    //left-shift 1 p1 and p2 times
    //and using XOR
    n ^= 1 << p1;
    n ^= 1 << p2;
    return n;
}
#endif

int main()
{
	unsigned int num=0x0000FFFF;
	unsigned int pos1=0;
	unsigned int pos2=31;

	int n = swapBits(num,pos1,pos2);

	cout<<"from main"<<endl;
	cout<<"num : "<<toBinary(num)<<endl;
	cout<<"res : "<<toBinary(n)<<endl;

	return 0;
}