#include <iostream>
#include <array>

using namespace std;

// public의 잘못된 사용으로 인한 문제 예시
class manage_data_structure_public {
    public: 
    manage_data_structure_public();
    int current_index;
    array<int, 10> data_queue;
};

manage_data_structure_public::manage_data_structure_public() :
    current_index(0), data_queue{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}{}

// 올바른 객체지향 원칙에 따른 코드 작성
class manage_data_structure_private {
    public: 
    manage_data_structure_private();
    int get_current_index() {return current_index; };
    void set_current_index(int new_index);
    int get_array_value() { return data_queue[current_index]; };

    private:
    int current_index;
    array<int, 10> data_queue;
};

manage_data_structure_private::manage_data_structure_private() :
    current_index(0), data_queue{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}{}

void manage_data_structure_private::set_current_index(int new_index) {
    if (new_index < 0 || new_index >= 10)
        return;
    current_index = new_index;
}


     

int main(void) {
    // public의 잘못된 사용으로 인한 문제 예시
    int data;
    manage_data_structure_public data_structure;
    data_structure.current_index = -1; // 이렇게 public으로 되어있으니 막 접근해서 수정할 수 있음. 
    data = data_structure.data_queue[data_structure.current_index];
    cout << "Data [" << data_structure.current_index << "]" << data << endl;

    // 올바른 객체지향 원칙에 따른 코드 작성
    int data_pri, index;
    manage_data_structure_private data_structure_pri;
    data_structure_pri.set_current_index(-1);
    index = data_structure_pri.get_current_index();
    data = data_structure_pri.get_array_value();

    cout << "Data [" << index << "]" << data << endl;
    // --> 멤버 변수는 될 수 있으면 private으로 선언하고 멤버 함수에서 접근하도록 구현

    return 0;
}