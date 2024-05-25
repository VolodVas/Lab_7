#include <stdio.h>

int MinArray(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; ++i) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

int main() {
    int continueProgram;

    do {
        int n;

        // Введення розміру масиву
        printf("Введіть розмір масиву: ");
        while (scanf("%d", &n) != 1 || n <= 0) {
            printf("Некоректне введення. Розмір масиву має бути додатним цілим числом. Спробуйте ще раз: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

        int a[n];

        // Введення елементів масиву
        printf("Введіть %d елементів масиву:\n", n);
        for (int i = 0; i < n; ++i) {
            while (scanf("%d", &a[i]) != 1) {
                printf("Некоректне введення. Введіть ціле число: ");
                while (getchar() != '\n'); // Очищення буфера вводу
            }
        }

        // Виклик функції MinArray і виведення результату
        int min = MinArray(a, n);
        printf("Мінімальний елемент масиву: %d\n", min);

        // Меню для продовження або завершення програми
        printf("Продовжити? (Так, введіть 1) (Ні, введіть 0): ");
        while (scanf("%d", &continueProgram) != 1 || (continueProgram != 0 && continueProgram != 1)) {
            printf("Некоректне введення. Введіть 1 для продовження або 0 для завершення: ");
            while (getchar() != '\n'); // Очищення буфера вводу
        }

    } while (continueProgram == 1);

    printf("Програму завершено.\n");

    return 0;
}
