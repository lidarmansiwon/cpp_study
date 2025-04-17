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


add_executable(talker src/basic_pub_sub/cpp_basic_pub.cpp)
ament_target_dependencies(talker rclcpp std_msgs mk3_msgs)

add_executable(listener src/basic_pub_sub/cpp_basic_sub.cpp)
ament_target_dependencies(listener rclcpp std_msgs mk3_msgs)

## Chapter.2
add_executable(implicit_cast src/cpp_do_it/chapter.02/implicit_cast.cpp)
add_executable(operator_precedence src/cpp_do_it/chapter.02/operator_precedence.cpp)


## Chapter.3
add_executable(pointer src/cpp_do_it/chapter.03/pointer.cpp)
add_executable(new_and_delete src/cpp_do_it/chapter.03/new_and_delete.cpp)
add_executable(function_ src/cpp_do_it/chapter.03/function.cpp)


install(TARGETS
  ## ROS2
  talker
  listener
  ## Chapter.2
  implicit_cast
  operator_precedence
  
  ## Chapter.3
  pointer
  new_and_delete
  function_
  DESTINATION lib/${PROJECT_NAME})

ament_package()
