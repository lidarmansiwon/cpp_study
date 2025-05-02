#include <iostream>
using namespace std;

class monster {
    public:
        monster() {
            cout << "monster 생성자" << endl;
        };
        // ~monster() {
        //     cout << "monster 소멸자" << endl; 
        // }; --> 이렇게 하면 monster_a 클래스의 소멸자가 호출이 안됨. 이 객체가 먼저 소멸돼서
        virtual ~monster() {
            cout << "monster 소멸자" << endl;
        };


};

class monster_a : public monster {
    public:
        monster_a() {
            cout << "monster_a 생성자" << endl;
        };

        // ~monster_a() {
        //     cout << "monster_a 소멸자" << endl;
        // };
        virtual ~monster_a() {
            cout << "monster_a 소멸자" << endl;
        };  
};

int main() {
    monster *forest_monsetr = new monster_a();
    delete forest_monsetr; // 메모리 해제
    return 0;
}
