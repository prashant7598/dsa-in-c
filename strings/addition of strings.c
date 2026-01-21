// to add to matrix
#include<stdio.h>

int main (){
int m,n,p,q;
int A[10][10], B[10][10], C[10][10];

//to take input of matrix

printf("enter the element of matrix");
scanf(" %d %d ", &m ,&n);
scanf("%d %d", &p ,&q);

// to take the element of matrix

if(m==p & n==q){
	printf("enter the element of matrix to be added");
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	
	for(int i=0 ;i<p; i++){
		for(int j=0 ; j<q; j++){
			scanf("%d", &B[i][j] );
		}
	}
	for(int i=0 ; i<m ; i++){
		for(int j=0; j<q;j++){
				C[i][j]= A[i][j]+ B[i][j];			
		}
	}

	
	for(int i=0 ;i<m;i++){
		for(int j=0; j<q;j++){
			printf("after the addition the matrix is %d", C[i][j]);
		}
	}
}
return 0;
}
