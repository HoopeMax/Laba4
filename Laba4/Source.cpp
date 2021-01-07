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
	std::cout << "\n�������� ����� ���������� "<<std::endl;
	std::cout << "1 - ���������� �������. " << std::endl;
	std::cout << "2 - ���������� �������� . " << std::endl;
	std::cout << "3 - ������ ����������. " << std::endl;
	std::cout << "4 - ���������� ���������.\n ->  ";//�������, � ���� � �������� ���������
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
		std::cout << "������ ������ ���\n " << std::endl;
		break;
	}
	std::cout << "��������� ���������� \n " << std::endl;
	object.show();		
	std::cout << std::endl;
	printf("Seconds = %.4lf\n", (clock() - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}