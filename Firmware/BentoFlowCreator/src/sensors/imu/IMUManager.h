#include "../../common/Common.h"

#include <Wire.h>
// #include "Adafruit_BNO055/Adafruit_BNO055.h"
#include <Adafruit_BNO055.h>

#ifdef HAS_M5_IMU
    #include "MPU6886/MPU6886.h"
#endif

class IMUEvent
{
public:
    enum Type { OrientationUpdate, Shock, FreeFall, TYPES_MAX };
    static const String eventNames[TYPES_MAX];

    IMUEvent(Type t) : type(t) {}
    Type type;
};


class IMUManager : public Component, public EventBroadcaster<IMUEvent> {
public:
    IMUManager();
    ~IMUManager();

#ifdef HAS_IMU
    Adafruit_BNO055 bno;
#endif

#ifdef HAS_M5_IMU
    MPU6886 imu6886;
#endif

    bool isConnected;
    bool isEnabled;
    
    long orientationSendTime;
    long timeSinceOrientationLastSent;

    float orientation[4];
    
    void init();
    void update();

    void setEnabled(bool value);


    bool handleCommand(String command, var * data, int numData) override;

    float pitch = 0.0F;
    float roll  = 0.0F;
    float yaw   = 0.0F;
};
