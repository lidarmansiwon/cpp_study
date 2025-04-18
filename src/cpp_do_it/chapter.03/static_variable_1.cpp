#include <iostream>
using namespace std;

// 결과는 a는 일정하고 b는 계속 증가함
void func()
{
    int a = 10;
    static int b = 10; // static 때문에 정적 변수로 선언됨. func 함수가 종료되어도 사라지지 않음
    // 그런데 호출 될 때마다 매번 10으로 초기화 될 것 같은데? --> X 아님. func 함수가 처음 호출될 때
    // 한 번만 초기화되며, 그 값은 프로그램이 종료될 때까지 지속됨. 
    static int c;      // 초기화를 안해서 자동으로 0으로 초기화함. 

    a++;
    b++;
    cout << "a: " << a << " , b: " << b << " , c: " << c << endl;
}

int main()
{
    func();
    func();
    func();
    func();
    func();

    int a = 0;
    int b = 1;
    const int *ptr = &a; // *ptr를 상수화 = 포인터 변수 자체를 상수화

    cout << "before ptr: " << *ptr << endl;

    // *ptr = 2; // 컴파일 에러
    ptr = &b; // ptr이 다른 걸 가리키는 건 됨
    a = 3; // 이건 또 됨
    // const가 제한하는 대상이 "포인터를 통해 값을 바꾸는 것"만 금지라는 사실


    cout << "after ptr: " << *ptr << endl;
    cout << "after a: " << a << endl; // a가 변경됨

    // ------------------------------------
    // int a = 0;
    // int b = 1;
    // int *const ptr = &a; // ptr 상수화 = 포인터 변수 자체를 상수화 --> 가리키는 값 a 는 변경 가능함

    // cout << "before ptr: " << *ptr << endl;

    // *ptr = 2; // 가리키는 값 a를 변경 
    // // ptr = &b; // 컴파일 에러

    // cout << "after ptr: " << *ptr << endl;
    // cout << "after a: " << a << endl; // a가 변경됨

    return 0;
}

