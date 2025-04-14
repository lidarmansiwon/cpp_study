cmake_minimum_required(VERSION 3.8)
project(cpp_study)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)       # 이는 패키지를 빌드할 때 이 두 패키지를 찾으라는 의미
find_package(std_msgs REQUIRED)     # ''
find_package(mk3_msgs REQUIRED)


add_executable(talker src/cpp_basic_pub.cpp)
ament_target_dependencies(talker rclcpp std_msgs mk3_msgs)

add_executable(listener src/cpp_basic_sub.cpp)
ament_target_dependencies(listener rclcpp std_msgs mk3_msgs)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
