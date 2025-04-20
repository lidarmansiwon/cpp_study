#include <iostream>

using namespace std;

int main()
{
    int input_number;

    cout << "1~5 정수 입력: ";
    cin >> input_number;

    switch (input_number)
    {
    case 1:
        cout << "Input number is 1." << endl;
        break;
    case 2:
        cout << "Input number is 2." << endl;  
        break;  
    case 3:
        cout << "Input number is 3." << endl;
        break;    
    case 4:
        cout << "Input number is 4." << endl; 
        break;
    case 5:
        cout << "Input number is 5." << endl;    
        break;
    default:
        cout << "Input number is out of range" << endl;
        break;
    }

    return 0;
}