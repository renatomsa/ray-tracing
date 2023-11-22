#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>

class Image
{
public:
    // Constructor
    Image();

    // Destructor
    ~Image();

    // Function Init
    void Initialize(const int xSize, const int ySize, SDL_Renderer *pRenderer);

    // Function SetPixel
    void SetPixel(const int x, const int y, const double red, const double green, const double blue);

    // Function Display
    void Display();

    // Return dimensions
    int GetXsize();
    int GetYsize();

private:
    Uint32 ConvertColor(const double red, const double green, const double blue);
    void InitTexture();

private:
    // Array of pixels
    std::vector<std::vector<double>> m_rChannel;
    std::vector<std::vector<double>> m_gChannel;
    std::vector<std::vector<double>> m_bChannel;

    // Size of the image
    int m_xSize, m_ySize;

    // SDL2 stuff
    SDL_Renderer *m_pRenderer;
    SDL_Texture *m_pTexture;
};

#endif