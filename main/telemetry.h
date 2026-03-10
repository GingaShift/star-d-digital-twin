#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <stdint.h>

typedef struct {
    uint16_t packet_id;
    uint16_t sequence_order;
    uint16_t packet_content_length;
} CCSDS_Formatting;

//TODO: check if char message[size] for messages has size problems based on new telem specifications

typedef struct {
    CCSDS_Formatting header;
    uint16_t packet_size;
    float voltage;
    float board_temp;
    float SSD_status;
    float camera_status;
    float pv_temp;
    float general_temp;
    uint32_t error_flag;
    uint32_t timestamp;
    char message[64];       //check size rqs for messages
    uint16_t crc;
} TelemetryPacket;


void telemetry_task(void);
void telemetry_init(void);

#endif