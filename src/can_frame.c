#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "can_frame.h"


int populate_can_frame(can_frame_t *frameptr, uint16_t can_id, uint8_t dlc, const uint8_t *data){ //using a const pointer to the data to show that we wont be modifying the data
    //validate that the frameptr is not NULL
    if(frameptr == NULL){
        fprintf(stderr, "Error: NULL frame pointer\n");
        return -1;
    }
    
    // Validate CAN ID
    if(can_id > CAN_STD_ID_MAX){
        fprintf(stderr, "Error: CAN ID 0x%X exceeds 11-bit limit (max 0x%X)\n", 
                can_id, CAN_STD_ID_MAX);
        return -1;
    }
    
    // Validate DLC
    if(dlc > CAN_STD_DLC_MAX){
        fprintf(stderr, "Error: DLC %d exceeds maximum (%d)\n", 
                dlc, CAN_STD_DLC_MAX);
        return -1;
    }


    memset(frameptr, 0, sizeof(*frameptr)); //zero out the entire struct to prevent garbage values to be left in the struct

    frameptr->can_id = can_id;
    frameptr->dlc = dlc;
    memcpy(frameptr->data, data, dlc);

    return 0;
}

void print_can_frame(const can_frame_t *frame) {
    printf("CAN Frame:\n");
    printf("  ID:  0x%03X\n", frame->can_id);
    printf("  DLC: %d\n", frame->dlc);
    printf("  Data: ");
    
    for (int i = 0; i < frame->dlc; i++) {
        printf("%02X ", frame->data[i]);
    }
    
    // Show remaining bytes as dots
    for (int i = frame->dlc; i < CAN_MAX_DATA_LEN; i++) {
        printf(".. ");
    }
    
    printf("\n");
}