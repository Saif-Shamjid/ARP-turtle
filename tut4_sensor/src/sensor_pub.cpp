#include <chrono>
#include <cstdlib>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
using namespace std::chrono_literals;

class SensorPub : public rclcpp::Node {
public:
  SensorPub() : Node("sensor_pub") {
    pub_ = create_publisher<std_msgs::msg::Float32>("temperature", 10);
    timer_ = create_wall_timer(500ms, [this]() {
      std_msgs::msg::Float32 msg;
      msg.data = 15.0f + static_cast<float>(std::rand() % 2000) / 100.0f;  // 15 to 35
      RCLCPP_INFO(get_logger(), "Publishing: %.1f", msg.data);
      pub_->publish(msg);
    });
  }
private:
  rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SensorPub>());
  rclcpp::shutdown();
  return 0;
}
