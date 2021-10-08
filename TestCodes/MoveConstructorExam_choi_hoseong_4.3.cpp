// MoveConstructorExample_4.3.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//
#include <iostream>
using namespace std;

class TData
{
public:

	// (1) �⺻ ������
	TData()
	{
		cout << "�ĺ��ڸ� �����ϴ� ������" << endl;
	}

	// (2) int�� ��ȯ ������
	TData(int nData)
	{
		m_pnData = new int;
		*m_pnData = nData;
		cout << "int Conversion Constructor " << endl;
	}

	//// (3) Shallow Copy Constructor
	//TData(const TData &rhs)
	//{
	//	m_pnData = rhs.m_pnData;
	//	cout << "Shallow Copy Constructor " << endl;
	//}

	// (4) Deep Copy Constructor
	TData(const TData& rhs)
	{
		m_pnData = new int;
		*m_pnData = *rhs.m_pnData;
		cout << "Deep Copy Constructor " << endl;
	}

	// (5) move semantics Constructor
	// ����� �� �Ű������� const�� ������ �ȵɱ��?
	// ������ �翬�� �����ϴ� ��ü�� ������ ���⵿���� �����ؾ� �ϱ� �����Դϴ�.
	// ���⼭ �ʿ��� ���⵿���� ����� ������ �����ͺ����� nullptr�� ����� ���Դϴ�. 
	// ����� �����ͺ����� �츮�� ����� �޸𸮸� �������ϰ� �ִٸ� �� ������ ������� �޸𸮴� �����˴ϴ�.
	// �׷��� �츮�� ���� ���� �ۼ��� �����ʹ� ������ �޸𸮸� �������ϴ� ��۸������Ͱ� �ǹ����ϴ�. 
	// �װ� �������� ����� ������ ������ nullptr�� ����� �ؾ��մϴ�.
	TData(TData&& rhs)
	{
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;
		cout << "Move Constructor " << endl;
	}

	~TData()
	{
		cout << "Destructor" << endl;
		delete(m_pnData);
	}



public:
	// (6) move semantics assignment operator
	// ����� �� �Ű������� const�� ������ �ȵɱ��?
	// ������ �翬�� �����ϴ� ��ü�� ������ ���⵿���� �����ؾ� �ϱ� �����Դϴ�.
	// ���⼭ �ʿ��� ���⵿���� ����� ������ �����ͺ����� nullptr�� ����� ���Դϴ�. 
	// ����� �����ͺ����� �츮�� ����� �޸𸮸� �������ϰ� �ִٸ� �� ������ ������� �޸𸮴� �����˴ϴ�.
	// �׷��� �츮�� ���� ���� �ۼ��� �����ʹ� ������ �޸𸮸� �������ϴ� ��۸������Ͱ� �ǹ����ϴ�. 
	// �װ� �������� ����� ������ ������ nullptr�� ����� �ؾ��մϴ�.
	TData& operator=(TData&& rhs)
	{
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;
		cout << "�̵� ���� ������" << endl;

		return *this;
	}
	

	void PrintData()
	{
		cout << *m_pnData << endl;
	}

	
private:
	int* m_pnData;
};


TData TDataCopy(const TData& ����rhs)
{
	cout << "Begin Func" << endl;
	
	TData �ӽú���(����rhs);

	cout << "End Func" << endl;

	return �ӽú���;
}

int main()
{
	cout << "Begin Main" << endl;
	
	TData Origin(15);

	// 1. �޸𸮸� �������ϰ� ������� ���� ���
	//TDataCopy(Origin);
	// 2. �޸𸮸� �����ϰ� �ĺ��ڸ� �޾��� ���
	TData Copy;
	Copy = TDataCopy(Origin);

	// <1>�� <2>�� ���غ��ø� <1>�� TDataCopy�Լ��� ���� �Ŀ� �ӽð�ü�� �ٷ� �Ҹ��մϴ�.
	// <1>�� <2>�� ���غ��ø� <2>�� �ӽð�ü�� �ĺ��ڰ� ����� ������ Main�� ����ɶ� �Ҹ��մϴ�.

	cout << "End Main" << endl;
    return 0;
}

