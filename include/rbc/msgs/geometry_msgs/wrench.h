//
// Created by Julian on 18.09.18.
//

#ifndef ROSBRIDGECLIENT_WRENCH_HPP
#define ROSBRIDGECLIENT_WRENCH_HPP

#include <cpprest/json.h>
#include <rbc/msgs/ros_type_base.h>
#include <rbc/msgs/geometry_msgs/vector3.h>
#include <memory>
#include <iostream>

namespace rbc::msgs::geometry_msgs
{

struct Wrench : public ROSTypeBase
{
  Wrench();

  Wrench(double lx, double ly, double lz, double ax, double ay, double az);

  Wrench(const Vector3 &linear, const Vector3 &angular);

  explicit Wrench(const web::json::value &response);

  ~Wrench() override = default;

  Vector3 force;
  Vector3 torque;
};

} // namespace rbc::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const rbc::msgs::geometry_msgs::Wrench &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<rbc::msgs::geometry_msgs::Wrench> &p);

#endif //ROSBRIDGECLIENT_WRENCH_HPP