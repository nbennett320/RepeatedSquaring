#include<stdio.h>
#include<stdlib.h>

#define DEBUG 0

unsigned long long multiply(unsigned long long multiplicand, int multiplier);

/* bitwise multiply */
unsigned long long multiply(unsigned long long multiplicand, int multiplier){
	/* upper bound */
	unsigned long long x = multiplicand;
	/* lower bound */
	int y = multiplier;
	unsigned long long product = 0;
	while(y > 0){
		if(y & 1){
			product = product + x;
		}
		x = x << 1;
		y = y >> 1;
	}
	return product;
}

/* main */
int main(int argc, char *argv[]){
	if(argc != 3){
		printf("syntax: RepeatedSquaring BASE EXPONENT\n");	
		printf("ex: RepeatedSquaring 3 2 => returns 9\n");
		return 1;
	}
	if(atoi(argv[2]) == 0){
		printf("result: %d\n", 1);
		return 0;
	}
	int base = atoi(argv[1]);
	int exp = atoi(argv[2]);
	unsigned long long result = base;
	
	/* exponentiate */
	for(int i = 1; i < exp; i++){
		result = multiply(result, base);
		if(DEBUG == 1){printf("current result: %lli\n",result);}
	}

	printf("result: %lli\n", result);
	return 0;
}
