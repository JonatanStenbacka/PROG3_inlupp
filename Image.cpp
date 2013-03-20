#include "Image.h"

Image::Image(std::string filename, bool transparent_background){
	this->image = IMG_Load(filename);
}