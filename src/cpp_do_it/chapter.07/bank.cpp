#include <iostream>

using namespace std;

class bank {
    private:
        int safe; // 금고
    public:
        bank(); // 기본 생성자
        void usr_counter(int _in, int _out); // 입출금 창구 함수
        bool check_working();
        
};

bank::bank() {
    safe = 1000; // 은행 금고 초기 금액 설정
    cout << "최초 금고 : " << safe << endl;
    cout << endl;

}
bool bank::check_working() {
    if (safe <= 0) 
    {
        cout << "금일 창구 영업 마감" << endl;
        return false; 
    }
    else
    {
        return true;
    }
}

void bank::usr_counter(int _in, int _out) {
    safe += _in;
    safe -= _out;

    cout << "입금 : " << _in << endl;
    cout << "출금 : " << _out << endl;
    cout << "금고 : " << safe << endl;
};

int main() {
    bank my_bank; // my_bank 인스턴트 생성
    bool bank_door = true;
    int in;
    int out;
    
    while (bank_door){
        cout << "입금 금액 : ";
        cin >> in;
    
        cout << "출금 금액 : ";
        cin >> out;
    
        my_bank.usr_counter(in, out);
        bank_door = my_bank.check_working();
    }
    return 0;

}


