#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_

#include <iostream>
#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>

class Text {
	private:
		//members
		TTF_Font* font;
		SDL_Color color;

	public:
		Text();
		Text(SDL_Color);
		void RenderText(std::string, SDL_Color, float, float, int);
		unsigned int PowerTwoFloor(unsigned int);
		bool InitFont();
};
#endif // !_TEXT_H_