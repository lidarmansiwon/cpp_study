#include <iostream>

using namespace std;

struct monster
{
    string name;
    int hp;     // 체력
    int attack; // 공격력
    int defense; // 방어력
    int speed; // 속도
};

void info_moster(monster monster)
{
    cout << monster.name << endl;
    cout << monster.hp << endl;
    cout << monster.attack << endl;
    cout << monster.defense << endl;
    cout << monster.speed << endl;
}

int main()
{
    // 문제 1. 포인터 활용
    int *array_pointer = new int[5];

    for (int i = 0; i < 5; i++)
    {
        array_pointer[i] = i+1;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << array_pointer[i] << endl;
    }
    
    delete[] array_pointer;

    // 문제 2. 구조체 활용
    monster dragon = {"fire dragon", 10, 5, 8, 20};
    info_moster(dragon);

    return 0;
}