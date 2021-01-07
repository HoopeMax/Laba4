#include <initializer_list>
template <typename variableType>
class Vector
{
private:
	enum exites
	{
		EMPTY = true,
		FULL = false
	};

	unsigned short length = 0;
	unsigned int counter = 0;
	variableType* p_arr = new variableType[length];
public:

	//����������� �� ���������.
	Vector()
	{

	}

	//����������� ��� ����� ������ ��������.
	Vector(variableType value)
	{
		length = 1;
		variableType* p_buff_arr = new variableType[length];
		p_buff_arr[0] = value;
		delete[] p_arr;
		p_arr = p_buff_arr;
	}

	//����������� ��� ����� ������ ����������.
	Vector(std::initializer_list<variableType> value)
	{
		length = value.size();
		variableType* p_buff_arr = new variableType[length];
		for (unsigned short step(0); step < length; step++)
		{
			p_buff_arr[step] = *(value.begin() + step);
		}
		delete[] p_arr;
		p_arr = p_buff_arr;
	}

	//����������
	~Vector()
	{
		delete[] p_arr;
	}

	//������� ����� �������.
	short size()
	{
		return length;
	}

	//�������� ����� ������� �� Pos ���������. �������� ������ �������� �� �������� Value.
	void resize(short pos, variableType value = variableType())
	{
		if (pos != length)
		{
			variableType* p_buffer_arr = new variableType[pos];
			if (pos < length)
			{
				for (short step(0); step < pos; step++)
				{
					p_buffer_arr[step] = p_arr[step];
				}
			}
			else
			{
				for (short step(0); step < length; step++)
				{
					p_buffer_arr[step] = p_arr[step];
				}
				for (short step(length); step < pos; step++)
				{
					p_buffer_arr[step] = value;
				}
			}
			length = pos;
			delete[] p_arr;
			p_arr = p_buffer_arr;
		}
	}

	//���������� ������ �� ��������� ��� ���.
	bool empty()
	{
		if (length == 0) return EMPTY;
		else return FULL;
	}

	//��������� ������� � ����� �������.
	void push_back(variableType value)
	{
		length++;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < length - 1; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		p_buffer_arr[length - 1] = value;
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//������� ������� � ����� �������.
	void pop_back()
	{
		length--;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//��������� ������� � ������ �������.
	void insert(variableType value)
	{
		length++;
		variableType* p_buffer_arr = new variableType[length];
		p_buffer_arr[0] = value;
		for (short step(1); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step - 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//��������� Elem ��������� � ������ ������� � Pos_Start �� ��������� Value.
	void insert(short pos_start, short elem, variableType value)
	{
		length += elem;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < pos_start; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		for (short step(pos_start); step < pos_start + elem; step++)
		{
			p_buffer_arr[step] = value;
		}
		for (short step(pos_start + elem); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step - elem];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//��������� ������������� ���������� ������ ������.
	variableType front()
	{
		return p_arr[0];
	}

	//��������� ������������� ���������� ��������� ������.
	variableType back()
	{
		return p_arr[length - 1];
	}

	//������� ����� ��������� ������� �������.
	void erase(short pos)
	{
		length--;
		variableType* p_buffer_arr = new variableType[length];
		for (short step(0); step < pos; step++)
		{
			p_buffer_arr[step] = p_arr[step];
		}
		for (short step(pos); step < length; step++)
		{
			p_buffer_arr[step] = p_arr[step + 1];
		}
		delete[] p_arr;
		p_arr = p_buffer_arr;
	}

	//������ ��� ������ ������� �������.
	void clear()
	{
		length = 0;
		delete[] p_arr;
		p_arr = nullptr;
	}

	// ���������� �������.
	void swap()
	{
		if (typeid(variableType) != typeid(bool))
		{
			unsigned int M;
			unsigned int temp;
			for (unsigned short i(0); i < length; i++)
			{
				M = i;
				for (unsigned short j(i + 1); j < length; j++)
				{
					counter++;
					if (p_arr[j] < p_arr[M])
					{
						M = j;
					}
				}
				if (M != i)
				{
					temp = p_arr[i];
					p_arr[i] = p_arr[M];
					p_arr[M] = temp;
					counter++;
				}
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "����� swap �� ����� �������� � �������� �����������.\n\a";
		}
	}

	//���������� �������� 
	void swap1()
	{
		if (typeid(variableType) != typeid(bool))
		{
			unsigned int temp;
			int flag = 0;
			for (int i = 0; i < length; i++)
			{
				do
				{
					flag = 0;
					for (int j = 0; j < length - i; j++)
					{
						if (p_arr[j - 1] > p_arr[j])
						{
							temp = p_arr[j - 1];
							p_arr[j - 1] = p_arr[j];
							counter++;
							p_arr[j] = temp;
							flag = 1;
						}

					}
					for (int k = length - 1 - i; k < i; k++)
					{
						if (p_arr[k - 1] > p_arr[k])
						{
							temp = p_arr[k - 1];
							p_arr[k - 1] = p_arr[k];
							counter++;
							p_arr[k] = temp;

						}
					}
				} while (flag != 0);
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "����� swap �� ����� �������� � �������� �����������.\n\a";
		}
	}

	// ������ ����������
	void swap2() 
	{
		if (typeid(variableType) != typeid(bool))
		{
			unsigned int temp;
			unsigned int i = 1;
			unsigned int j = 2;
			while (i < length)
			{
				if (p_arr[i - 1] < p_arr[i])
				{
					i = j;
					j = j + 1;
				}
				else
				{
					temp = p_arr[i - 1];
					p_arr[i - 1] = p_arr[i];
					p_arr[i] = temp;
					i = i - 1;

					counter++;

					if (i == 0)
					{
						i = j;
						j = j + 1;
					}
				}
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "����� swap �� ����� �������� � �������� �����������.\n\a";
		}
	}

	// ���������� ���������
	void swap3() 
	{
		if (typeid(variableType) != typeid(bool))
		{
			unsigned int M;
			unsigned int temp;
			int j;
			for (unsigned short i(1); i < length; i++)
			{

				temp = p_arr[i];
				j = i;
				while (p_arr[j - 1] > temp && j > 0)
				{
					p_arr[j] = p_arr[j - 1];
					counter++;
					j--;

				}
				p_arr[j] = temp;
			}
		}
		else
		{
			setlocale(LC_ALL, "russian");
			std::cout << "����� swap �� ����� �������� � �������� �����������.\n\a";
		}
	}

	//������������� ��� �������� �������.(!��������� - ����� �������!!)
	void show()
	{
		for (short step(0); step < length; step++)
		{
			std::cout << p_arr[step] << " ";
		}
		std::cout << "\nQuantity of elements = " << length << "\n";
		std::cout << "\nCounter = " << counter << "\n";
	}
};