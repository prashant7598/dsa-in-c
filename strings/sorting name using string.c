#include<stdio.h>
#include<string.h>
struct employee{
	char name[20];
	int salary;
	int age;
	
};

int main(){
	struct employee emp[3]= {
		{"pratik", 200, 18},
		{ "krishna",100, 21},
		{"raj",150, 19}
	};
	
	struct employee temp;
	for(int i=0;i<2; i++){
		for(int j=0; j<2-i;j++){
			if( strcmp(emp[j].name, emp[j+1].name)>0){
				temp=emp[i];
				emp[j]=emp[j+1];
				emp[j+1]= temp;
			}
		}
	}
	printf("sorting by name");
	
	for(int i=0;i<2;i++){
		printf("the name is %s  the age is:%d  the salary is %d  " , emp[i].name, emp[i].age,emp[i].salary);
	}
	return 0;
}
