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
