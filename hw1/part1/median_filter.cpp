// EE6470 HW1 Median Filter
// Chong-Yao, Zhang Jian
// 30, Sept. 2018
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

// Filter parameters and Color definitions
const int MASK_X  = 3;
const int MASK_Y = 3;

unsigned char *image_s = NULL;     // source image array
unsigned char *image_t = NULL;     // target image array
FILE *fp_s = NULL;                 // source file handler
FILE *fp_t = NULL;                 // target file handler

unsigned int   width, height;      // image width, image height
unsigned int   rgb_raw_data_offset;// RGB raw data offset
unsigned char  bit_per_pixel;      // bit per pixel
unsigned short byte_per_pixel;     // byte per pixel

//color arrays
int red[MASK_X * MASK_Y];
int green[MASK_X * MASK_Y];
int blue[MASK_X * MASK_Y];

// bitmap header
unsigned char header[54] = {
  0x42,        // identity : B
  0x4d,        // identity : M
  0, 0, 0, 0,  // file size
  0, 0,        // reserved1
  0, 0,        // reserved2
  54, 0, 0, 0, // RGB data offset
  40, 0, 0, 0, // struct BITMAPINFOHEADER size
  0, 0, 0, 0,  // bmp width
  0, 0, 0, 0,  // bmp height
  1, 0,        // planes
  24, 0,       // bit per pixel
  0, 0, 0, 0,  // compression
  0, 0, 0, 0,  // data size
  0, 0, 0, 0,  // h resolution
  0, 0, 0, 0,  // v resolution
  0, 0, 0, 0,  // used colors
  0, 0, 0, 0   // important colors
};

// Function declarations
int read_bmp(const char *fname_s);
int write_bmp(const char *fname_t);
void median_filter();
int median(int* data, int end, int k);

int main(void) {
  read_bmp("lena.bmp");
  median_filter();
  write_bmp("lena_filtered.bmp");

  return 0;
}

int read_bmp(const char *fname_s) {
  fp_s = fopen(fname_s, "rb");
  if (fp_s == NULL) {
    cerr<<"fopen fp_s error"<<endl;
    return -1;
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
    return -1;
  }
   
  image_t = (unsigned char *)malloc((size_t)width * height * byte_per_pixel);
  if (image_t == NULL) {
    printf("malloc image_t error\n");
    return -1;
  }
   
  fread(image_s, sizeof(unsigned char), (size_t)(long)width * height * byte_per_pixel, fp_s);
 
  return 0;
}

int write_bmp(const char *fname_t) {
  unsigned int file_size; // file size
 
  fp_t = fopen(fname_t, "wb");
  if (fp_t == NULL) {
    printf("fopen fname_t error\n");
    return -1;
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
    
  fclose(fp_s);
  fclose(fp_t);
    
  return 0;
}

void median_filter(){
  for(unsigned int y = 0; y < height; y++){
    for(unsigned int x = 0; x < width; x++){
      int n = 0;
      //set the color values in the arrays
      for(int filterY = 0; filterY < MASK_Y; filterY++){
        for(int filterX = 0; filterX < MASK_X; filterX++){
          int imageX = (x - MASK_X / 2 + filterX + width) % width;
          int  imageY = (y - MASK_Y / 2 + filterY + height) % height;
          red[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 2);
          green[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 1);
          blue[n] = *(image_s + byte_per_pixel * (width * imageY + imageX) + 0);
          n++;
        }
      }
      int filterSize = MASK_X * MASK_Y;
      // Write result through pointer
      *(image_t + byte_per_pixel * (width * y + x) + 2) = median(red, filterSize, filterSize / 2);
      *(image_t + byte_per_pixel * (width * y + x) + 1) = median(green, filterSize, filterSize / 2);
      *(image_t + byte_per_pixel * (width * y + x) + 0) = median(blue, filterSize, filterSize / 2);
    }
  }
}

int median(int* data, int end, int k){
  sort(data, data + end);
  return data[k];
}