#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	
}
int partition(int arr[],int p,int q){
	int pi,i,j;
	
	pi=arr[q];
	i=p-1;
	for(j=p;j<q;j++){
		if(arr[j]<pi){
			i++;
			swap(&arr[i],&arr[j]);
			
		}
	}
	swap(&arr[i+1],&arr[q]);
	return i+1;
	
}
void quicksort(int arr[],int p,int q){
	int pi;
	
	if(p<q){
		pi=partition(arr,p,q);
		quicksort(arr,p,pi-1);
		quicksort(arr,pi+1,q);
		
	}
	
	
}
void printarray(int arr[],int size){
	int i;
	
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){

	int n;
	int arr[]={35,50,15,25,80,20,90,45};
	n=sizeof(arr)/sizeof(arr[0]);
	printf("original array :\n");
	printarray(arr,n);
	quicksort(arr,0,n-1);
	printf("sorted array :\n");
	printarray(arr,n);
	return 0;
	
	
}
