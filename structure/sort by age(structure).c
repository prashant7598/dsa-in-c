#include <stdio.h>
#include <string.h>

struct employee {
    char name[20];
    int age;
    int salary;
};

int main() {
    struct employee e[3], temp;

    // Data
    strcpy(e[0].name, "Krishna");
    e[0].age = 22;
    e[0].salary = 5000;

    strcpy(e[1].name, "Pratik");
    e[1].age = 20;
    e[1].salary = 6000;

    strcpy(e[2].name, "Amit");
    e[2].age = 21;
    e[2].salary = 7000;

    // Sort by age
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (e[i].age > e[j].age) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    printf("Sorted by age:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s %d %d\n", e[i].name, e[i].age, e[i].salary);
    }

    return 0;
}

