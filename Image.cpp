#include "Image.h"

Image::Image(std::string filename, bool transparent_background){
	image = IMG_Load(filename);
}
