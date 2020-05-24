// Generated by gencpp from file ISLH_msgs/taskInfoFromRobotMessage.msg
// DO NOT EDIT!


#ifndef ISLH_MSGS_MESSAGE_TASKINFOFROMROBOTMESSAGE_H
#define ISLH_MSGS_MESSAGE_TASKINFOFROMROBOTMESSAGE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ISLH_msgs
{
template <class ContainerAllocator>
struct taskInfoFromRobotMessage_
{
  typedef taskInfoFromRobotMessage_<ContainerAllocator> Type;

  taskInfoFromRobotMessage_()
    : senderRobotID(0)
    , infoMessageType(0)
    , taskUUID()
    , encounteringTime(0)
    , reachingTime(0)
    , handlingDuration(0)
    , timeOutDuration(0)
    , requiredResources()
    , posX(0.0)
    , posY(0.0)  {
    }
  taskInfoFromRobotMessage_(const ContainerAllocator& _alloc)
    : senderRobotID(0)
    , infoMessageType(0)
    , taskUUID(_alloc)
    , encounteringTime(0)
    , reachingTime(0)
    , handlingDuration(0)
    , timeOutDuration(0)
    , requiredResources(_alloc)
    , posX(0.0)
    , posY(0.0)  {
  (void)_alloc;
    }



   typedef uint16_t _senderRobotID_type;
  _senderRobotID_type senderRobotID;

   typedef uint16_t _infoMessageType_type;
  _infoMessageType_type infoMessageType;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _taskUUID_type;
  _taskUUID_type taskUUID;

   typedef uint64_t _encounteringTime_type;
  _encounteringTime_type encounteringTime;

   typedef uint64_t _reachingTime_type;
  _reachingTime_type reachingTime;

   typedef uint16_t _handlingDuration_type;
  _handlingDuration_type handlingDuration;

   typedef uint16_t _timeOutDuration_type;
  _timeOutDuration_type timeOutDuration;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _requiredResources_type;
  _requiredResources_type requiredResources;

   typedef float _posX_type;
  _posX_type posX;

   typedef float _posY_type;
  _posY_type posY;





  typedef boost::shared_ptr< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> const> ConstPtr;

}; // struct taskInfoFromRobotMessage_

typedef ::ISLH_msgs::taskInfoFromRobotMessage_<std::allocator<void> > taskInfoFromRobotMessage;

typedef boost::shared_ptr< ::ISLH_msgs::taskInfoFromRobotMessage > taskInfoFromRobotMessagePtr;
typedef boost::shared_ptr< ::ISLH_msgs::taskInfoFromRobotMessage const> taskInfoFromRobotMessageConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ISLH_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ISLH_msgs': ['/home/berkay/catkin_ws/src/ISLH_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e54b818b14e2cc4a576aa5a518a1a847";
  }

  static const char* value(const ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe54b818b14e2cc4aULL;
  static const uint64_t static_value2 = 0x576aa5a518a1a847ULL;
};

template<class ContainerAllocator>
struct DataType< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ISLH_msgs/taskInfoFromRobotMessage";
  }

  static const char* value(const ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# The task's information  from member robot to coalition leader\n\
\n\
uint16 senderRobotID #robot id which encounters the task\n\
\n\
uint16 infoMessageType\n\
\n\
string taskUUID # the task's UUID\n\
\n\
uint64 encounteringTime #The encountering time in timestamp form\n\
\n\
uint64 reachingTime # The time when the robot reached to the task site\n\
\n\
uint16 handlingDuration\n\
\n\
uint16 timeOutDuration\n\
\n\
string requiredResources # Required resources for this task\n\
\n\
float32 posX # The position of the task at x direction \n\
float32 posY # The position of the task at y direction \n\
\n\
\n\
";
  }

  static const char* value(const ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.senderRobotID);
      stream.next(m.infoMessageType);
      stream.next(m.taskUUID);
      stream.next(m.encounteringTime);
      stream.next(m.reachingTime);
      stream.next(m.handlingDuration);
      stream.next(m.timeOutDuration);
      stream.next(m.requiredResources);
      stream.next(m.posX);
      stream.next(m.posY);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct taskInfoFromRobotMessage_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ISLH_msgs::taskInfoFromRobotMessage_<ContainerAllocator>& v)
  {
    s << indent << "senderRobotID: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.senderRobotID);
    s << indent << "infoMessageType: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.infoMessageType);
    s << indent << "taskUUID: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.taskUUID);
    s << indent << "encounteringTime: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.encounteringTime);
    s << indent << "reachingTime: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.reachingTime);
    s << indent << "handlingDuration: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.handlingDuration);
    s << indent << "timeOutDuration: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.timeOutDuration);
    s << indent << "requiredResources: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.requiredResources);
    s << indent << "posX: ";
    Printer<float>::stream(s, indent + "  ", v.posX);
    s << indent << "posY: ";
    Printer<float>::stream(s, indent + "  ", v.posY);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ISLH_MSGS_MESSAGE_TASKINFOFROMROBOTMESSAGE_H
