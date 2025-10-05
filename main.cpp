#include <iostream>
#include <Windows.h>

void InputTask();					// ������ - 21 ( ����� ������� )
void IfTask(int task);				// ������ - 53 ( ������� ������� ��������� � ����� ������� ����� ��� ������� ������� )
void Task1();						// ������ - 63
void Task2();						// ������ - 108
void Task3();						// ������ - 147
int SumHalf(int num, bool half);	// ������ - 201 ( ��������� ����� �� �� ������� ����� )
void Exit();						// ������ - 21 ( ������� ������� ����������, ��� ��� ������ ������� ��� ��������� ������ )
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	InputTask();
	
	return 0;
}

void InputTask()
{
	int task{};

	while (true)
	{
		std::cout << "�������� ����������� ������ 1, 2, 3 ����� �������������� ��������: ";
		std::cin >> task;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			std::cout << "��������, �� �� ����� ������, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else if (task != 1 && task != 2 && task != 3)
		{
			std::cout << "��������, �� �� ����� �������� ��������, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else
		{
			system("pause");
			system("cls");
			IfTask(task);
			break;
		}
	}
}

void IfTask(int task)
{
	switch (task)
	{
	case 1: Task1(); break;
	case 2: Task2(); break;
	case 3: Task3(); break;
	}
}

void Task1()
{
	int* inputNum = new int{};

	std::cout << "\t\t\t\t\t������������ ����������� �����" << std::endl;
	while (true)
	{
		std::cout << "������� ������������ �����: ";
		std::cin >> *inputNum;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			std::cout << "��������, �� �� ����� ������, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else if (*inputNum < 100000 || *inputNum > 999999)
		{
			std::cout << "��������, �� �� ����� �� ������������ �����, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else
		{
			system("pause");
			system("cls");
			break;
		}
	}
	std::cout << std::endl;
	if (SumHalf(*inputNum, false) == SumHalf(*inputNum, true))
	{
		std::cout << "\t\t\t\t\t����������! ������ ����� ����������!!!" << std::endl << std::endl;
	}
	else
	{
		std::cout << "\t\t\t\t\t��������... ������ ����� �� �����������..." << std::endl << std::endl;
	}

	delete inputNum;

	Exit();
}
void Task2()
{
	unsigned short* inputNum = new unsigned short{};

	std::cout << "\t\t\t��������� �������� 1 - 2 ����� �������, 3 - 4 ����� �������" << std::endl;
	while (true)
	{
		std::cout << "������� �������������� �����: ";
		std::cin >> *inputNum;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
			std::cout << "��������, �� �� ����� ������, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else if (*inputNum < 1000 || *inputNum > 9999)
		{
			std::cout << "��������, �� �� ����� �� �������������� �����, ������� ��� ���" << std::endl;
			system("pause");
			system("cls");
		}
		else
		{
			system("pause");
			system("cls");
			break;
		}
	}
	*inputNum = (*inputNum / 1000 % 10 * 100) + (*inputNum / 100 % 10 * 1000) + (*inputNum / 10 % 10) + (*inputNum % 10 * 10);

	std::cout << "��� ���� ���������� �����: " << std::endl << *inputNum << std::endl;

	delete inputNum;

	Exit();
}
void Task3()
{
	const short size = 7;
	int* nums = new int[size]{};
	int* max = new int{};

	std::cout << "\t\t��������� ������� ���������� ����� �� 7 ����� ������� ���� ������������ ����� ����������" << std::endl;
	system("pause");
	system("cls");

	for (int i = 0; i < size; i++)
	{
		while (true)
		{
			std::cout << "������� ����� ����� " << i + 1 << ": ";
			std::cin >> nums[i];
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				std::cout << "��������, �� �� ����� ������, ������� ��� ���" << std::endl;
				system("pause");
				system("cls");
			}
			else
			{
				system("pause");
				system("cls");
				break;
			}
		}
	}
	*max = nums[0];
	for (int i = 0; i < size; i++)
	{
		if (*max < nums[i])
		{
			*max = nums[i];
		}
	}
	std::cout << "�� �����: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "������������ �����: " << *max << std::endl;

	delete max;
	delete[] nums;

	Exit();
}

int SumHalf(int num, bool half)
{
	if (!half)
	{
		return (num / 100000 % 10) + (num / 10000 % 10) + (num / 1000 % 10);
	}
	else
	{
		return (num / 100 % 10) + (num / 10 % 10) + (num % 10);
	}
}

void Exit()
{
	int* exit = new int{};
	system("pause");
	system("cls");
	std::cout << "������� 0 ���� ������ ������� ����� ������, ������ - �����: ";
	std::cin >> *exit;
	if (*exit != 0 || std::cin.fail())
	{
		std::cout << "��������!" << std::endl << std::endl;
	}
	else
	{
		delete exit;

		system("pause");
		system("cls");
		InputTask();
	}
}