#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void Swap(recordtype *a,recordtype *b){
	recordtype temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void read_data(recordtype a[],int *n){
	FILE *f;
	f = fopen("data.txt","r");
	int i =0;
	if (f!=NULL)
	while(!feof(f)){
		fscanf(f,"%d %f",&a[i].key,&a[i].otherfields);
		i++;
	}
	else printf("Loi mo file\n");
	fclose(f);
	*n = i;
}
void print_data(recordtype a[],int n){
	for(int i=0;i<n;i++)
		printf("%3d %5d %8.2f\n",i+1,a[i].key,a[i].otherfields);
}
void SelectionSort(recordtype a[],int n){
	int i,j,lowindex;
	keytype lowkey;
	for(i=0;i<=n-2;i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j=i+1;j<=n-1;j++)
		{
			if(a[j].key<lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		Swap(&a[i],&a[lowindex]);
	}
}
main(){
	recordtype a[100];
	int n;
	printf("Selection Sort:\n");
	read_data(a,&n);
	printf("truoc khi sap xep:\n");
	print_data(a,n);
	printf("sau khi sap xep:\n");
	SelectionSort(a,n);
	print_data(a,n);
}

