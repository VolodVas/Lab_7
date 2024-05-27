#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

// Функція для ініціалізації масиву випадковими значеннями в діапазоні [-100, 100]
void initializeArray(int arr[], int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; // Генерація числа в діапазоні [-100, 100]
    }
}

// Функція для виведення масиву на екран
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функція для визначення індексу мінімального елемента масиву
int findMinIndex(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Функція для обчислення добутку елементів масиву до першого нульового елемента
int productUntilZero(int arr[], int size, int *foundZero) {
    int product = 1;
    *foundZero = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            *foundZero = 1;
            break;
        }
        product *= arr[i];
    }
    return product;
}

int main() {
    int continueProgram;

    do {
        int arr[SIZE];

        // Ініціалізація масиву
        initializeArray(arr, SIZE);

        // Виведення масиву на екран
        printf("Масив: ");
        printArray(arr, SIZE);

        // Знаходження індексу мінімального елемента
        int minIndex = findMinIndex(arr, SIZE);
        printf("Індекс мінімального елемента: %d\n", minIndex);

        // Обчислення добутку елементів до першого нульового елемента
        int foundZero;
        int product = productUntilZero(arr, SIZE, &foundZero);
        if (foundZero) {
            printf("Добуток елементів до першого нульового елемента: %d\n", product);
        } else {
            printf("Нульового елемента не знайдено.\n");
        }

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
