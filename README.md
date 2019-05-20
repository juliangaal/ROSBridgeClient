# rbcpp [![Build Status](https://travis-ci.com/juliangaal/ROSBridgeClient.svg?branch=master)](https://travis-ci.com/juliangaal/ROSBridgeClient)

**r**os**b**ridge**c**lient + **cpp** = **rbcpp**

A [rosbridge v2.0](http://wiki.ros.org/rosbridge_suite) client.
> rosbridge provides a JSON interface to [ROS](http://www.ros.org/), allowing any client to send JSON to publish or subscribe to ROS topics, call ROS services, and more. 

It allows you to work with ROS on not officially supported hardware or operating systems.

**DEPRECATED, USE AT YOUR OWN RISK**. This will eventually be rewritten with https://github.com/target/libdart

*Important Note*: as of now, tornado >= 4.5.3 breaks the websocket connection with rosbridge. See [issue](https://github.com/RobotWebTools/rosbridge_suite/issues/371). 
If your connection is dropped at the fist send attempt, check your tornado version with `pip show tornado`.

### TOC

1. [install, Build](#build)
2. [Status](#status)
3. [Usage](#usage) 

<a name="build"></a>

## Build, Install

**Minimum Requirements**: clang-6.0, g++-6 or xcode9.1

To use librbc, you need to install [cpprestsdk](https://github.com/Microsoft/cpprestsdk). If you want to run the tests, as well, you need to additionally install [Catch2](https://github.com/catchorg/Catch2)

Set compiler, e.g g++-8, for entire session
```
export CXX=/usr/bin/g++-8
```
or do so in the `cmake` command: `cmake -DCMAKE_CXX_COMPILER=/usr/bin/g++-7 ..`, see below

Build only the client api
```bash
mkdir build && cd build
cmake -DCMAKE_CXX_COMPILER=/path/to/compiler ..
make
```

Install with 
```
sudo make install
```

Build all tests, as well
```bash
mkdir build && cd build
cmake -DCMAKE_CXX_COMPILER=/path/to/compiler -DCOMPILE_TEST=ON ..
make 
```

**Note**: On Mac, you may need to adjust `OPENSSL_ROOT_DIR` and `OPENSSL_INCLUDE_DIR`, if your openssl installation is not located in `/usr/local/opt/openssl`

<a name="status"></a>

## Status: very early development
### ROS Services
- [x] Support for basic ROS services

Implement your own serializer (class to json) and deserializer (json to class) for more complex use cases

### Publisher, Subscriber
All messages that are checked below can be used already. Examples can be found [here](test/full_test.cpp)

| Type           | Messages | Subscriber Status | Publisher Status |
|----------------|----------------|----------------|----------------|
|**geometry_msgs**| orientation  | <ul><li>-[x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | orientation stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | vector3  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | vector3 stamped | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose 2d   | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose array  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose stamped | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose with covariance  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | pose with covariance stamped | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | point  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | point32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | point stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel with covariance | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | accel with covariance stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | inertia  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | inertia stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | wrench  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | wrench stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | polygon | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | polygon stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | transform  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | transform stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist with covariance  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | twist with covariance stamped  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|**nav_msgs**     | GridCells  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Odometry  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Path      | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | OccupancyGrid | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | MapMetaData  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|**sensor_msgs**  | BatteryState | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | CameraInfo | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | ChannelFloat32 | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | CompressedImage | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | FluidPressure | <ul><li>- [x] </li></ul> | <ul><li>- [x] </li></ul> |
|                 | Illuminance | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | Image | <ul><li>- [ ] (rosbrigde error?)</li></ul> | <ul><li>- [x] </li></ul> |
|                 | Imu | <ul><li>- [x] </li></ul> | <ul><li>- [x] </li></ul> |
|                 | JointState | <ul><li>- [x] </li></ul> | <ul><li>- [x] </li></ul> |
|                 | Joy | <ul><li>- [x] </li></ul> | <ul><li>- [x] </li></ul> |
|                 | JoyFeedback | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | JoyFeedbackArray | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | LaserEcho | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | LaserScan | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | MagneticField | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | MultiDOFJointState | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | MultiEchoLaserScan | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | NavSatFix | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | NavSatStatus | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | PointCloud | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | PointCloud2 | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | PointField | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | Range | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | RegionOfInterest | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | RelativeHumidity | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | Temperature | <ul><li>- [x] </li></ul> | <ul><li>- [x] </li></ul> |
|                 | TimeReference | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|                 | SetCameraInfo | <ul><li>- [ ] </li></ul> | <ul><li>- [ ] </li></ul> |
|**std_msgs**     | String  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Header  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int8  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int8MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Int16  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int16MultiArray  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Int64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Int64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt8 | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt16  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt16MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | UInt64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | MultiArrayDimension  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | MultiArrayLayout  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Time  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Byte   | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | ByteMultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Char  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | ColorRGBA  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Duration  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Empty  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Bool  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Float32  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Float32MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | Float64  | <ul><li>- [x]  </li></ul> | <ul><li>- [x]  </li></ul> |
|                 | Float64MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |
|                 | UInt8MultiArray  | <ul><li>- [ ]  </li></ul> | <ul><li>- [ ]  </li></ul> |

<a name="usage"></a>

## Usage



### TODO

- [ ] cmake install
- [ ] make web value json call safer
- [ ] test all wrench stamped constructors
- [ ] overload operators for Int/Float std_msgs
- [ ] check incoming received_message for validity
- [ ] Instructions for custom service
