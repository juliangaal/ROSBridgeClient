//
// Created by Julian on 14.10.18.
//

#include <rbc/subscriber/rbc_string_subscriber.h>
#include <rbc/subscriber/response_to_message.h>

using namespace rbc::subscriber;

RBCStringSubscriber::RBCStringSubscriber(ROSBridgeClient &wsc, std::string topic, size_t buffer_size)
  : RBCSubscriber<std_msgs::StringMessage>(wsc, topic, "std_msgs/String", buffer_size)
{}

void RBCStringSubscriber::addMessage(const web::json::value &json_msg)
{
  const auto& msg = conversions::responseToStringMessage(json_msg);

  if (messages.size() >= buffer_size)
  {
    messages.pop();
    messages.push(msg);
    return;
  }

  messages.push(msg);
  std::cout << getTopic() << " subscriber received: " << msg.toString() << "\n";
}