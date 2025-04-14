#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 2, c = 8;
    int result_1 = a + b * c; // 곱셈 먼저 계산(오른쪽으로 결합)
    cout << "Result 1: " << result_1 << endl;

    int result_2 = (a+b) * c; // 괄호로 우선 순위 변경
    cout << "Result 2: " << result_2 << endl;

    a += b * c; // 곱셈 먼저 계산
    cout << "Result 3: " << a << endl;

    bool condition = true;
    int result_4 = (condition && a > b) ? a : b; // > 먼저 연산(왼쪽으로 결합)
    cout << "Result 4: " << result_4 << endl;

    return 0;
}