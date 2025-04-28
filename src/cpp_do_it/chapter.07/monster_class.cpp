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

    monster_a forest_monster;
    monster_b tutorial_monster;
    monster_c boss_monster;

    // overriding 공격
    cout << "몬스터 총 공격" << endl;
    forest_monster.attack_special(player_1);
    tutorial_monster.attack_special(player_1);
    boss_monster.attack_special(player_1);

    // 기본 클래스 공격
    forest_monster.monster::attack_special(player_1);
    tutorial_monster.monster::attack_special(player_1);
    boss_monster.monster::attack_special(player_1);

    monster &mon = forest_monster;
    monster_a &mon_a = forest_monster;

    cout << endl << "부모 클래스 레퍼런스로 공격" << endl; // 가상 함수로 인해 부모를 참조해도 자식의 오버라이딩 함수가 호출됨
    mon.attack_special(player_1);

    cout << endl << "자식 클래스 레퍼런스로 공격" << endl;
    mon_a.attack_special(player_1);

    cout << endl << "네임스페이스 활용 공격" << endl;
    mon_a.monster::attack_special(player_1);

    return 0;
}

// monster는 public 으로 상속

// character는 private 으로 상속

// --> 이유

// monster는 외부 인터페이스로 쓰고 싶다.

// monster 안에는 attack(), get_damage() 같은 공개 메서드가 있습니다.

// 즉, monster_a, monster_b, monster_c 객체가 외부에서 attack(), get_damage()를 사용할 수 있어야 하므로 public으로 상속한 것입니다.

// character는 내부에서만 사용하고 싶다.

// character는 hp, power 같은 **데이터 (속성)**만 제공하고 있습니다.

// monster_a 같은 하위 클래스가 이 hp, power를 직접 사용하거나 조작하고 싶지만, 외부(main() 같은 데)에서는 character의 기능이 노출되기를 원치 않습니다.

// 그래서 private 상속을 사용해서 monster_a 내부에서만 character의 멤버를 접근할 수 있게 한 것입니다.

// monster_a는 monster처럼 보일 수 있지만, character처럼 보이게 사용할 수는 없습니다.

// character는 완전히 monster_a 내부의 '비공개 비밀 데이터'처럼만 취급됩니다.

// 비유를 들자면
// monster 상속은 "이 몬스터는 기본적으로 몬스터 행동을 한다"를 외부에 알리는 것.

// character 상속은 "몬스터가 체력과 힘을 가진다"는 내부 구현 디테일일 뿐, 외부에 알리고 싶지 않은 것.