#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <SDL2/SDL.h>
#include "Image.hpp"

namespace RT
{
    class Scene
    {
    public:
        // Constructor
        Scene();

        // Rendering
        bool Render(Image &outputImage);

        // Functions
    private:
        // Members
    private:
    };
}

#endif