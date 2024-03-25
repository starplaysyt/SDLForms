#ifndef SDLFORMS_VECTOR2_H
#define SDLFORMS_VECTOR2_H

namespace Containers{
    struct Vector2 {
    public:
        int x, y;

        Vector2() {
            x = 0;
            y = 0;
        }

        Vector2(int x, int y){
            this->x = x;
            this->y = y;
        }

        void Fill(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
    };
}

#endif
