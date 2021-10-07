#include <atomic>
#include <Windows.h>
#include <iostream>

// 테스트 내용 : atomic과 non atomic의 성능차이 측정
// 테스트 결과 : atomic이 약 50배정도 느리다.

using namespace std;

#define BENCHMARK( name, func, its ) {\
		int st = GetTickCount(); \
			func( its ); \
		printf(" [%s] - %dms\n", name, GetTickCount() - st ); \
	}

void testbed_non_atomic(int n) {
	int value = 1234;
	int* ptr = &value;

	for (int i = 0; i < n; i++) {

		if (ptr != nullptr) 
		{
		}
	}
}
void testbed_atomic(int n) {
	int value = 1234;

	atomic<int*> atomic_ptr(&value);

	for (int i = 0; i < n; i++) {
		int* ptr = atomic_ptr.load();

		if (ptr != nullptr) 
		{
		}
	}
}

int main()
{

	const int its = 100000000;

	BENCHMARK("non-atomic", testbed_non_atomic, its);
	BENCHMARK("atomic", testbed_atomic, its);

	return 0;
}
