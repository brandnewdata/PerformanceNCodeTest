// OverlapedPointer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
using namespace std;


int main(void)
{
	int** ppnTable;
	int nStudentSize;
	int nRecordSize;

	std::cout << "학생의 수는 몇명입니까?" << std::endl;
	std::cin >> nStudentSize;
	
	ppnTable = new int* [nStudentSize];
	
	
	for (int i = 0; i < nStudentSize; i++)
	{
		printf("%d번째 학생은 몇 개의 수업을 듣고 있습니까?", i+1);
		std::cin >> nRecordSize;

		ppnTable[i] = new int[nRecordSize];
	}
	// 할당받은 메모리를 하나 넘어서 참조함.
	// ppnTable[nStudentSize] = nullptr;

	for (int i = 0; i < nStudentSize; i++)
	{
		delete[] ppnTable[i];
	}
	delete[] ppnTable;


	return 0;
}
