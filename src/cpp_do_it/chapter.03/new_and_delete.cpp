#include <iostream>
#include <string>
using namespace std;

int main()
{
    int *pt_int_value = new int; // 동적 메모리 할당
    *pt_int_value = 100;
    cout << *pt_int_value << endl;
    
    delete pt_int_value; // 동적 메모리 해제 int 자료형


    int *pt_int_array_value = new int[5];

    for (int i = 0; i < 5; i++)
    {
        pt_int_array_value[i] = i;
    }

    cout << *pt_int_array_value << endl;

    delete[] pt_int_array_value; // 동적 메모리 해제(배열)

    int customer_num = 0;

    cout << "오늘 방문 손님: ";
    cin >> customer_num;

    string *bread = new string[customer_num]; // 손님 수만큼 string 배열 생성

    for (int i = 0; i < customer_num; i++) // 입력 받은 손님 수만큼 반복
    {
        bread[i] = "빵_" + to_string(i); // '빵 숫자' 형태로 배열에 저장
    }

    cout << endl << "생산된 빵 --" << endl;

    for (int i = 0; i < customer_num; i++)  
    {
        cout << *(bread + i) << endl;

    }

    delete[] bread;

    return 0;
}