#include "median.hpp"

void Testbench::read_bmp() {
    // Input file name
    const char *fname_s = "lena.bmp";
    
    FILE *fp_s = NULL;
    
    fp_s = fopen(fname_s, "rb");
    if (fp_s == NULL) {
        cerr<<"fopen fp_s error"<<endl;
        return;
    }
    // move offset to 10 to find rgb raw data offset
    fseek(fp_s, 10, SEEK_SET);
    fread(&rgb_raw_data_offset, sizeof(unsigned int), 1, fp_s);
    // move offset to 18 to get width & height;
    fseek(fp_s, 18, SEEK_SET);
    fread(&width,  sizeof(unsigned int), 1, fp_s);
    fread(&height, sizeof(unsigned int), 1, fp_s);
    // get bit per pixel
    fseek(fp_s, 28, SEEK_SET);
    fread(&bit_per_pixel, sizeof(unsigned short), 1, fp_s);
    byte_per_pixel = bit_per_pixel / 8;
    // move offset to rgb_raw_data_offset to get RGB raw data
    fseek(fp_s, rgb_raw_data_offset, SEEK_SET);

    image_s = (unsigned char *)malloc((size_t)width * height * byte_per_pixel);
    if (image_s == NULL) {
        printf("malloc images_s error\n");
        return;
    }

    image_t = (unsigned char *)malloc((size_t)width * height * byte_per_pixel);
    if (image_t == NULL) {
        printf("malloc image_t error\n");
        return;
    }
    fread(image_s, sizeof(unsigned char), (size_t)(long)width * height * byte_per_pixel, fp_s);
    fclose(fp_s); // clode file, image data now in image_s

    for(y = 0; y < height; y++){
        for(x = 0; x < width; x++){
            int n = 0;
            //set the color values in the arrays
            for(int filterY = 0; filterY < MASK_Y; filterY++){
                for(int filterX = 0; filterX < MASK_X; filterX++){
                    int imageX = (x - MASK_X / 2 + filterX + width) % width;
                    int  imageY = (y - MASK_Y / 2 + filterY + height) % height;
                    filter_r[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 2);
                    filter_g[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 1);
                    filter_b[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 0);
                    n++;
                }
            }
            o_red.write(filter_r);
            o_green.write(filter_g);
            o_blue.write(filter_b);
            wait(i_blue.data_written_event());
        }
    }
}

void Testbench::write_bmp() {
    unsigned int file_size; // file size
    const char *fname_t = "lena_filtered.bmp";
    FILE *fp_t = NULL;

    while(1){
        /* wait(*i_median_finish);   // wait finding median
        // Write color info.
        *(image_t + byte_per_pixel * (width * y + x) + 2) = temp_r;
        *(image_t + byte_per_pixel * (width * y + x) + 1) = temp_g;
        *(image_t + byte_per_pixel * (width * y + x) + 0) = temp_b;
        if(x == (width-1) && y == (height-1)){
            break;
        } */
        /* else{
            //_write_finish.notify();
        } */
        if(i_red.num_available() > 0 && i_green.num_available() > 0 && i_blue.num_available() > 0){
            temp_r = i_red.read();
            temp_g = i_green.read();
            temp_b = i_blue.read();
            cout<<"--RECEIVE--";
            cout<<" x = "<<x<<" y = "<<y<<endl;
            cout<<"RED = "<<temp_r<<", ";
            cout<<"GREEN = "<<temp_g<<", ";
            cout<<"BLUE = "<<temp_b<<endl;
            *(image_t + byte_per_pixel * (width * y + x) + 2) = temp_r;
            *(image_t + byte_per_pixel * (width * y + x) + 1) = temp_g;
            *(image_t + byte_per_pixel * (width * y + x) + 0) = temp_b;
            temp_r = 0;
            temp_g = 0;
            temp_b = 0;
        }
        else if(x == (width) && y == (height)){
            cout << "Width = "<<width<<endl;
            cout<<"Height = "<<height<<endl;
            cout<<"ready to write file"<<endl;
            break;
        }
        else{
            if(i_red.num_available() < 1){
                wait(i_red.data_written_event());
            }
            else if(i_green.num_available() < 1){
                wait(i_green.data_written_event());
            }
            else{
                wait(i_blue.data_written_event());
            }
        }
        
    }
    cout << "Width = "<<width<<endl;
    cout<<"Height = "<<height<<endl;
    fp_t = fopen(fname_t, "wb");
    if (fp_t == NULL) {
        printf("fopen fname_t error\n");
        return;
    }

    // file size 
    file_size = width * height * byte_per_pixel + rgb_raw_data_offset;
    header[2] = (unsigned char)(file_size & 0x000000ff);
    header[3] = (file_size >> 8)  & 0x000000ff;
    header[4] = (file_size >> 16) & 0x000000ff;
    header[5] = (file_size >> 24) & 0x000000ff;

    // width
    header[18] = width & 0x000000ff;
    header[19] = (width >> 8)  & 0x000000ff;
    header[20] = (width >> 16) & 0x000000ff;
    header[21] = (width >> 24) & 0x000000ff;

    // height
    header[22] = height &0x000000ff;
    header[23] = (height >> 8)  & 0x000000ff;
    header[24] = (height >> 16) & 0x000000ff;
    header[25] = (height >> 24) & 0x000000ff;

    // bit per pixel
    header[28] = bit_per_pixel;
    // write header
    fwrite(header, sizeof(unsigned char), rgb_raw_data_offset, fp_t);
    // write image
    fwrite(image_t, sizeof(unsigned char), (size_t)(long)width * height * byte_per_pixel, fp_t);
    // close output file
    fclose(fp_t);
    cout<<"Output file closed"<<endl;
    sc_stop();
}