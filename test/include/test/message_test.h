//
// Created by Julian on 15.09.18.
//

#ifndef ROSBRIDGECLIENT_Test_TEST_HPP
#define ROSBRIDGECLIENT_Test_TEST_HPP

#include <test/csv_reader.h>
#include <cpprest/ws_client.h>
#include <ros_bridge_client/ros_bridge_client.h>

#include <ros_bridge_client/msgs/message.h>
#include <ros_bridge_client/msgs/std_msgs/int8.h>
#include <ros_bridge_client/msgs/std_msgs/int16.h>
#include <ros_bridge_client/msgs/std_msgs/int32.h>
#include <ros_bridge_client/msgs/std_msgs/int64.h>
#include <ros_bridge_client/msgs/std_msgs/uint8.h>
#include <ros_bridge_client/msgs/std_msgs/uint16.h>
#include <ros_bridge_client/msgs/std_msgs/uint32.h>
#include <ros_bridge_client/msgs/std_msgs/uint64.h>
#include <ros_bridge_client/msgs/std_msgs/string.h>
#include <ros_bridge_client/msgs/std_msgs/header.h>
#include <ros_bridge_client/msgs/std_msgs/color_rgba.h>
#include <ros_bridge_client/msgs/std_msgs/float32.h>
#include <ros_bridge_client/msgs/std_msgs/float64.h>

#include <ros_bridge_client/msgs/geometry_msgs/pose.h>
#include <ros_bridge_client/msgs/geometry_msgs/point.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist.h>
#include <ros_bridge_client/msgs/geometry_msgs/point32.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose2d.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench.h>
#include <ros_bridge_client/msgs/geometry_msgs/vector3.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/point_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/wrench_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/inertia_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/transform_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/accel_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/utils/covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/quaternion_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance.h>
#include <ros_bridge_client/msgs/geometry_msgs/pose_with_covariance_stamped.h>
#include <ros_bridge_client/msgs/geometry_msgs/twist_with_covariance_stamped.h>

using namespace ros_bridge_client::msgs;

namespace test
{

struct DataFrame
{
  DataFrame() = delete;

  DataFrame(const test::CSVReader &reader)
      : reader(reader),
        data(reader.getData())
  {}

  ~DataFrame() = default;

  const test::CSVReader &reader;
  const std::unordered_map<std::string, std::vector<std::string>> &data;
};

struct Test
{
  Test() = default;

  virtual ~Test() = default;

  template<typename T>
  inline std::string messageToString(const T &t) const
  {
    Message<T> msg(t);
    return msg.toString();
  }
};

struct HeaderTest : public Test
{
  explicit HeaderTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("HeaderTest")[0]),
        test2(dataframe.data.at("HeaderTest")[1])
  {}

  ~HeaderTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(std::string frame_id = "world") const
  {
    std_msgs::Header msg(frame_id);
    return messageToString<std_msgs::Header>(msg);
  }
};


struct StringTest : public Test
{
  StringTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("StringTest")[0]),
        test2(dataframe.data.at("StringTest")[1])
  {}

  ~StringTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(std::string message) const
  {
    std_msgs::String msg(message);
    return messageToString(msg);
  }
};

struct Float32Test : public Test
{
  Float32Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Float32Test")[0]),
        test2(dataframe.data.at("Float32Test")[1])
  {}

  ~Float32Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(float message) const
  {
    std_msgs::Float32 msg(message);
    return messageToString(msg);
  }
};

struct Float64Test : public Test
{
  Float64Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Float64Test")[0]),
        test2(dataframe.data.at("Float64Test")[1])
  {}

  ~Float64Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double message) const
  {
    std_msgs::Float64 msg(message);
    return messageToString(msg);
  }
};

struct UInt8Test : public Test
{
  UInt8Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("UInt8Test")[0]),
        test2(dataframe.data.at("UInt8Test")[1])
  {}

  ~UInt8Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(uint8_t message) const
  {
    std_msgs::UInt8 msg(message);
    return messageToString(msg);
  }
};

