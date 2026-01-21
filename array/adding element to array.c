#include <stdio.h>

int main() {
    int a[100] = {1, 2, 3, 4, 5};  // original array
    int n = 5;                     // number of elements
    int pos = 2;                   // index where to insert
    int value = 7;               // value to insert

    // shift elements to the right
    for (int i = n; i > pos; i--) {
        a[i] = a[i - 1];
    }

    a[pos] = value;  // insert value
    n++;             // increase size

    // print array
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}

