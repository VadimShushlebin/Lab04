#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int nuber(char fname);
int function_tub(char* fname, float interval1, float interval2, float tab, char mode);


main() {

	system("chcp 1251");

	char fname2[20] = "temp.txt";

	float int1, int2, tab;
	char mode;
	printf("Дозаписать в существующий файл - a\nСоздать новый файл - w\n");
	scanf("%c", &mode);
	printf("Введите начало интервала: ");
	scanf("%f", &int1);
	printf("Введите конец интервала: ");
	scanf("%f", &int2);
	printf("Введите шаг табуляции: ");
	scanf("%f", &tab);
	int k = function_tub(fname2, int1, int2, tab, mode);
	if (k == 1) printf("Успех!");
	else printf("Произошла ошибка!");
}



float func(float x) {
	return x * x * x + 3 * x * x - 3;
}


int function_tub(char* fname, float interval1, float interval2, float tab, char mode) {

	FILE* temp_t;
	puts("Создание файла");

	if (mode == "at") {
		if ((temp_t = fopen(fname, "a")) == NULL) {
			printf("Ошибка открытия файла для записи");
			return 0;
		}
	}
	else {
		if ((temp_t = fopen(fname, "w")) == NULL) {
			printf("Ошибка открытия файла для записи");
			return 0;
		}
	}

	fprintf(temp_t, "Интервал значений: [%f;%f]\n", interval1, interval2);
	fprintf(temp_t, "Шаг табуляции: %f\n\n", tab);
	fprintf(temp_t, "Значения:\n");
	for (float i = interval1; i <= interval2; i+=tab)
	fprintf(temp_t, "%f\n", func(i));

	fclose(temp_t);
	return 1;
}
