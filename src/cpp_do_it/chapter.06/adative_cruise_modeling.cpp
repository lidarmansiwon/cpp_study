#include <iostream>
#include <studio.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>

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