struct UInt16Test : public Test
{
  UInt16Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("UInt16Test")[0]),
        test2(dataframe.data.at("UInt16Test")[1])
  {}

  ~UInt16Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(uint16_t message) const
  {
    std_msgs::UInt16 msg(message);
    return messageToString(msg);
  }
};

struct UInt32Test : public Test
{
  UInt32Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("UInt32Test")[0]),
        test2(dataframe.data.at("UInt32Test")[1])
  {}

  ~UInt32Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(uint32_t message) const
  {
    std_msgs::UInt32 msg(message);
    return messageToString(msg);
  }
};

struct UInt64Test : public Test
{
  UInt64Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("UInt64Test")[0]),
        test2(dataframe.data.at("UInt64Test")[1])
  {}

  ~UInt64Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(uint64_t message) const
  {
    std_msgs::UInt64 msg(message);
    return messageToString(msg);
  }
};

struct Int8Test : public Test
{
  Int8Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Int8Test")[0]),
        test2(dataframe.data.at("Int8Test")[1])
  {}

  ~Int8Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(int8_t message) const
  {
    std_msgs::Int8 msg(message);
    return messageToString(msg);
  }
};

struct Int16Test : public Test
{
  Int16Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Int16Test")[0]),
        test2(dataframe.data.at("Int16Test")[1])
  {}

  ~Int16Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(int16_t message) const
  {
    std_msgs::Int16 msg(message);
    return messageToString(msg);
  }
};

struct Int32Test : public Test
{
  Int32Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Int32Test")[0]),
        test2(dataframe.data.at("Int32Test")[1])
  {}

  ~Int32Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(int32_t message) const
  {
    std_msgs::Int32 msg(message);
    return messageToString(msg);
  }
};

struct Int64Test : public Test
{
  Int64Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Int64Test")[0]),
        test2(dataframe.data.at("Int64Test")[1])
  {}

  ~Int64Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(int64_t message) const
  {
    std_msgs::Int64 msg(message);
    return messageToString(msg);
  }
};

struct ColorRGBATest : public Test
{
  ColorRGBATest(const DataFrame &dataframe)
      : test1(dataframe.data.at("ColorRGBATest")[0]),
        test2(dataframe.data.at("ColorRGBATest")[1])
  {}

  ~ColorRGBATest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(float r, float g, float b, float a) const
  {
    std_msgs::ColorRGBA msg(r, g, b, a);
    return messageToString(msg);
  }
};

//struct ColorRGBATest : public Test
//{
//  ColorRGBATest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("ColorRGBATest")[0]),
//        test2(dataframe.data.at("ColorRGBATest")[1])
//  {}
//
//  ~ColorRGBATest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(float r, float g, float b, float a) const
//  {
//    std_msgs::ColorRGBATest msg(r, g, b, a);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessage(const ColorRGBA &c) const
//  {
//    std_msgs::ColorRGBATest msg(c);
//    return messageToString(msg);
//  }
//};
//
//
struct Point32Test : public Test
{
  explicit Point32Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Point32Test")[0]),
        test2(dataframe.data.at("Point32Test")[1])
  {}

  ~Point32Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(float x, float y, float z) const
  {
    geometry_msgs::Point32 msg(x, y, z);
    return messageToString(msg);
  }
};

struct PointTest : public Test
{
  explicit PointTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PointTest")[0]),
        test2(dataframe.data.at("PointTest")[1])
  {}

  ~PointTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z) const
  {
    geometry_msgs::Point msg(x, y, z);
    return messageToString<geometry_msgs::Point>(msg);
  }
};

struct Pose2DTest : public Test
{
  explicit Pose2DTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("Pose2DTest")[0]),
        test2(dataframe.data.at("Pose2DTest")[1])
  {}

  ~Pose2DTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double theta) const
  {
    geometry_msgs::Pose2D msg(x, y, theta);
    return messageToString<geometry_msgs::Pose2D>(msg);
  }
};


struct PointStampedTest : public Test
{
  explicit PointStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PointStampedTest")[0]),
        test2(dataframe.data.at("PointStampedTest")[1])
  {}

