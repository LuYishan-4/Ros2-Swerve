#pragma once

#include "rclcpp/rclcpp.hpp"

class Controller : public rclcpp::Node {
public:
    explicit Controller(const std::string &node_name = "controller_node");
    ~Controller();
};
