docker build -t ros-swerve-env .

docker run --rm -it --name swerve-container -v "$(pwd):/demo" ros-swerve-env


docker cp swerve-container:/opt/ros/jazzy/include ./ros-jazzy-include