  ~PointStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, std::string frame_id = "world") const
  {
    geometry_msgs::PointStamped msg(x, y, z, frame_id);
    return messageToString<geometry_msgs::PointStamped>(msg);
  }
};

struct Vector3Test : public Test
{
  explicit Vector3Test(const DataFrame &dataframe)
      : test1(dataframe.data.at("Vector3Test")[0]),
        test2(dataframe.data.at("Vector3Test")[1])
  {}

  ~Vector3Test() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z) const
  {
    geometry_msgs::Vector3 msg(x, y, z);
    return messageToString<geometry_msgs::Vector3>(msg);
  }
};

struct Vector3StampedTest : public Test
{
  explicit Vector3StampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("Vector3StampedTest")[0]),
        test2(dataframe.data.at("Vector3StampedTest")[1])
  {}

  ~Vector3StampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, std::string frame_id = "world") const
  {
    geometry_msgs::Vector3Stamped msg(x, y, z, frame_id);
    return messageToString<geometry_msgs::Vector3Stamped>(msg);
  }
};

struct PoseTest : public Test
{
  explicit PoseTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PoseTest")[0]),
        test2(dataframe.data.at("PoseTest")[1])
  {}

  ~PoseTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww) const
  {
    geometry_msgs::Pose msg(x, y, z, xx, yy, zz, ww);
    return messageToString<geometry_msgs::Pose>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Point &point, const geometry_msgs::Quaternion &quaternion) const
  {
    geometry_msgs::Pose msg(point, quaternion);
    return messageToString<geometry_msgs::Pose>(msg);
  }
};

struct PoseWithCovarianceTest : public Test
{
  explicit PoseWithCovarianceTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PoseWithCovarianceTest")[0]),
        test2(dataframe.data.at("PoseWithCovarianceTest")[1])
  {}

  ~PoseWithCovarianceTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww,
                                const std::array<double, 36> &arr) const
  {
    geometry_msgs::PoseWithCovariance msg(x, y, z, xx, yy, zz, ww, arr);
    return messageToString<geometry_msgs::PoseWithCovariance>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Point &point, const geometry_msgs::Quaternion &quaternion,
             const std::array<double, 36> &arr) const
  {
    geometry_msgs::PoseWithCovariance msg(point, quaternion, arr);
    return messageToString<geometry_msgs::PoseWithCovariance>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Pose &pose, const std::array<double, 36> &arr) const
  {
    geometry_msgs::PoseWithCovariance msg(pose, arr);
    return messageToString<geometry_msgs::PoseWithCovariance>(msg);
  }
};

struct PoseWithCovarianceStampedTest : public Test
{
  explicit PoseWithCovarianceStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PoseWithCovarianceStampedTest")[0]),
        test2(dataframe.data.at("PoseWithCovarianceStampedTest")[1])
  {}

  ~PoseWithCovarianceStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string
  getMessage(const geometry_msgs::Point &point, const geometry_msgs::Quaternion &quaternion,
             const std::array<double, 36> &arr, std::string frame_id = "world") const
  {
    geometry_msgs::PoseWithCovarianceStamped msg(point, quaternion, arr, frame_id);
    return messageToString<geometry_msgs::PoseWithCovarianceStamped>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Pose &pose, const std::array<double, 36> &arr, std::string frame_id = "world") const
  {
    geometry_msgs::PoseWithCovarianceStamped msg(pose, arr, frame_id);
    return messageToString<geometry_msgs::PoseWithCovarianceStamped>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::PoseWithCovariance &pose, std::string frame_id = "world") const
  {
    geometry_msgs::PoseWithCovarianceStamped msg(pose, frame_id);
    return messageToString<geometry_msgs::PoseWithCovarianceStamped>(msg);
  }
};

