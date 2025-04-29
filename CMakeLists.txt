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
add_executable(argument_structure src/cpp_do_it/chapter.03/argument_structure.cpp)
add_executable(static_variable_1 src/cpp_do_it/chapter.03/static_variable_1.cpp)
add_executable(call_by_value src/cpp_do_it/chapter.03/call_by_value.cpp)
add_executable(final_exam src/cpp_do_it/chapter.03/final_exam.cpp)

## Chapter.4
add_executable(switch src/cpp_do_it/chapter.04/switch.cpp)
add_executable(final_04 src/cpp_do_it/chapter.04/final_04.cpp)

## Chatper.5
add_executable(try_throw_catch_1 src/cpp_do_it/chapter.05/try_throw_catch_1.cpp)
add_executable(assert src/cpp_do_it/chapter.05/assert.cpp)
add_executable(final_05 src/cpp_do_it/chapter.05/final_05.cpp)
add_executable(final_05_ref src/cpp_do_it/chapter.05/final_05_ref.cpp)
add_executable(final_05_2 src/cpp_do_it/chapter.05/final_05_2.cpp)

## Chapter.6
add_executable(adative_cruise_modeling src/cpp_do_it/chapter.06/adative_cruise_modeling.cpp)

## Chapter.7
add_executable(bank src/cpp_do_it/chapter.07/bank.cpp)
add_executable(monster_class src/cpp_do_it/chapter.07/monster_class.cpp)
add_executable(monster_with_parameter src/cpp_do_it/chapter.07/monster_with_parameter.cpp)



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
  argument_structure
  static_variable_1
  call_by_value
  final_exam

  ## Chapter.4
  switch
  final_04

  ## Chapter.5
  try_throw_catch_1
  assert
  final_05
  final_05_2
  final_05_ref

  ## Chapter.6
  adative_cruise_modeling

  ## Chapter.7
  bank
  monster_class
  monster_with_parameter

  DESTINATION lib/${PROJECT_NAME})

ament_package()
