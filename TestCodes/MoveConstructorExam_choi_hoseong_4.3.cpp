// MoveConstructorExample_4.3.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <iostream>
using namespace std;

class TData
{
public:

	// (1) 기본 생성자
	TData()
	{
		cout << "식별자만 생성하는 생성자" << endl;
	}

	// (2) int형 변환 생성자
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
	// 여기는 왜 매개변수를 const로 받으면 안될까요?
	// 이유는 당연히 참조하는 객체의 변수에 쓰기동작을 수행해야 하기 때문입니다.
	// 여기서 필요한 쓰기동작은 사라질 변수의 포인터변수를 nullptr로 덮어쓰는 것입니다. 
	// 사라질 포인터변수가 우리가 사용할 메모리를 포인팅하고 있다면 그 변수가 사라질때 메모리는 해제됩니다.
	// 그러면 우리가 지금 새로 작성한 포인터는 해제된 메모리를 포인팅하는 댕글링포인터가 되버립니다. 
	// 그걸 막으려면 사라질 포인터 변수는 nullptr로 덮어쓰기 해야합니다.
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
	// 여기는 왜 매개변수를 const로 받으면 안될까요?
	// 이유는 당연히 참조하는 객체의 변수에 쓰기동작을 수행해야 하기 때문입니다.
	// 여기서 필요한 쓰기동작은 사라질 변수의 포인터변수를 nullptr로 덮어쓰는 것입니다. 
	// 사라질 포인터변수가 우리가 사용할 메모리를 포인팅하고 있다면 그 변수가 사라질때 메모리는 해제됩니다.
	// 그러면 우리가 지금 새로 작성한 포인터는 해제된 메모리를 포인팅하는 댕글링포인터가 되버립니다. 
	// 그걸 막으려면 사라질 포인터 변수는 nullptr로 덮어쓰기 해야합니다.
	TData& operator=(TData&& rhs)
	{
		m_pnData = rhs.m_pnData;
		rhs.m_pnData = nullptr;
		cout << "이동 대입 연산자" << endl;

		return *this;
	}
	

	void PrintData()
	{
		cout << *m_pnData << endl;
	}

	
private:
	int* m_pnData;
};


TData TDataCopy(const TData& 원본rhs)
{
	cout << "Begin Func" << endl;
	
	TData 임시복사(원본rhs);

	cout << "End Func" << endl;

	return 임시복사;
}

int main()
{
	cout << "Begin Main" << endl;
	
	TData Origin(15);

	// 1. 메모리를 생성만하고 사용하지 않은 경우
	//TDataCopy(Origin);
	// 2. 메모리를 생성하고 식별자를 달아준 경우
	TData Copy;
	Copy = TDataCopy(Origin);

	// <1>과 <2>를 비교해보시면 <1>은 TDataCopy함수가 끝난 후에 임시객체가 바로 소멸합니다.
	// <1>과 <2>를 비교해보시면 <2>는 임시객체의 식별자가 생겼기 때문에 Main이 종료될때 소멸합니다.

	cout << "End Main" << endl;
    return 0;
}