struct PoseStampedTest : public Test
{
  explicit PoseStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("PoseStampedTest")[0]),
        test2(dataframe.data.at("PoseStampedTest")[1])
  {}

  ~PoseStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double xx, double yy, double zz, double ww,
                                std::string frame_id = "world") const
  {
    geometry_msgs::PoseStamped msg(x, y, z, xx, yy, zz, ww, frame_id);
    return messageToString<geometry_msgs::PoseStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Pose &pose, std::string frame_id = "world") const
  {
    geometry_msgs::PoseStamped msg(pose, frame_id);
    return messageToString<geometry_msgs::PoseStamped>(msg);
  }
};

struct QuaternionTest : public Test
{
  explicit QuaternionTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("QuaternionTest")[0]),
        test2(dataframe.data.at("QuaternionTest")[1])
  {}

  ~QuaternionTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double w) const
  {
    geometry_msgs::Quaternion msg(x, y, z, w);
    return messageToString<geometry_msgs::Quaternion>(msg);
  }
};

struct QuaternionStampedTest : public Test
{
  explicit QuaternionStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("QuaternionStampedTest")[0]),
        test2(dataframe.data.at("QuaternionStampedTest")[1])
  {}

  ~QuaternionStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x, double y, double z, double w, std::string frame_id = "world") const
  {
    geometry_msgs::QuaternionStamped msg(x, y, z, w, frame_id);
    return messageToString<geometry_msgs::QuaternionStamped>(msg);
  }
};

struct AccelTest : public Test
{
  explicit AccelTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("AccelTest")[0]),
        test2(dataframe.data.at("AccelTest")[1])
  {}

  ~AccelTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double lx, double ly, double lz, double ax, double ay, double az) const
  {
    geometry_msgs::Accel msg(lx, ly, lz, ax, ay, az);
    return messageToString<geometry_msgs::Accel>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular) const
  {
    geometry_msgs::Accel msg(linear, angular);
    return messageToString<geometry_msgs::Accel>(msg);
  }
};

struct AccelStampedTest : public Test
{
  AccelStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("AccelStampedTest")[0]),
        test2(dataframe.data.at("AccelStampedTest")[1])
  {}

  ~AccelStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string
  getMessage(double lx, double ly, double lz, double ax, double ay, double az,
             std::string frame_id = "world") const
  {
    geometry_msgs::AccelStamped msg(lx, ly, lz, ax, ay, az, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular,
                                std::string frame_id = "world") const
  {
    geometry_msgs::AccelStamped msg(linear, angular, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Accel &accel, std::string frame_id = "world")
  {
    geometry_msgs::AccelStamped msg(accel, frame_id);
    return messageToString<geometry_msgs::AccelStamped>(msg);
  }
};


struct TwistTest : public Test
{
  TwistTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TwistTest")[0]),
        test2(dataframe.data.at("TwistTest")[1])
  {}

  ~TwistTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double lx, double ly, double lz, double ax, double ay, double az) const
  {
    geometry_msgs::Twist msg(lx, ly, lz, ax, ay, az);
    return messageToString<geometry_msgs::Twist>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular) const
  {
    geometry_msgs::Twist msg(linear, angular);
    return messageToString<geometry_msgs::Twist>(msg);
  }
};

struct TwistStampedTest : public Test
{
  TwistStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TwistStampedTest")[0]),
        test2(dataframe.data.at("TwistStampedTest")[1])
  {}

  ~TwistStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(const geometry_msgs::Twist &t, std::string frame_id = "world") const
  {
    geometry_msgs::TwistStamped msg(t, frame_id);
    return messageToString<geometry_msgs::TwistStamped>(msg);
  }

  inline std::string
  getMessage(double lx, double ly, double lz, double ax, double ay, double az, std::string frame_id = "world") const
  {
    geometry_msgs::TwistStamped msg(lx, ly, lz, ax, ay, az, frame_id);
    return messageToString<geometry_msgs::TwistStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &linear, const geometry_msgs::Vector3 &angular,
                                std::string frame_id = "world") const
  {
    geometry_msgs::TwistStamped msg(linear, angular, frame_id);
    return messageToString<geometry_msgs::TwistStamped>(msg);
  }
};

struct TwistWithCovTest : public Test
{
  TwistWithCovTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TwistWithCov")[0]),
        test2(dataframe.data.at("TwistWithCov")[1])
  {}

