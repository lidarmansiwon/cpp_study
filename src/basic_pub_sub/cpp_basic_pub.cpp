// C++ Standard lib 
#include <chrono>
#include <functional>
#include <memory>
#include <string>

// C++ ROS lib
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "mk3_msgs/msg/psi_to_wp.hpp"

// 매번 입력하는 것을 대체 
using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
    public:
    MinimalPublisher()
    : Node("minimal_publisher"), count_(0) // public constructor(생성자), MinimalPublisher 정의, constructor node 이름을 정의하고, count를 0으로 초기화 // ! 생성자란 -> 객체 지향 프로그래밍에서 객체를 생성할 때 초기화하는 함수
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10); // publisher_가 string 타입 메시지 이용하도록 선언, topic이 가지고 있을 수 있는 message의 한계 개수는 10개
        timer_     = this->create_wall_timer(
        500ms, std::bind(&MinimalPublisher::timer_callback, this));              // timer_라는 변수에 timer_callback 함수를 선언, 주기는 500ms(1초에 2번) 

        psi_publisher_ = this->create_publisher<mk3_msgs::msg::PsiToWP>("psi", 10);

    }

    private:
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hellow, world! " + std::to_string(count_++);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);

        auto psi_message = mk3_msgs::msg::PsiToWP();
        psi_message.psi = float(count_++);
        psi_publisher_->publish(psi_message);
    }
    // 상단에 사용된 멤버변수를 하단에서 정의
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Publisher<mk3_msgs::msg::PsiToWP>::SharedPtr psi_publisher_;
    size_t count_;

};

// 클래스를 main함수에서 생성하여 기능하도록하는 코드
int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);                               // ROS2 를 초기화
    rclcpp::spin(std::make_shared<MinimalPublisher>());     // MinimalPublisher class에 정의된 publisher 코드 실행
    rclcpp::shutdown();                                     // ROS2 종료
    return 0;
}
