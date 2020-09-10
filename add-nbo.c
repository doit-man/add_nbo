#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>

uint32_t read_num(char *a){
	FILE *fp = fopen(a,"r");
	uint32_t num[1];
	size_t result;
	result = fread(num,4,1,fp);
	num[0]=ntohl(num[0]);
	return num[0];
}

int main(int argc, char **argv){
	if(argc != 3)
	{
		printf(" input wrong!");
		return 1;
	}
	uint32_t num1,num2;
	num1 = read_num(argv[1]);
	num2 = read_num(argv[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",num1,num1,num2,num2,num1+num2,num1+num2);
	return 0;


}



