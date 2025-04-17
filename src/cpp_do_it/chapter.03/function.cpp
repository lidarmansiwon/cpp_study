#include <iostream>
using namespace std;

int add(int _x, int _y)
{
    int result = _x + _y;
    return result;
}

// 일반 변수를 매개 변수로 사용하기
void change_negative(int _val)
{
    if (_val > 0)
    {
        _val = -_val;
    }
}

// 포인터를 매개 변수로 사용하기 
void change_negative_pointer(int *_val) // 매개 변수가 포인터 변수로 변경됨!
//* 포인터 변수 == 메모리를 저장하는 변수!
// 함수를 호출할 때 주솟값을 전달했으므로 이를 받으려면 포인터 변수로 선언해야함!
// 위 함수(change_negative)와 다르게 *(역참조 연산자)를 사용해 포인터 변수가 가리키는 데이터에 직접 접근!
// 저장된 값이 모두 영향을 받음!
{
    if (*_val > 0)
    {
        *_val = -(*_val);
    }
}

// 배열을 매개 변수로 사용하기
int average(int _array[], int _count)
{
    int sum = 0;
    for (int i = 0; i < _count; i++)
    {
        sum += _array[i];
    }

    // 아래 main 문에서 계산하는 size와 다른 이유
    // _array[]로 함수 인자를 받는 과정에서 
    // C++에서는 배열을 함수의 인자로 전달할 때 배열이 포인터로 decay(변형) 돼서 전달된다. 
    // 즉, _array는 사실상 int* _array로 해석
    
    int score_size = 0;
    score_size = sizeof(_array)/sizeof(int);
    cout << "score_size in function: " << score_size << endl;

    return (sum/_count);
}

int main()
{
    int add_result = add(2, 3); // add 함수 호출    
    cout << "add 함수 결과: " << add_result << endl;


    int a, b;
    a = 3;
    b = -4;

    change_negative(a); // 변수에 영향 안받음 
    change_negative(b);

    cout << "change_negative(a): " << a << endl;
    cout << "change_negative(b): " << b << endl;


    // 포인터를 매개 변수로 사용하기 
    cout << endl;
    cout << "---포인터를 매개 변수로 사용하기--" << endl;

    change_negative_pointer(&a); // a의 주소값을 전달
    change_negative_pointer(&b); // b의 주소값을 전달

    cout << "change_negative_pointer(a): " << a << endl;
    cout << "change_negative_pointer(b): " << b << endl;

    cout << endl;
    // 배열을 매개 변수로 사용하기 
    cout << "---배열을 매개 변수로 사용하기--" << endl;

    int score[5] = {90, 75, 80, 100, 65};
    int score_size = 0;
    score_size = sizeof(score)/sizeof(int);
    cout << "score_size: " << score_size << endl;


    cout << "평균 점수: " << average(score, score_size) << endl;


    return 0;
}