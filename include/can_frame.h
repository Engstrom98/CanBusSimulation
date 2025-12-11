#ifndef CAN_FRAME_H
#define CAN_FRAME_H

#include <stdint.h>

#define CAN_STD_ID_MAX 0x7FF
#define CAN_STD_DLC_MAX 8
#define CAN_MAX_DATA_LEN 8

/**
 * @brief Can frame struct including id, data and lenght of data
 * @param can_id 11-bit CAN identifier (0x000 - 0x7FF)
 * @param dlc Data length code (0-8)
 * @param data Pointer to data bytes (can be null if dlc is 0)
 */
typedef struct{
    uint16_t can_id;
    uint8_t dlc;
    uint8_t data[CAN_MAX_DATA_LEN];
}can_frame_t;



/**
 * @brief populate a can frame with validation and error checking
 * 
 * @param frameptr Pointer to the frame you want to populate
 * @param can_id 11-bit CAN identifier (0x000 - 0x7FF)
 * @param dlc Data length code (0-8)
 * @param data Pointer to data bytes (can be null if dlc is 0)
 * @return 0 on success, -1 on error
 */
int populate_can_frame(can_frame_t *frameptr, uint16_t can_id, uint8_t dlc, const uint8_t *data);


/**
 * @brief Print a CAN frame in readable format
 * 
 * @param frame Pointer to frame to print
 */
void print_can_frame(const can_frame_t *frame);


#endif




