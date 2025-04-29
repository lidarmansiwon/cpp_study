#include <iostream>

using namespace std;

// 캐릭터 클래스
class character {
    public:
        character() : hp(100), power(100){};
    
    protected:
        int hp;
        int power;
};

class player : public character {
    public:
        player(){};
};

class monster {
    public:
        monster(){};
        void get_damage(int _damage){};
        void attack(player target_player){};
        virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
    cout << "기본 공격 : 데미지 -10 hp" << endl;
}

class monster_a : public monster, character {
    public:
        // 상속 받은 함수 오버라이딩
        virtual void attack_special(player target_player) override;
        monster_a() : monster_a(10,10) {
            cout << "monster_a 클래스 생성자" << endl;
        };

        monster_a(int x, int y) : location{x, y} {
            cout << "monster_a 클래스 생성자 (매개변수 추가)" << endl;
        };

        void show_location() {
            cout << "위치(" << location[0] << "," << location[1] << ")" << endl;
        };

    private:
        int location[2];
};

void monster_a::attack_special(player target_player) {
    cout << "인텡글 공격 : 데미지 -15 hp" << endl;
}

class monster_b : public monster, character {
    public: 
        // 상속 받은 함수 오버라이딩
        virtual void attack_special(player target_player) override;
};

void monster_b::attack_special(player target_player) {
    cout << "가상 공격 : 데미지 -0 hp" << endl;
}

class monster_c : public monster, character {
    public: 
        void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
    cout << "강력 뇌전 공격 : 데미지 -100 hp" << endl;
}

int main()
{
    player player_1;

    monster_a forest_monster; // 기본 생성자 호출

    forest_monster.show_location();
    monster_a wood_monster(10, 25);  // 매개 변수가 있는 생성자 호출
    wood_monster.show_location();



    return 0;
}
