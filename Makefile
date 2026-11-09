CXX = g++
CXXFLAGS = -std=c++17 -Isrc -Isrc/lib -Isrc/subSystem $(shell ros2 pkg cflags-libs rclcpp 2>/dev/null || echo "")

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
TARGET = bin/swerve_robot

all: $(TARGET)

$(TARGET): $(OBJ)
	mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	find src -name "*.o" -delete
	rm -f $(TARGET)