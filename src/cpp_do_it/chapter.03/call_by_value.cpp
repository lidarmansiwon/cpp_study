#include <iostream>
using namespace std;

// 값을 전달하는 호출 방식을 "값에 의한 호출(call by value)라고 한다."

void swap(int a, int b)
{
    // swap 함수 내 교환 전 a, b 값
    cout << "[swap func] before swap, a: " << a << " b: " << b << endl;

    int temp = a;
    a = b;
    b = temp;

    // swap 함수 내 교환 후 값
    cout << "[swap func] before swap, a: " << a << " b: " << b << endl;
    // swap 함수 내의 지역 변수 a,b만 바뀐거임. 
}

int main()
{
    int a = 5;
    int b = 10;

    // swap 함수 호출 전 a, b 값
    cout << "[main] before swap, a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "[main] after swap, a: " << a << " b: " << b << endl; // 결과가 안바뀜. 
    // 여기의 a, b는 전혀 영향이 없음.\

    return 0;
}