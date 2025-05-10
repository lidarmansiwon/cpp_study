#include <iostream>
#include <string>

using namespace std;

class character {
public:
  character() : hp(100), power(100), location{ 0,0 }, level(1) {
  };
  void move(int x, int y) {};
  void move(int x[], int y[], int spot_count) {}
  void get_damage(int _damage) {};
  int get_hp() { return hp; };
  int get_level() { return level; };

protected:
  int hp;
  int power;
  int location[2];
  int level;
};

class player : public character {
public:
  player() {};
};

//기본 Monster 클래스
class monster {
public:
  void attack(player target_player) {};
  virtual void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
  cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

//몬스터 C는 기본 Monster 클래스로부터 상속
class monster_c : public monster, public character {
public:
  //상속받은 함수 오버라이딩
  void attack_special(player target_player) override;
  monster_c operator+(monster_c &operand); // 덧셈 연산자 오버로딩 선언
  monster_c operator+(player &operand); // 다른 클래스의 객체를 덧셈하기 위한 오버로딩 선언
  void set_level(int level_value) { level = level_value; };
  void set_hp(int hp_value) { hp = hp_value; };
};

// 덧셈 연산자 오버로딩 구현
monster_c monster_c::operator+(monster_c& operand) {
  monster_c result_monster;
  result_monster.set_level(level + operand.get_level());
  return result_monster;
}

monster_c monster_c::operator+(player &operand) {
    monster_c result_monster;
    result_monster.set_hp(hp + operand.get_hp());
    return result_monster;
}

void monster_c::attack_special(player target_player) {
  cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main() {

    monster_c monster_c_obj1, monster_c_obj2;
    monster_c_obj2.set_level(2);
    monster_c new_monster_c_obj = monster_c_obj1 + monster_c_obj2;

    cout << "합체전 몬스터C #1 Level[" << monster_c_obj1.get_level()
        << "], 몬스터C #2 Level[" << monster_c_obj2.get_level()
        << "]" << endl;

    cout << "합체 후 몬스터C Level[" << new_monster_c_obj.get_level()
        << "]" << endl;

    player player_1;
    
    cout << "Player 합체 전 몬스터 C HP[" << new_monster_c_obj.get_hp() << "]" << endl;
    
    new_monster_c_obj = new_monster_c_obj + player_1;

    cout << "Player 합체 후 몬스터 C HP[" << new_monster_c_obj.get_hp() << "]" << endl;



    return 0;     
}
// 체력을 나타내는 멤버 변수 hp를 public으로 공유하여 덧셈할 수도 있음. 하지만 몬스터 삭제, 체력 제한 등, 전처리와 
// 후처리를 위해서 hp를 protected로 숨기고(은닉화) 멤버 함수나 연산자 오버로딩을 활용하는 것이 
// 객체지향 프로그래밍에 더 가깝다. 

