#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <stdint.h>
#include "mode_manager.h"

typedef struct {                            //BYTE SIZE
    uint16_t packet_id;                     //
    uint16_t sequence_order;                //
    uint16_t packet_length;                 //
} CCSDS_Header;                             //6 bytes

typedef struct {
    CCSDS_Header header;
    uint32_t timestamp;         //Internal clock timestamp
    software_mode_t mode;       //Current software mode

    //SENSOR VALUES
        //Temperature
    float PCB_temp;             //Electronic board temperature
    float PT100_MFC_temp;       //Fluid temperature
    float general_ext_temp;     //EM overall temperature

        //Fluidic
    float SLF35_flow;           //SLF35 fluid flow
    float ABP_pressure;         //ABP sensor fluid pressure

    //SYSTEM HEALTH
    float voltage;              //Main PCB voltage
    uint8_t SSD_status;         //Data storage status
    uint8_t camera_status;      //Camera recording status
    uint32_t error_flag;        //Error flags

    //SYSTEM HEALTH
    char message[64];           //check size rqs for messages
    uint16_t crc;               //checksum
} TelemetryPacket;

void telemetry_init(void);
void telemetry_task(void);

#endif