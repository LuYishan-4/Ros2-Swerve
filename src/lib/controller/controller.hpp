#pragma once

#include "rclcpp/rclcpp.hpp"
#include "subSystemBase/subSystemBase.hpp"
#include <vector>
#include <memory>
class Controller : public rclcpp::Node {
public:
    explicit Controller(const std::string &node_name = "controller_node");
    ~Controller();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    std::vector<std::shared_ptr<Subsystem>> subsystems_;
};
