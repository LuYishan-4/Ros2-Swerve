#include "controller.hpp"
#include <iostream>
#include "subSystem/driveSubsystem.hpp"

Controller::Controller(const std::string &node_name) : rclcpp::Node(node_name) {
    subsystems_.push_back(std::make_shared<DriveSubsystem>());
}
Controller::~Controller() {
    std::cout << "done" << std::endl;
}
