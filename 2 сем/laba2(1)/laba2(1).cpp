#include <iostream>
#include <stdio.h> 
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* fileA; 
	errno_t errA; 
	errA = fopen_s(&fileA, "fileA.txt", "r"); 
	if (errA != 0) {
		perror("Ошибка открытия файла!");
		return 1;
	}
	int unique_numbers[100]; 
	int num_unique = 0; 
	int number; 

	while (fscanf_s(fileA, "%d", &number) == 1) { 
		int isDuplicate = 0; 
		for (int i = 0; i < num_unique; i++) { 
			if (unique_numbers[i] == number) {
				isDuplicate = 1;
				break;
			}
		}
		if (!isDuplicate) { 
			unique_numbers[num_unique] = number;
			num_unique++;
		}
	}

	fclose(fileA);
	FILE* fileB; 
	errno_t errB; 
	errB = fopen_s(&fileB, "fileB.txt", "w"); 
	if (errB != 0) {
		perror("Ошибка открытия файла!");
		fclose(fileA);
		return 2;
	}
	for (int i = 0; i < num_unique; i++) { 
		fprintf(fileB, "%d\t", unique_numbers[i]);
	}
	fclose(fileB);
	printf("Программа быстро выполнена!");

	return 0;
}
