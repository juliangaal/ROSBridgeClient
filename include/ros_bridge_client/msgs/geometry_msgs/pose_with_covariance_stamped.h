//
// Created by Julian on 27.10.18.
//

#ifndef ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_STAMPED_H
#define ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_STAMPED_H

#include <cpprest/json.h>
#include <ros_bridge_client/msgs/ros_type_base.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance.h>

namespace ros_bridge_client::msgs::geometry_msgs
{

struct PoseWithCovarianceStamped : public ROSTypeBase
{
  PoseWithCovarianceStamped();

  PoseWithCovarianceStamped(const Point &p, const Quaternion &q, const std::array<double, 36> &arr, std::string frame_id = "world");

  PoseWithCovarianceStamped(const Pose &pose, const std::array<double, 36> &arr, std::string frame_id = "world");

  explicit PoseWithCovarianceStamped(const PoseWithCovariance &pose, std::string frame_id = "world");

  explicit PoseWithCovarianceStamped(const web::json::value &response);

  ~PoseWithCovarianceStamped() final = default;

  PoseWithCovariance pose;
  std_msgs::Header header;
};

} // namespace ros_bridge_client::msgs::geometry_msgs

std::ostream &operator<<(std::ostream &os, const ros_bridge_client::msgs::geometry_msgs::PoseWithCovarianceStamped &p);

std::ostream &
operator<<(std::ostream &os, const std::shared_ptr<ros_bridge_client::msgs::geometry_msgs::PoseWithCovarianceStamped> &p);

#endif //ROSBRIDGECLIENT_POSE_WITH_COVARIANCE_STAMPED_H
