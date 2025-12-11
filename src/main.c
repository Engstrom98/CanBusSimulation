#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "can_frame.h"

int main(){
    can_frame_t frame;
    can_frame_t *fptr = &frame;
    uint8_t data[8] = {1,2,3,4};
    uint16_t can_id = 0xF1;
    uint8_t dlc = 4;
    int a = populate_can_frame(fptr, can_id,dlc ,data);
    
    print_can_frame(fptr);

    
}