  ~TwistWithCovTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(const geometry_msgs::TwistWithCovariance &twist) const
  {
    return messageToString<geometry_msgs::TwistWithCovariance>(twist);
  }

  inline std::string getMessage(const geometry_msgs::Twist &twist, const std::array<double, 36> &covariance) const
  {
    geometry_msgs::TwistWithCovariance twist_cov(twist, covariance);
    return messageToString<geometry_msgs::TwistWithCovariance>(twist_cov);
  }

  inline std::string
  getMessage(const geometry_msgs::Vector3 &vec1, const geometry_msgs::Vector3 &vec2,
             const std::array<double, 36> &covariance) const
  {
    geometry_msgs::TwistWithCovariance twist_cov(vec1, vec2, covariance);
    return messageToString<geometry_msgs::TwistWithCovariance>(twist_cov);
  }
};

struct TwistWithCovarianceStampedTest : public Test
{
  TwistWithCovarianceStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TwistWithCovStamped")[0]),
        test2(dataframe.data.at("TwistWithCovStamped")[1])
  {}

  ~TwistWithCovarianceStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string
  getMessage(const geometry_msgs::TwistWithCovariance &twist, std::string frame_id = "world") const
  {
    geometry_msgs::TwistWithCovarianceStamped twist_cov(twist, frame_id);
    return messageToString<geometry_msgs::TwistWithCovarianceStamped>(twist_cov);
  }

  inline std::string
  getMessage(const geometry_msgs::Twist &twist,
             const std::array<double, 36> &covariance, std::string frame_id = "world") const
  {
    geometry_msgs::TwistWithCovarianceStamped twist_cov(twist, covariance, frame_id);
    return messageToString<geometry_msgs::TwistWithCovarianceStamped>(twist_cov);
  }

  inline std::string
  getMessage(const geometry_msgs::Vector3 &vec1, const geometry_msgs::Vector3 &vec2,
             const std::array<double, 36> &covariance, std::string frame_id = "world") const
  {
    geometry_msgs::TwistWithCovarianceStamped twist_cov(vec1, vec2, covariance, frame_id);
    return messageToString<geometry_msgs::TwistWithCovarianceStamped>(twist_cov);
  }
};

struct TransformTest : public Test
{
  TransformTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TransformTest")[0]),
        test2(dataframe.data.at("TransformTest")[1])
  {}

  ~TransformTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double a, double b, double c, double d, double e, double f, double g) const
  {
    geometry_msgs::Transform msg(a, b, c, d, e, f, g);
    return messageToString<geometry_msgs::Transform>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Vector3 &translation, const geometry_msgs::Quaternion &rotation) const
  {
    geometry_msgs::Transform msg(translation, rotation);
    return messageToString<geometry_msgs::Transform>(msg);
  }
};


struct TransformStampedTest : public Test
{
  TransformStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("TransformStampedTest")[0]),
        test2(dataframe.data.at("TransformStampedTest")[1])
  {}

  ~TransformStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double tx, double ty, double tz, double fx, double fy, double fz, double fw,
                                std::string frame_id = "world") const
  {
    geometry_msgs::TransformStamped msg(tx, ty, tz, fx, fy, fz, fw, frame_id);
    return messageToString<geometry_msgs::TransformStamped>(msg);
  }

  inline std::string
  getMessage(const geometry_msgs::Vector3 &translation, const geometry_msgs::Quaternion &rotation,
             std::string frame_id = "world") const
  {
    geometry_msgs::TransformStamped msg(translation, rotation, frame_id);
    return messageToString<geometry_msgs::TransformStamped>(msg);
  }
};

struct WrenchTest : public Test
{
  WrenchTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("WrenchTest")[0]),
        test2(dataframe.data.at("WrenchTest")[1])
  {}

  ~WrenchTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(double x1, double y1, double z1, double x2, double y2, double z2) const
  {
    geometry_msgs::Wrench msg(x1, y1, z1, x2, y2, z2);
    return messageToString<geometry_msgs::Wrench>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &force, const geometry_msgs::Vector3 &torque) const
  {
    geometry_msgs::Wrench msg(force, torque);
    return messageToString<geometry_msgs::Wrench>(msg);
  }
};

