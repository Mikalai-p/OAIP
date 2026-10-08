#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i = 0, star = 0, dlina = 0, num = 0, max_dlina = 0, star_slova = 0, num_slova = 0; 
	bool k = false;
	char a[333];
	cout << "Введите ряд: ";
	gets_s(a); 
	while (*(a + i) != '\0') {
		if (*(a + i) != ' ' and k == false) 
		{
			k = true;
			star = i;
			dlina += 1;
			num += 1;
		}  
		else if (*(a + i) != ' ' and k == true and *(a + i + 1) != '\0')
		{
			dlina += 1;
		}
		else if (*(a + i) == ' ' or *(a + i + 1) == '\0')
		{
			if (*(a + i + 1) == '\0')
			{
				dlina += 1;
			} 
			k = false;
			if (dlina > max_dlina)
			{
				max_dlina = dlina;
				star_slova = star;
				num_slova = num;
			}
			dlina = 0;
		}
		i++;
	}
	cout << "Слово по счёту: " << num_slova << endl;
	cout << "Порядковый номер 1 символа слова: " << star_slova + 1 << endl; 
}
