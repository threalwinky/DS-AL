#include<stdio.h>
#include<string.h>
/**
 *      author: iwttry
 *      created: 01/09/2022
**/

#include<stdbool.h>
int maxx(int a, int b){ return ((a > b) ? a : b);}
int F[2001][2001];
int main(){
	char a[20001], b[20001];
	scanf("%s%s", &a, &b);
	for (int i = 1; i<=strlen(a); i++){
		for (int j = 1; j<=strlen(b); j++){
			if (a[i - 1] == b[j - 1]) F[i][j] = F[i - 1][j - 1] + 1;
			else F[i][j] = maxx(F[i-1][j], F[i][j-1]);
		}
	}
	printf("%d", F[strlen(a)][strlen(b)]);
}