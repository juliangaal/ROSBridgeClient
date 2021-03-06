//
// Created by Julian on 18.09.18.
//

#include <rbc/msgs/geometry_msgs/quaternion_stamped.h>
#include <rbc/utils/deserializer.h>

using namespace rbc::msgs::geometry_msgs;
using namespace web;

QuaternionStamped::QuaternionStamped(double x, double y, double z, double w, std::string frame_id)
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(frame_id),
    quaternion(x, y, z, w)
{}

QuaternionStamped::QuaternionStamped(const web::json::value &response)
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(),
    quaternion()
{
  utils::Deserializer::deserialize(header, response.at(U("msg")).at(U("header")), true);

  utils::Deserializer::deserialize(quaternion, response.at(U("msg")).at(U("quaternion")), true);
}

QuaternionStamped::QuaternionStamped()
  : ROSTypeBase("geometry_msgs/QuaternionStamped"),
    header(),
    quaternion()
{}

std::ostream &operator<<(std::ostream &os, const QuaternionStamped &q)
{
  os << "\nQuaternion Stamped:";
  os << q.header;
  os << q.quaternion;
  os << "\n";
  return os;
}

std::ostream &operator<<(std::ostream &os, const std::shared_ptr<QuaternionStamped> &q)
{
  return os << *q.get();
}