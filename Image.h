#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <string>

class Image{
	public:
		Image();
		Image(std::string filename, bool transparent_background);
		~Image();
	private:
		SDL_Surface * image;
		std::string filename;
		bool transparent_background; //En boolean som anger om bildens bakgrund ska vara genomskinlig eller ej.
};

#endif