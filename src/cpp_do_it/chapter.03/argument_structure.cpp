#include <iostream>
using namespace std;

struct Person
{
    std::string name;
    int age;
    float height;
    float weight;
};

void check_age(Person *_adult, int _count)
{
    for (int i = 0; i < _count; i++)
    {
        if (_adult[i].age >= 25)
        {
            cout << "name: " << _adult[i].name << endl;
            cout << "age: "  << _adult[i].age << endl;
            cout << "height: " << _adult[i].height << endl;
            cout << "weight: " << _adult[i].weight << endl; 
            cout << endl;
            
        }
        else
        {
            cout << _adult[i].name << " is to young!" << endl;
        }
    }
}

int main()
{
    Person _adult[] = 
    {
        {"siwon", 26, 173, 73}, 
        {"siwoo", 25, 173, 65},
        {"siyoon", 19, 179, 70},
    };

    Person _adult2[] = 
    {
        {"siwon2", 26, 173, 73}, 
        {"siwoo2", 25, 173, 65},
        {"siyoon2", 19, 179, 70},
    };

    Person _adult3[] = 
    {
        {"siwon3", 26, 173, 73}, 
        {"siwoo3", 25, 173, 65},
        {"siyoon3", 19, 179, 70},
    };


    Person siwon = {"kimsiwon", 26, 173, 73};

    Person *_adult_pointer = _adult; // 배운거 응용차 포인터 사용해봄. 여기서의 *는 포인터 선언을 위함

    check_age(&siwon, 1);            // 이건 배열 구조체가 아니라서 주소를 넘겨야함. 
                                     // 함수의 매개변수가 *포인터 형식이기 때문!
    Person *siwon_pointer = &siwon;  // 이것도 마찬가지 

    check_age(_adult_pointer, 3);

    _adult_pointer = _adult2;        // _adult_pointer는 원래 _adult의 메모리 주소를 가지고 있었음
                                     // 그걸 _adult2의 메모리 주소로 변경

    check_age(_adult_pointer, 3);

    check_age(_adult3, 3);

    return 0;
};
