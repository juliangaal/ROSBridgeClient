//
// Created by julian on 01.11.18.
//

#include <ros_bridge_client/utils/response_converter.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped.h>

using namespace ros_bridge_client::msgs::geometry_msgs;

TwistStamped::TwistStamped()
  : MessageBase("geometry_msgs/TwistStamped"),
    header(),
    twist()
{}

TwistStamped::TwistStamped(const Twist &twist, std::string frame_id)
  : MessageBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(twist)
{}

TwistStamped::TwistStamped(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id)
  : MessageBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(lx, ly, lz, ax,ay, az)
{}

TwistStamped::TwistStamped(const Vector3 &linear, const Vector3 &angular, std::string frame_id)
  : MessageBase("geometry_msgs/TwistStamped"),
    header(frame_id),
    twist(linear, angular)
{}

TwistStamped::TwistStamped(const web::json::value &response)
  : MessageBase("geometry_msgs/TwistStamped")
{
  const auto &msg = response.at(U("msg"));
  const auto &twist_msg = msg.at(U("twist"));

  std::tie(header.seq, header.stamp.sec, header.stamp.nsec, header.frame_id) =
    utils::ResponseConverter::responseToHeader(msg.at(U("header")), true);

  std::tie(twist.linear.x, twist.linear.y, twist.linear.z) =
    utils::ResponseConverter::responseToVector3(twist_msg.at(U("linear")), true);

  std::tie(twist.angular.x, twist.angular.y, twist.angular.z) =
    utils::ResponseConverter::responseToVector3(twist_msg.at(U("angular")), true);
}

std::ostream &operator<<(std::ostream &os, const TwistStamped &p)
{
  os << "\nTwist Stamped:";
  os << p.header;
  os << p.twist;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<TwistStamped> &p)
{
  return os << p.get();
}