#include <stdio.h>

struct length {
    int feet;
    int inches;
};

// Add two lengths
struct length add(struct length a, struct length b) {
    struct length r;
    r.feet = a.feet + b.feet;
    r.inches = a.inches + b.inches;

    if (r.inches >= 12) {
        r.feet += r.inches / 12;
        r.inches = r.inches % 12;
    }

    return r;
}

// Subtract lengths
struct length subtract(struct length a, struct length b) {
    struct length r;
    r.feet = a.feet - b.feet;
    r.inches = a.inches - b.inches;

    if (r.inches < 0) {
        r.feet -= 1;
        r.inches += 12;
    }

    return r;
}

// Multiply length
struct length multiply(struct length a, int n) {
    int total = (a.feet * 12 + a.inches) * n;
    struct length r;
    r.feet = total / 12;
    r.inches = total % 12;
    return r;
}

int main() {
    struct length l1 = {5, 8};
    struct length l2 = {3, 9};

    struct length addResult = add(l1, l2);
    printf("Add: %d feet %d inches\n", addResult.feet, addResult.inches);

    struct length subResult = subtract(l1, l2);
    printf("Subtract: %d feet %d inches\n", subResult.feet, subResult.inches);

    struct length mulResult = multiply(l1, 3);
    printf("Multiply: %d feet %d inches\n", mulResult.feet, mulResult.inches);

    return 0;
}

