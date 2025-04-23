#include <iostream>

using namespace std;

int main()
{   
    try
    {
        int month;
        int day;

        cout << "월을 입력하세요: ";
        cin >> month;
    
        if (month > 12 || month < 1)
        {
            cout << "std::out_of_range" <<endl;
            throw "std::out_of_range";
        }

        cout << "일을 입력하세요: ";
        cin >> day;

        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10
        || month == 12)
        {
            if (day > 31 || day < 1)
            {
                throw "std::out_of_range";
            }
        }
        else if (month == 2)
        {
            if (day > 28 || day < 1)
            {
                throw "std::out_of_range";
            }  
        }
        else
        {
            if (day > 30 || day < 1)
            {
                throw "std::out_of_range";
            }
        }

        if (month >= 3 && month <= 5)
        {
            cout << "입력하신 날짜의 계절은 봄입니다." << endl;
        }
        else if(month >= 6 && month <= 8)
        {
            cout << "입력하신 날짜의 계절은 여름입니다." << endl;
        }
        else if(month >= 9 && month <= 11)
        {
            cout << "입력하신 날짜의 계절은 가을입니다." << endl;
        }
        else if(month <=2 || month == 12)
        {
            cout << "입력하신 날짜의 계절은 겨울입니다." << endl;
        }


    }
    catch(char c) 
    {   
        cout << c << endl;
    }
    
}