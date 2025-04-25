#include <iostream>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

// 운영체제에 따라 다른 헤더를 포함하는 부분.
// #ifdef _WIN32는 현재 운영체제가 Windows인지 확인.
// Windows이면 Windows.h를 포함.
// 아니면(unix 계열이면) unistd.h를 포함.
// 이 구조는 플랫폼에 따라 sleep 같은 기능을 다르게 구현할 때 자주 사용

using namespace std;

class accelerator;
const int dummy = 0;

class engine{
private:
    virtual void acceleraion_output() = 0;
    virtual void reduce_output() = 0;
    friend class accelerator;
};

class ic_engine : public engine {
    private:
        virtual void acceleration_output() = 0;
        virtual void reduce_output() = 0;
};

class gs_engine : public ic_engine {
    private:
        void acceleration_output() override { increasing_fuel(); };
        void reduce_output() override { decreasing_fuel(); };
        void increasing_fuel() { increasing_piston_speed(); };
        void decreasing_fuel() { decreasing_piston_speed(); };
        void increasing_piston_speed() {cout << "increasing_piston_speed" << endl; };
        void decreasing_piston_speed() {cout << "decreasing_piston_speed" << endl; };
};

class elec_engine : public engine {
    private:
        void acceleration_output() override { increasing_motor_speed(); };
        void reduce_output() override { decreasing_motor_speed(); };
        void increasing_motor_speed() {cout << "increasing_motor_speed" << endl; };
        void decreasing_motor_speed() {cout << "decreasing_motor_speed" << endl; };
};
