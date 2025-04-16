#include <iostream>

using namespace std;

int main()
{
    char char_value = 'A';
    int int_value   = 123;
    double double_value = 123.456;

    char *char_pointer = &char_value;
    int *int_pointer   = &int_value;
    double *double_pointer = &double_value;

    //일반 변수의 데이터 출력
    cout << "char_value: " << char_value << endl;
    cout << "int_value: "  << int_value << endl;
    cout << "double_value: " << double_value << endl;

    cout << endl;

    // 역참조 연산자로 포인터 변수가 가리키는 데이터 출력

    cout << "char_pointer: " << *char_pointer << endl;
    cout << "int_pointer: " << *int_pointer << endl;
    cout << "double_pointer: " << *double_pointer << endl;

    cout << endl;

    cout << "Change data value using pointer!" << endl;
    // 역참조 연산자로 원본 데이터 덮어쓰기
    *char_pointer = 'Z';
    *int_pointer = 456;
    *double_pointer = 456.123;

    cout << "char_pointer: " << *char_pointer << endl;
    cout << "int_pointer: " << *int_pointer << endl;
    cout << "double_pointer: " << *double_pointer << endl;

    return 0;
}