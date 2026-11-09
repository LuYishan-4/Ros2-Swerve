#include "rclcpp/rclcpp.hpp"
#include "controller.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Controller>("Swerve");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}