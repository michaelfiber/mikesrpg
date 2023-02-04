#ifndef DRAWIMAGE_H
#define DRAWIMAGE_H

#include "raylib.h"

typedef struct PaletteImage
{
	Color *palette;
	int *data;
	int width;
	int height;
} PaletteImage;

void ClearImage(Image *img, Color color);
Image PaletteImageToImage(PaletteImage *pimg);
void DrawImageRec(Image *img, int x, int y, int width, int height, Color color);
void DrawImagePixel(Image *img, int x, int y, Color color);

#endif