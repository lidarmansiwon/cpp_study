#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "mk3_msgs/msg/psi_to_wp.hpp"

using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::String>(
        "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

        psi_sub_ = this->create_subscription<mk3_msgs::msg::PsiToWP>(
        "psi", 10, std::bind(&MinimalSubscriber::psi_callback, this, _1));
    }  
  private:
    void topic_callback(const std_msgs::msg::String & msg) const  
    // const std_msgs::msg::String 형식의 매개변수 선언. 
    // &(레퍼런스 변수(ampersand), msg라는 큰 데이터를 복사하지 않고 참조만 하기 위함, 별칭 부여)
    // const는 그렇게 바로 참조해서 가져온 데이터를 절대 수정하지 않도록 하는 용도, 읽기 용도 강조, 수정 방지
    // 마지막 const --> 이 함수는 멤버 변수들을 변경하지 않는다는 약속
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg.data.c_str());
    }

    void psi_callback(const mk3_msgs::msg::PsiToWP & msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: Psi '%f'", msg.psi);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    rclcpp::Subscription<mk3_msgs::msg::PsiToWP>::SharedPtr psi_sub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
