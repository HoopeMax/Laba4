#include <iostream>
#include "Vector.h"
#include <ctime>

int main(void)
{
	setlocale(LC_ALL, "rus");
	bool flag = true;
	int metod = 0;
	double start = clock();
	Vector<int> object({ 3, 4 ,6, 8, 9 ,7, 5 });
	object.insert(1, 1, 2);
	object.show();
	std::cout << "\nВыберете метод сортировки "<<std::endl;
	std::cout << "1 - Сортировка выбором. " << std::endl;
	std::cout << "2 - Сортировка шейкером . " << std::endl;
	std::cout << "3 - Гномья сортировка. " << std::endl;
	std::cout << "4 - Сортировка вставками.\n ->  ";//Проверь, у меня с ошибками сортирует
	std::cin >> metod;
	switch (metod)
	{
	case 1:
	{
		object.swap();
		break;
	}
	case 2:
	{
		object.swap1();
		break;
	}
	case 3:
	{
		object.swap2();
		break;
	}
	case 4:
	{
		object.swap3();
		break;
	}
	default:
		std::cout << "Такого метода нет\n " << std::endl;
		break;
	}
	std::cout << "Результат сортировки \n " << std::endl;
	object.show();		
	std::cout << std::endl;
	printf("Seconds = %.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}