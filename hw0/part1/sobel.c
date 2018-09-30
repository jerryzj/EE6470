
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MASK_N 2
#define MASK_X 3
#define MASK_Y 3
#define WHITE  255
#define BLACK  0

unsigned char *image_s = NULL;     // source image array
unsigned char *image_t = NULL;     // target image array
FILE *fp_s = NULL;                 // source file handler
FILE *fp_t = NULL;                 // target file handler

unsigned int   width, height;      // image width, image height
unsigned int   rgb_raw_data_offset;// RGB raw data offset
unsigned char  bit_per_pixel;      // bit per pixel
unsigned short byte_per_pixel;     // byte per pixel

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


// sobel mask
int mask[MASK_N][MASK_X][MASK_Y] = {
  {{-1,-2,-1},
   {0 , 0, 0},
   {1 , 2, 1}},

  {{-1, 0, 1},
   {-2, 0, 2},
   {-1, 0, 1}}
};

int read_bmp(const char *fname_s) {
  fp_s = fopen(fname_s, "rb");
  if (fp_s == NULL) {
    printf("fopen fp_s error\n");
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
 
// convert RGB to gray level int
int color_to_int(int r, int g, int b) {
  return (r + g + b) / 3;
}

int sobel(double threshold) {
  unsigned int  x, y, i, v, u;             // for loop counter
  unsigned char R, G, B;         // color of R, G, B
  double val[MASK_N] = {0.0};
  int adjustX, adjustY, xBound, yBound;
  double total;

  for(y = 0; y != height; ++y) {
    for(x = 0; x != width; ++x) {
      for(i = 0; i != MASK_N; ++i) {
        adjustX = (MASK_X % 2) ? 1 : 0;
                adjustY = (MASK_Y % 2) ? 1 : 0;
                xBound = MASK_X / 2;
                yBound = MASK_Y / 2;
           
        val[i] = 0.0;
        for(v = -yBound; v != yBound + adjustY; ++v) {
          for (u = -xBound; u != xBound + adjustX; ++u) {
            if (x + u >= 0 && x + u < width && y + v >= 0 && y + v < height) {
              R = *(image_s + byte_per_pixel * (width * (y+v) + (x+u)) + 2);
              G = *(image_s + byte_per_pixel * (width * (y+v) + (x+u)) + 1);
              B = *(image_s + byte_per_pixel * (width * (y+v) + (x+u)) + 0);
             
                  val[i] +=    color_to_int(R, G, B) * mask[i][u + xBound][v + yBound];
            }
          }
        }
      }

      total = 0.0;
      for (i = 0; i != MASK_N; ++i) {
              total += val[i] * val[i];
      }

          total = sqrt(total);
         
      if (total - threshold >= 0) {
        // black
        *(image_t + byte_per_pixel * (width * y + x) + 2) = BLACK;
        *(image_t + byte_per_pixel * (width * y + x) + 1) = BLACK;
        *(image_t + byte_per_pixel * (width * y + x) + 0) = BLACK;
      } else {
        // white
        *(image_t + byte_per_pixel * (width * y + x) + 2) = WHITE;
        *(image_t + byte_per_pixel * (width * y + x) + 1) = WHITE;
        *(image_t + byte_per_pixel * (width * y + x) + 0) = WHITE;
      }
    }
  }
 
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
 
int main() {
  read_bmp("lena.bmp"); // 24 bit gray level image
  sobel(90.0);
  write_bmp("lena_sobel.bmp");
}
