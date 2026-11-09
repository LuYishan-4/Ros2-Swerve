#include "controller.hpp"
#include <iostream>

Controller::Controller(const std::string &node_name) : rclcpp::Node(node_name) {
    std::cout << "init part, node name is: " << this->get_name() << std::endl;
}
Controller::~Controller() {
    std::cout << "done" << std::endl;
}
