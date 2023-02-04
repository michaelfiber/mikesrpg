#include "raylib.h"
#include "drawimage.h"

Image PaletteImageToImage(PaletteImage *pimg)
{
	Image img = {0};
	Color *data = (Color *)MemAlloc(sizeof(Color) * pimg->width * pimg->height);
	for (int x = 0; x < pimg->width; x++)
	{
		for (int y = 0; y < pimg->height; y++)
		{
			data[y * pimg->width + x] = pimg->palette[pimg->data[y * pimg->width + x]];
		}
	}
	return (Image){
		.data = data,
		.width = pimg->width,
		.height = pimg->height,
		.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};
}

void ClearImage(Image *img, Color color)
{
	Color *data = img->data;
	for (int x = 0; x < img->width; x++)
	{
		for (int y = 0; y < img->height; y++)
		{
			data[y * img->width + x] = color;
		}
	}
}

void DrawImageRec(Image *img, int x, int y, int width, int height, Color color)
{
	Color *data = img->data;

	for (int xf = x; xf < x + width; xf++)
	{
		for (int yf = y; yf < y + height; yf++)
		{
			data[yf * img->width + xf] = color;
		}
	}
}

void DrawImagePixel(Image *img, int x, int y, Color color)
{
	Color *data = img->data;
	data[y * img->width + x] = color;
}