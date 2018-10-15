#include "median.hpp"

void Median::do_median(){
    while(1){
        if(i_red.num_available() > 0 && i_green.num_available() > 0 && i_blue.num_available() > 0){        
            // Restore from backup filter
            for(int j = 0; j < MASK_SIZE; j++){
                if(j % MASK_X == MASK_X - 1){
                    red[j] = 0;
                    green[j] = 0;
                    blue[j] = 0;
                }
                else{
                    red[j] = old_r[j+1];
                    green[j] = old_g[j+1];
                    blue[j] = old_b[j+1];
                }
            }
            // Fill pixel from FIFO
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
                // Write pixel to sort array
                sort_r[i] = red[i];
                sort_g[i] = green[i];
                sort_b[i] = blue[i];
                // Backup pixel
                old_r[i] = red[i];
                old_g[i] = green[i];
                old_b[i] = blue[i];
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
            wait(i_update_index.data_written_event());
        }
    }
}