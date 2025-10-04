#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "RUS");
    int A, B, C;
    int condition;

    printf("=== ПРОВЕРКА ГИПОТЕЗЫ ===\n");
    printf("Введите три целых числа (A, B, C): ");

    scanf("%d %d %d", &A, &B, &C);

    condition = (A % 3 == 0) && (B % 3 == 0) && (C % 3 == 0);

    printf("Гипотеза подтверждена (1 - да, 0 - нет): %d\n", condition);

    return 0;
}