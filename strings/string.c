#include<stdio.h>
#include<string.h>
int main(){
	char a[10]= "hello";
	char b[10]="world";
	
//    strcpy(a,b);
//	printf("after copy the string is %s ",a);

	
	strcat(a,b); //this will add the string
	printf("after strcat function the string is %s \n" ,a);
	
	if (strcmp(a,b) ==0){
		printf("both strings are same");
	}
	else{
		printf("the strings are different");
	}
		return 0;
	
	
}
