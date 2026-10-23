#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class SensorSub : public rclcpp::Node {
public:
  SensorSub() : Node("sensor_sub") {
    sub_ = create_subscription<std_msgs::msg::Float32>(
      "temperature", 10,
      [this](const std_msgs::msg::Float32 & msg) {
        if (msg.data > 30.0f) {
          RCLCPP_WARN(get_logger(), "Too hot: %.1f", msg.data);
        } else {
          RCLCPP_INFO(get_logger(), "Temperature OK: %.1f", msg.data);
        }
      });
  }
private:
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr sub_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SensorSub>());
  rclcpp::shutdown();
  return 0;
}
