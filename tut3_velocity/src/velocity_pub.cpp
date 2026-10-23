#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
using namespace std::chrono_literals;

class VelocityPub : public rclcpp::Node {
public:
  VelocityPub() : Node("velocity_pub") {
    pub_ = create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = create_wall_timer(500ms, [this]() {
      geometry_msgs::msg::Twist msg;
      msg.linear.x = 0.2;    // forward speed (m/s)
      msg.angular.z = 0.5;   // turn rate (rad/s)
      RCLCPP_INFO(get_logger(), "Publishing: linear.x=%.2f angular.z=%.2f",
                  msg.linear.x, msg.angular.z);
      pub_->publish(msg);
    });
  }
private:
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<VelocityPub>());
  rclcpp::shutdown();
  return 0;
}
