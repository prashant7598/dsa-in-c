#include <stdio.h>
#include <string.h>

int main() {
    char a[30];              // enough space
    char *b = "world";       // pointer to string "world"
    char *msg = "hello";     // pointer to string "hello"

    strcpy(a, msg);          // copy msg into a => a = "hello"
    strcat(a, b);            // add b to a => a = "helloworld"

    printf("After strcat function, the string is: %s\n", a);

    if (strcmp(a, b) == 0){
	
        printf("The strings are equal\n");
    }
    else{
	
        printf("The strings are different\n");
    }

    return 0;
}


