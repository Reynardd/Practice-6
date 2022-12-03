#include <stdio.h>
void printImage(int image[255][256],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){printf("%d ",image[i][j]);}
			printf("\n");
    }
}
void convert2Negative(int image[255][256],int n){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){image[i][j]=255-image[i][j];}
	}
}
int main(){
	int n;
	int image[255][256];
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%d",&image[i][j]);}}
	convert2Negative(image,n);
	printImage(image,n);
}
