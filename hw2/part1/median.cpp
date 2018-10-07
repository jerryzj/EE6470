#include "median.hpp"

void Median::do_median(){
    while(1){
        if(i_red.num_available() > 0 && i_green.num_available() > 0 && i_blue.num_available() > 0){
            red_ptr = i_red.read();
            green_ptr = i_green.read();
            blue_ptr = i_blue.read();
            for(int i = 0; i < MASK_SIZE; i++){
                red[i] = red_ptr[i];
                blue[i] = blue_ptr[i];
                green[i] = green_ptr[i];
            }
            int k = MASK_SIZE / 2;
            sort(red,red+MASK_SIZE);
            sort(green,green+MASK_SIZE);
            sort(blue,blue+MASK_SIZE);
            o_red.write(red[k]);
            o_green.write(green[k]);
            o_blue.write(blue[k]);
        }
        else{
            wait();
        }
    }
}