#include <iostream> 
#include <Windows.h>
#include <vector>
using namespace std;

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector <string> n; 
	int i = 0;
	bool t = false;
	char a[333];
	cout << "введите предложение: ";
	gets_s(a); 
	cout << "новое предложение: ";
	string r;
	while (a[i] != '\0') { 
		if (a[i] != ' ' and t == false) 
		{
			t = true;
			r += a[i];  
		}
		else if (a[i] != ' ' and t == true and a[i + 1] != '\0') { 
			r += a[i]; 
		}
		else if ((a[i] == ' ' and t == true) or (a[i + 1] == '\0' and t == true)) 
		{
			if (a[i + 1] == '\0') { 
				r += a[i];  
			}
			t = false;
			if (find(begin(n), end(n), r) == end(n)) { 
				n.push_back(r); 
			}
			r = "";
		}
		i++;
	}
	for (int i = 0; i < n.size(); i++) { 
		cout << n[i] << ' ';
	}
}
