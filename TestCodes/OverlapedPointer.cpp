// OverlapedPointer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include <iostream>
using namespace std;


int main(void)
{
	int** ppnTable;
	int nStudentSize;
	int nRecordSize;

	std::cout << "�л��� ���� ����Դϱ�?" << std::endl;
	std::cin >> nStudentSize;
	
	ppnTable = new int* [nStudentSize];
	
	
	for (int i = 0; i < nStudentSize; i++)
	{
		printf("%d��° �л��� �� ���� ������ ��� �ֽ��ϱ�?", i+1);
		std::cin >> nRecordSize;

		ppnTable[i] = new int[nRecordSize];
	}
	// �Ҵ���� �޸𸮸� �ϳ� �Ѿ ������.
	// ppnTable[nStudentSize] = nullptr;

	for (int i = 0; i < nStudentSize; i++)
	{
		delete[] ppnTable[i];
	}
	delete[] ppnTable;


	return 0;
}
