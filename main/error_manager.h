#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include <stdint.h>
                                                                        //ERROR FLAG BIT POSITION (because defined as enum)
typedef enum {
    ERROR_NONE = 0,             //no error                              1
    ERROR_CAMERA_REC,           //camera                                2
    ERROR_SENSOR_FAIL,          //sensor issues                         3
    ERROR_SENSOR_INVALID,       //                                      4
    ERROR_GENTEMP_SENSOR_FAIL,  //temperature read and control          5
    ERROR_GENTEMP_CRITICAL,     //                                      6    
    ERROR_PVTEMP_SENSOR_FAIL,   //                                      7
    ERROR_PVTEMP_CONTROL_FAIL,  //                                      8
    ERROR_PVTEMP_CRITICAL,      //                                      9
    ERROR_INTERFACE_RS422,      //interface issues                      10
    ERROR_INTERFACE_SPI,        //                                      11
    ERROR_INTERFACE_UART,       //                                      12
    ERROR_TELEM_FORMAT,         //telemetry issues                      13
    ERROR_TELEM_BUFFER,         //                                      14
    ERROR_MEMORY,               //memory                                15
    ERROR_DATA_CORRUPTION,      //                                      16
    ERROR_CPU                   //flight computer issues                17
} error_flag_t;

uint32_t get_error_flags(void);

#endif