#include "Image.h"

Image::Image(char* filename, bool transparent_background){
	image = IMG_Load(filename);
}
