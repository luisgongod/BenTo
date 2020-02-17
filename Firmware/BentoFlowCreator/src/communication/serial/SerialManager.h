#pragma once
#include "../../common/Common.h"

class SerialEvent
{
public:
    enum Type { MessageReceived };
    SerialEvent(Type type) : type(type) {}
    SerialEvent(Type type, String target, String command, String data) :
        type(type),target(target), command(command), data(data)
    {}

    Type type;
    String target;
    String command;
    String data;
};

class SerialManager :
    public Component,
    public EventBroadcaster<SerialEvent>
{
public:
    SerialManager();
    ~SerialManager(){}

    char buffer[64];
    byte bufferIndex;

    void init();
    void update();

    void processMessage(String buffer);
};