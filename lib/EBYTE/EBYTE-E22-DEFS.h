#ifndef _EBYTE_E22_H_
#define _EBYTE_E22_H_

#include <Arduino.h>
#include <HardwareSerial.h>

#define MODE_0_TRANSFER     0
#define MODE_1_WOR          1
#define MODE_2_CONFIG       2
#define MODE_3_DORMANCY     3


#define ADDR_H              0x00
#define ADDR_L              0x01
#define NET_ID              0x02
#define REG0                0x03
#define REG1                0x04
#define REG2                0x05
#define REG3                0x06
#define CRYPT_H             0x07
#define CRYPT_L             0x08
#define PID                 0x09

#define REG0_BAUD_1200      0x00
#define REG0_BAUD_2400      0x20
#define REG0_BAUD_4800      0x40
#define REG0_BAUD_9600      0x60
#define REG0_BAUD_19200     0x80
#define REG0_BAUD_38400     0xA0
#define REG0_BAUD_57600     0xC0
#define REG0_BAUD_115200    0xE0

#define REG0_PARITY_8N1     0x00
#define REG0_PARITY_8O1     0x08
#define REG0_PARITY_8E1     0x10

#define REG0_WAR_0K3        0x00
#define REG0_WAR_1K2        0x01
#define REG0_WAR_2K4        0x02
#define REG0_WAR_4K8        0x03
#define REG0_WAR_9K6        0x04
#define REG0_WAR_19K2       0x05
#define REG0_WAR_38K4       0x06
#define REG0_WAR_62K5       0x07


class EBYTE_E22{

    public:
        EBYTE_E22(HardwareSerial ser, uint8_t m0_pin, uint8_t m1_pin, uint8_t en_pin) : ser(ser), m0_pin(m0_pin), m1_pin(m1_pin), en_pin(en_pin){
            pinMode(m0_pin, OUTPUT);
            pinMode(m1_pin, OUTPUT);
            pinMode(en_pin, OUTPUT);
        };

        void setMode(uint8_t mode){
            switch(mode){
                case MODE_0_TRANSFER:
                    digitalWrite(m0_pin, LOW);
                    digitalWrite(m1_pin, LOW);
                    break;
                case MODE_1_WOR:
                    digitalWrite(m0_pin, HIGH);
                    digitalWrite(m1_pin, LOW);
                    break;
                case MODE_2_CONFIG:
                    digitalWrite(m0_pin, LOW);
                    digitalWrite(m1_pin, HIGH);
                    break;
                case MODE_3_DORMANCY:
                    digitalWrite(m0_pin, LOW);
                    digitalWrite(m1_pin, HIGH);
                    break;
                default:
                break;
            };
            delay(5);
        }

    private:
        HardwareSerial ser;
        uint8_t m0_pin, m1_pin, en_pin;

};



#endif