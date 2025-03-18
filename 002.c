#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void stringmatcher(char *string , char *pattern){
	int n,m,i,j;
	n=strlen(string);
	m=strlen(pattern);
	if(m>n){
		printf("cant find pattern ");
		return;
	}
	for(i=0;i<=n-m;i++){
		for(j=0;j<m;j++){
			if(string[i+j]!=pattern[j]){
				break;
			}
		}
		if(j==m){
			printf("pattern found at : %d\n",i);
		}
		
	}
}
int main(){
	char *string="nobody noticed him";
	char *pattern="him";
	stringmatcher(string,pattern);
	return 0;
}
