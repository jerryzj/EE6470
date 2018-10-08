#include "median.hpp"

void Median::do_median(){
    while(1){
        /* if(i_red.num_available() > 0 && i_green.num_available() > 0 && i_blue.num_available() > 0){
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
            wait(i_blue.data_written_event());
        } */
        if(i_red.num_available() > 0 && i_green.num_available() > 0 && i_blue.num_available() > 0){        
            while(i_update_index.num_available() > 0){
                int index = i_update_index.read();
                red_ptr = i_red.read();
                red[index] = red_ptr;
                green_ptr = i_green.read();
                green[index] = green_ptr;
                blue_ptr = i_blue.read();
                blue[index] = blue_ptr;
            }
            for(int i = 0; i < MASK_SIZE; i++){
                sort_r[i] = red[i];
                sort_g[i] = green[i];
                sort_b[i] = blue[i];
            }
            int k = MASK_SIZE / 2;
            sort(sort_r,sort_r+MASK_SIZE);
            sort(sort_g,sort_g+MASK_SIZE);
            sort(sort_b,sort_b+MASK_SIZE);
            o_red.write(sort_r[k]);
            o_green.write(sort_g[k]);
            o_blue.write(sort_b[k]);
        }
        else{
            wait(i_blue.data_written_event());
        }
    }
}