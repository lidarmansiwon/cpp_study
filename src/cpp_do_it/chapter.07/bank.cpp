#include <iostream>

using namespace std;

class bank {
    private:
        int safe; // 금고
        string bank_name;
        int *safe_ptr = &safe;
    public:
        bank(string name) : bank_name(name) {safe = 1000; };
        ~bank() {};
        void usr_counter(int _in, int _out); // 입출금 창구 함수
        bool check_working();
        void transfer_account(int send_money, bank &where);
        
};

void bank::transfer_account(int send_money, bank &where) {
    this->safe -= send_money;
    where.safe += send_money;
    cout << endl;
    cout << where.bank_name << "으로 송금 : " << send_money << endl;
    cout << endl;
    cout << bank_name << "출금 금고 :" << this->safe << endl;
    cout << where.bank_name << "입금 금고 :" << where.safe << endl;

};

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

    cout << bank_name << "처리 - 입금 : " << _in << endl;
    cout << bank_name << "처리 - 출금 : " << _out << endl;
    cout << bank_name << "처리 - 금고 : " << safe << endl;
};

int main() {
    // bank my_bank; // my_bank 인스턴트 생성
    bank a_bank("A 은행"), b_bank("B 은행");
    bool bank_door_a = true;
    bool bank_door_b = true;
    int in_a;
    int out_a;
    int in_b;
    int out_b;
    int trans_to_a;
    
    while (bank_door_a || bank_door_b){
        cout << "A 은행 입금 금액 : ";
        cin >> in_a;
    
        cout << "A 은행 출금 금액 : ";
        cin >> out_a;
    
        a_bank.usr_counter(in_a, out_a);
        bank_door_a = a_bank.check_working();

        cout << "B 은행 입금 금액 : ";
        cin >> in_b;
    
        cout << "B 은행 출금 금액 : ";
        cin >> out_b;
    
        b_bank.usr_counter(in_b, out_b);
        bank_door_b = b_bank.check_working();

        cout << "A 은행으로 계좌 이동 : ";
        cin >> trans_to_a;

        b_bank.transfer_account(trans_to_a, a_bank);
        bank_door_b = b_bank.check_working();
        bank_door_a = a_bank.check_working();

    }
    return 0;

}


