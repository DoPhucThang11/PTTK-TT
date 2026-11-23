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
read_data(recordtype a[], int *n){
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
void print_data(recordtype a[], int n){
	int i;
	for (i=0;i<n;i++)
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
}
int findpivot(recordtype a[], int i,int j){
	keytype firstkey;
	int k = i+1;
	firstkey = a[i].key;
	while(k<=j && a[k].key ==firstkey) k++;
	if(k>j) return -1;
	if(a[k].key>firstkey) return k;
	return i;
}
int partition(recordtype a[], int i, int j, keytype pivot){
	int l,r;
	l = i;
	r = j;
	while(l<=r){
		while(a[l].key<pivot) l++;
		while(a[r].key>=pivot) r--;
		if(l<r) swap(&a[l],&a[r]);
	}
	return l;
}
void quicksort(recordtype a[],int i,int j){
	keytype pivot;
	int pivotindex, k;
	pivotindex = findpivot(a,i,j);
	if(pivotindex!=-1){
		pivot = a[pivotindex].key;
		k = partition(a,i,j,pivot);
		quicksort(a,i,k-1);
		quicksort(a,k,j);
	}
}
main(){
	recordtype  a[100];
	int n;
	printf("quick sort \n\n");
	read_data(a,&n);
	printf("Truoc khi sap xep:\n");
	print_data(a,n);
	quicksort(a,0,n-1);
	printf("Sau khi sap xep:\n");
	print_data(a,n);
}
