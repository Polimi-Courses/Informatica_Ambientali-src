#include <stdio.h>

/*A PPM file consists of a sequence of one or more PPM images. There are no
data, delimiters, or padding before, after, or between images.

Each PPM image consists of the following:

1) A "magic number" for identifying the file type. A ppm image's magic number is
the two characters "P6". 2) Whitespace (blanks, TABs, CRs, LFs). 3) A width,
formatted as ASCII characters in decimal. 4) Whitespace. 5) A height, again in
ASCII decimal. 6) Whitespace. 7) The maximum color value (Maxval), again in
ASCII decimal. Must be less than 65536 and more than zero. 8) A single
whitespace character (usually a newline). 9) A raster of Height rows, in order
from top to bottom. Each row consists of Width pixels, in order from left to
right. Each pixel is a triplet of red, green, and blue samples, in that order.
Each sample is represented in pure binary by either 1 or 2 bytes. If the Maxval
is less than 256, it is 1 byte. Otherwise, it is 2 bytes. The most significant
byte is first. A row of an image is horizontal. A column is vertical. The pixels
in the image are square and contiguous.
Try with ~head -3 file.ppm~ to check the first parameters.

------------
We want to transform the original file in black and white
 */
int main(int argc, char *argv[]) {
  // rb for read byte
  FILE *f = fopen("data/LenaSoderberg.ppm", "rb");

  unsigned int height, width, max_val;
  fscanf(f, "P6 %u %u %u ", &height, &width, &max_val);

  fprintf(stdout, "H: %u, W: %u, MAX: %u\n", height, width, max_val);

  FILE *f_bw = fopen("data/LenaSoderberg_bw.ppm", "wb");
  fprintf(f_bw, "P6 %u %u %u\n", height, width, max_val);
  for (int r = 0; r < height; ++r) {
    for (int c = 0; c < width; ++c) {
      // 3 byte for each pixel (assuming max_val == 255)
      unsigned char color[3];
      // Read from file f into array color 3 elements of size 1 byte
      // It automatically reads from the first unread element of the file
      fread(color, 1, 3, f);

      // buffer with the converted colors for black and white
      unsigned char color_bw[3];
      // a way to transform a color in grayscale is:
      // 0.3R + 0.6G + 0.1B
      for (int i = 0; i < 3; ++i) {
        color_bw[i] =
            (unsigned char)(0.3 * color[0] + 0.6 * color[1] + 0.1 * color[2]);
      }
      fwrite(color_bw, 1, 3, f_bw);
    }
  }

  fclose(f);
  fclose(f_bw);
  return 0;
}
