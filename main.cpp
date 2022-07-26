#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
	if(argc!=3) {
		printf("usage: ./add-nbo <file1> <file2>");
		return -1;
	}
	
	FILE* fp1 = fopen(argv[1], "rb");
	FILE* fp2 = fopen(argv[2], "rb");

	uint32_t n1;
	uint32_t n2;

	size_t readN1 = fread(&n1, 1, sizeof(n1), fp1);
	size_t readN2 = fread(&n2, 1, sizeof(n2), fp2);

	n1 = ntohl(n1);
	n2 = ntohl(n2);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1+n2, n1+n2);
	
	return 0;
}
