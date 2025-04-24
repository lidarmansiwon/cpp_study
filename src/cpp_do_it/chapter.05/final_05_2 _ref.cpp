#include <iostream>
#include <random>
#include <stdexcept>
#include <limits>

using namespace std;

int main() {
  // 1부터 100까지 랜덤 숫자 생성
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(1, 100);
  int answer = dist(gen);

  // *count 변수는 문제와는 상관없지만, 게임의 재미를 위해 추가하였습니다.
  // *몇 번만에 숫자 맞히기를 성공하는지 카운트하기 위해 활용되는 변수입니다. :)
  int count = 0;

  // 게임 시작
  bool is_correct = false;
  while (!is_correct) {
    try {
      // 사용자에게 숫자 입력 요청
      ++count;
      cout << "숫자를 입력하세요: ";
      int guess;
      cin >> guess;

      // *숫자가 아닌 입력이 들어왔는지 확인하는 부분입니다.
      // *문제와는 상관없지만, 좀 더 어드밴스한 것을 원하는 독자분들을 위해 특별히 추가한 부분입니다. :)
      if (cin.fail()) {
        cin.clear(); // 입력 스트림의 상태를 초기화
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 버퍼 비우기
        throw invalid_argument("숫자를 입력해주세요!");
      }

      // 입력한 숫자가 범위를 벗어나는지 확인
      if (guess < 1 || guess > 100) {
        throw out_of_range("1부터 100 사이의 숫자를 입력해주세요!");
      }

      // 숫자 비교 후 메시지 출력
      if (guess > answer) {
        cout << "너무 높아요!" << endl << endl;
      }
      else if (guess < answer) {
        cout << "너무 낮아요!" << endl << endl;
      }
      else {
        cout << "축하합니다! 정답은 " << answer << "입니다." << endl;
        cout << count << "번 만에 맞추셨습니다. :)" << endl;
        is_correct = true;
      }
    }
    catch (const exception& e) {
      // 예외 발생 시 에러 메시지 출력
      cerr << e.what() << endl << endl;
    }
  }

  return 0;
}