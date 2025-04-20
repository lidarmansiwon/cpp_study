# include <iostream>
using namespace std;

int main()
{   
    cout << endl;
    cout << "문제 1 if 문 활용하기\n" << endl;

    int input_value;
    cout << "Input value: ";
    cin >> input_value;

    if (input_value >= 0)
    {
        cout << "Input value > 0" << endl;
    }
    else
    {
        cout << "Input value < 0" << endl;
    }

    cout << endl;
    cout << "문제 2 switch 문 활용하기\n" << endl;

    int input_value2;
    cout << "Input value2(range 1~7): ";
    cin >> input_value2;

    switch (input_value2)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Tursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default :
        cout << "다른 수를 해주세요" << endl;
    }

    cout << endl;
    cout << "문제 3 while 문 활용하기\n" << endl;

    int value = 0;
    while (value <= 10)
    {
        if (value % 2 == 0)
        {
            cout << value << endl;
        };
        value ++;
    }


    cout << endl;
    cout << "문제 4 for 문 활용하기\n" << endl;

    int input_value3;

    while (true)
    {
        cout << "문제 4, 1~9 범위 내의 정수를 입력해주세요\n";
        cin >> input_value3;

        if (input_value3 >= 1 && input_value3 <= 9)
        {
            break;
        }
        cout << "유효하지 않은 숫자입니다. 다시 입력해주세요\n" ;
    }


    for (int i = 1; i < 10; i++)
    {   
        cout << input_value3<< "에 대한 구구단 출력" << endl;
        cout << input_value3*i << endl;
    }

    return 0;
}