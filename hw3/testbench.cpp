#include "median.hpp"


Testbench::Testbench(sc_module_name n) : sc_module(n), initiator("initiator") {
    x = 0;
    y = 0;
    temp_r = 0;
    temp_g = 0;
    temp_b = 0;
    width = 0;
    height = 0;
    rgb_raw_data_offset = 0;
    bit_per_pixel = 0;
    byte_per_pixel = 0;
    pixel_counter = 0;
    image_s = NULL;
    image_t = NULL;
    SC_THREAD(IO);
}

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
    cout<<"Read input file successfully"<<endl;
}

void Testbench::write_bmp() {
    unsigned int file_size; // file size
    const char *fname_t = "lena_filtered.bmp";
    FILE *fp_t = NULL;

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
    cout<<"Total pixels transmitted: "<<pixel_counter<<endl;
    cout<<"Output file generated successfully"<<endl;
}

void Testbench::IO(){
    word data, mask;
    for(unsigned int y = 0; y < height; y++){
        for(unsigned int x = 0; x < width; x++){
            if(x == 0){  // transmit the whole filter 
                for(int filterY = 0; filterY < MASK_Y; filterY++){
                    for(int filterX = 0; filterX < MASK_X; filterX++){
                        int imageX = (x - MASK_X / 2 + filterX + width) % width;
                        int  imageY = (y - MASK_Y / 2 + filterY + height) % height;
                        temp_r = *(image_s + byte_per_pixel * (width * imageY + imageX) + 2);
                        temp_g = *(image_s + byte_per_pixel * (width * imageY + imageX) + 1);
                        temp_b = *(image_s + byte_per_pixel * (width * imageY + imageX) + 0);
                        // set data
                        data.uc[0] = (char) temp_r;
                        data.uc[1] = (char) temp_g;
                        data.uc[2] = (char) temp_b;
                        // set mask
                        mask.uc[0] = 0xff;
                        mask.uc[1] = 0xff;
                        mask.uc[2] = 0xff;
                        mask.uc[3] = 0; 
                        pixel_counter ++;                       
                        initiator.write_to_socket(MEDIAN_FILTER_R_ADDR, mask.uc, data.uc, 4);
                    }
                }
            }
            else{   // tranmit by row
                for(int filterY = 0; filterY < MASK_Y; filterY++){
                    int filterX = MASK_X - 1;
                    int imageX = (x - MASK_X / 2 + filterX + width) % width;
                    int  imageY = (y - MASK_Y / 2 + filterY + height) % height;
                    temp_r = *(image_s + byte_per_pixel * (width * imageY + imageX) + 2);
                    temp_g = *(image_s + byte_per_pixel * (width * imageY + imageX) + 1);
                    temp_b = *(image_s + byte_per_pixel * (width * imageY + imageX) + 0);
                    // set data
                    data.uc[0] = temp_r;
                    data.uc[1] = temp_g;
                    data.uc[2] = temp_b;
                    // set mask
                    mask.uc[0] = 0xff;
                    mask.uc[1] = 0xff;
                    mask.uc[2] = 0xff;
                    mask.uc[3] = 0;
                    pixel_counter ++;                        
                    initiator.write_to_socket(MEDIAN_FILTER_R_ADDR, mask.uc, data.uc, 4);
                }
            }
            // Write result
            initiator.read_from_socket(MEDIAN_FILTER_RESULT_ADDR, mask.uc, data.uc, 4);
            *(image_t + byte_per_pixel * (width * y + x) + 2) = data.uc[0];
            *(image_t + byte_per_pixel * (width * y + x) + 1) = data.uc[1];
            *(image_t + byte_per_pixel * (width * y + x) + 0) = data.uc[2];
        }
    }
    sc_stop();
}

unsigned int Testbench::get_width(){
    return width;
}

unsigned int Testbench::get_height(){
    return height;
}