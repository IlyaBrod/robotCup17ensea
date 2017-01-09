
#ifndef ROBOCLAW_H
#define ROBOCLAW_H
#include "mbed.h"
#include "registers.h"

/** The RoboClaw class, yo ucan use the library with : http://www.ionmc.com/RoboClaw-2x15A-Motor-Controller_p_10.html
*   Used to control one or two motors with (or not) encoders
*  @code
* #include "mbed.h"
* #include "RoboClaw.h"
*
* RoboClaw roboclaw(115200, PA_11, PA_12);
*
* int main() {
*     roboclaw.ForwardM1(ADR, 127);
*     while(1);
* }
* @endcode
*/

class RoboClaw
{
public:
    /** Create RoboClaw instance
    */
    RoboClaw(uint8_t adr, int baudrate, PinName rx, PinName tx);

    /** Forward and Backward functions
    * @param address address of the device
    * @param speed speed of the motor (between 0 and 127)
    * @note Forward and Backward functions
    */
    void ForwardM1(int speed);
    void BackwardM1(int speed);
    void ForwardM2(int speed);
    void BackwardM2(int speed);

    /** Forward and Backward functions
    * @param address address of the device
    * @param speed speed of the motor (between 0 and 127)
    * @note Forward and Backward functions, it turns the two motors
    */
    void Forward(int speed);
    void Backward(int speed);

    /** Read the Firmware
    * @param address address of the device
    */
    void ReadFirm();

    /** Read encoder and speed of M1 or M2
    * @param address address of the device
    * @note Read encoder in ticks
    * @note Read speed in ticks per second
    */
    int32_t ReadEncM1();
    int32_t ReadEncM2();
    int32_t ReadSpeedM1();
    int32_t ReadSpeedM2();

    /** Set both encoders to zero
    * @param address address of the device
    */
    void ResetEnc();

    /** Set speed of Motor with different parameter (only in ticks)
    * @param address address of the device
    * @note Set the Speed
    * @note Set the Speed and Accel
    * @note Set the Speed and Distance
    * @note Set the Speed, Accel and Distance
    * @note Set the Speed, Accel, Decceleration and Position
    */
    void SpeedM1(int32_t speed);
    void SpeedM2(int32_t speed);
    void SpeedAccelM1(int32_t accel, int32_t speed);
    void SpeedAccelM2(int32_t accel, int32_t speed);
    void SpeedAccelM1M2(int32_t accel, int32_t speed1, int32_t speed2);
    void SpeedDistanceM1(int32_t speed, uint32_t distance, uint8_t buffer);
    void SpeedDistanceM2(int32_t speed, uint32_t distance, uint8_t buffer);
    void SpeedAccelDistanceM1(int32_t accel, int32_t speed, uint32_t distance, uint8_t buffer);
    void SpeedAccelDistanceM2(int32_t accel, int32_t speed, uint32_t distance, uint8_t buffer);
    void SpeedAccelDeccelPositionM1(uint32_t accel, int32_t speed, uint32_t deccel, int32_t position, uint8_t flag);
    void SpeedAccelDeccelPositionM2(uint32_t accel, int32_t speed, uint32_t deccel, int32_t position, uint8_t flag);
    void SpeedAccelDeccelPositionM1M2(uint32_t accel1,uint32_t speed1,uint32_t deccel1, int32_t position1,uint32_t accel2,uint32_t speed2,uint32_t deccel2, int32_t position2,uint8_t flag);

private:
    Serial _roboclaw;
    uint16_t crc;
    uint8_t address;
    void crc_clear();
    void crc_update(uint8_t data);
    uint16_t crc_get();

    void write_n(uint8_t cnt, ...);
    void write_(uint8_t command, uint8_t data, bool reading, bool crcon);

    uint16_t crc16(uint8_t *packet, int nBytes);
    uint8_t read_(void);
};

#endif

