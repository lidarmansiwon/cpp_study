#include <iostream>
#include <random>

using namespace std;

int main()
{   
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(1, 100);
    int answer = dist(gen);

    // 게임 시작
    bool is_correct = false;
    while(!is_correct){
        try{

            int get;
            cout << "무작위 숫자를 입력하세요: "; 
            cin >> get;

            if (get > 100 || get < 1)
            {
                throw out_of_range("1부터 100 사이의 숫자를 입력해주세요.");
            }
            if (get < answer)
            {
                cout << "숫자가 너무 작아요" << endl;
            }
            else if (get > answer)
            {
                cout << "숫자가 너무 커요" << endl;
            }
            else
            {
                cout << "축하합니다!" << endl;
                is_correct = true;
            }

        }
        catch (const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
    
}