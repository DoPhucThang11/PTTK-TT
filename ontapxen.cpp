#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void swap(recordtype *a,recordtype *b){
	recordtype temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void read_data(recordtype a[], int *n){
	FILE *f;
	f = fopen("data.txt","r");
	int i=0;
	if(f!=NULL)
	while(!feof(f)){
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
	}
	else printf("loi mo file\n");
	fclose(f);
	*n = i;
}
void print_data(recordtype a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
	}
}
void InsertionSort(recordtype a[], int n){
	int i,j;
	for(i=1;i<=n-1;i++){
		j = i;
		while(j>0 && a[j].key < a[j-1].key){
			swap(&a[j],&a[j-1]);
			j--;
		}
	}
}
main(){
	recordtype a[100];
	int n;
	printf("Insertion sort\n");
	printf("truoc khi sap xep\n");
	read_data(a,&n);
	print_data(a,n);
	printf("sau khi sap xep\n");
	InsertionSort(a,n);
	print_data(a,n);
}