//
struct WrenchStampedTest : public Test
{
  WrenchStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("WrenchStampedTest")[0]),
        test2(dataframe.data.at("WrenchStampedTest")[1])
  {}

  ~WrenchStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string
  getMessage(double x1, double y1, double z1, double x2, double y2, double z2,
             std::string frame_id = "world") const
  {
    geometry_msgs::WrenchStamped msg(x1, y1, z1, x2, y2, z2, frame_id);
    return messageToString<geometry_msgs::WrenchStamped>(msg);
  }

  inline std::string getMessage(const geometry_msgs::Vector3 &force, const geometry_msgs::Vector3 &torque,
                                std::string frame_id = "world") const
  {
    geometry_msgs::WrenchStamped msg(force, torque, frame_id);
    return messageToString<geometry_msgs::WrenchStamped>(msg);
  }
};

//
//struct PolygonTest : public Test
//{
//  PolygonTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PolygonTest")[0]),
//        test2(dataframe.data.at("PolygonTest")[1])
//  {}
//
//  ~PolygonTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Point32 &point) const
//  {
//    geometry_msgs::PolygonTest msg(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessageWithAdd(const Point32 &point) const
//  {
//    geometry_msgs::PolygonTest msg;
//    msg.add(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//};
//
//struct PolygonStampedTest : public Test
//{
//  PolygonStampedTest(const DataFrame &dataframe)
//      : test1(dataframe.data.at("PolygonStampedTest")[0]),
//        test2(dataframe.data.at("PolygonStampedTest")[1])
//  {}
//
//  ~PolygonStampedTest() final = default;
//
//  const std::string test1;
//  const std::string test2;
//
//  inline std::string getMessage(const Point32 &point, std::string frame_id = "world") const
//  {
//    geometry_msgs::PolygonStampedTest msg(point, frame_id);
//    msg.add(point);
//    return messageToString(msg);
//  }
//
//  inline std::string getMessageWithAdd(const Point32 &point, std::string frame_id = "world") const
//  {
//    geometry_msgs::PolygonStampedTest msg(frame_id);
//    msg.add(point);
//    msg.add(point);
//    return messageToString(msg);
//  }
//};
//
struct InertiaTest : public Test
{
  InertiaTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("InertiaTest")[0]),
        test2(dataframe.data.at("InertiaTest")[1])
  {}

  ~InertiaTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(const geometry_msgs::Inertia &inertia) const
  {
    geometry_msgs::Inertia msg(inertia);
    return messageToString<geometry_msgs::Inertia>(msg);
  }

  inline std::string
  getMessage(double m, geometry_msgs::Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz,
             double izz) const
  {
    geometry_msgs::Inertia msg(m, com, ixx, ixy, ixz, iyy, iyz, izz);
    return messageToString<geometry_msgs::Inertia>(msg);
  }
};

struct InertiaStampedTest : public Test
{
  InertiaStampedTest(const DataFrame &dataframe)
      : test1(dataframe.data.at("InertiaStampedTest")[0]),
        test2(dataframe.data.at("InertiaStampedTest")[1])
  {}

  ~InertiaStampedTest() final = default;

  const std::string test1;
  const std::string test2;

  inline std::string getMessage(const geometry_msgs::Inertia &inertia, std::string frame_id = "world") const
  {
    geometry_msgs::InertiaStamped msg(inertia, frame_id);
    return messageToString(msg);
  }

  inline std::string
  getMessage(double m, geometry_msgs::Vector3 &com, double ixx, double ixy, double ixz, double iyy, double iyz,
             double izz, std::string frame_id = "world") const
  {
    geometry_msgs::InertiaStamped msg(m, com, ixx, ixy, ixz, iyy, iyz, izz, frame_id);
    return messageToString(msg);
  }
};

} // namespace test

#endif //ROSBRIDGECLIENT_Test_TEST_HPP
