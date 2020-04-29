#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int chrtoint(char a){
	int i;
	for (i = 48; i<=57; i++)
		if (toascii(i)==a) return i-48;
	return 0;
}

char *strrev(char *str)
{
	char *p1, *p2;
	if (! str || ! *str)
		return str;
	for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
	{
		*p1 ^= *p2;
		*p2 ^= *p1;
		*p1 ^= *p2;

		return str;
	}
}

void main(int argc, char *argv[]){
	char n1[80];
	char n2[80];
	int rs[80];
	int c1, c2;

	int i,j,m, cmax, sum;
	printf("%s\n", argv[1]);
	if( argc == 3) {
		sprintf(n1, "%s", argv[1]);
		sprintf(n2, "%s", argv[2]);
	}
	else {
		printf("Need two argument numbers\n");
		exit(0);
	}
	c1 = strlen(n1);
	c2 = strlen(n2);

	strrev(n1);
	strrev(n2);

	cmax = c1;
	if(c1<c2){
		cmax = c2;
	}

	m=0;
	for(i=0; i< cmax; i++){
		if(c1==c2 || (i < c1 && i < c2)){
			sum = m+chrtoint(n1[i])+chrtoint(n2[i]);
		}else if(i >=c1){
			sum = m+chrtoint(n2[i]);
		}else if(i >=c2){
			sum = m+chrtoint(n1[i]);
		}
		rs[i] = sum%10;
		m = sum/10;
	}

	if(m){
		rs[i]=m;
		i++;
	}

	printf("\nResult: ");
	for(j=0; j < i; j++){
		printf("%d", rs[i-j-1]);
	}
	printf("\n");

}
