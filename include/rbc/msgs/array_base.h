//
// Created by julian on 11.12.18.
//

#ifndef ROSBRIDGECLIENT_ARRAY_BASE_H
#define ROSBRIDGECLIENT_ARRAY_BASE_H

#include <rbc/msgs/ros_type_base.h>
#include <string>
#include <vector>

namespace rbc::msgs
{

template<typename T>
struct ArrayBase : public ROSTypeBase
{
  ArrayBase() = delete;

  explicit ArrayBase(std::string ros_msg_type);

  ~ArrayBase() override = default;

  std::vector<T> data;
};

template<typename T>
ArrayBase<T>::ArrayBase(std::string ros_msg_type)
  : ROSTypeBase(ros_msg_type)
{}

} // namespace rbc::msgs

#endif //ROSBRIDGECLIENT_ARRAY_BASE_H
