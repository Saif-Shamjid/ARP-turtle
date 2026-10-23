#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"

class CounterSub : public rclcpp::Node {
public:
  CounterSub() : Node("counter_sub"), total_(0) {
    sub_ = create_subscription<std_msgs::msg::Int32>(
      "count", 10,
      [this](const std_msgs::msg::Int32::SharedPtr msg) {
        total_ += msg->data;
        RCLCPP_INFO(get_logger(), "Received %d, running total %d", msg->data, total_);
      });
  }
private:
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr sub_;
  int total_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CounterSub>());
  rclcpp::shutdown();
  return 0;
}
