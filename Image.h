#ifndef IMAGE_H
#define IMAGE_H

#ifdef WIN32
#include <SDL_image.h>
#else
#include <SDL/SDL_image.h>
#endif

#include <string>

class Image {
	public:
		Image();
		Image(char* filename, bool transparent_background);
		~Image();
	private:
		SDL_Surface *image;
		char* filename;
		bool transparent_background; //En boolean som anger om bildens bakgrund ska vara genomskinlig eller ej
};

#endif
