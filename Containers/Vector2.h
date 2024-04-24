#ifndef SDLFORMS_VECTOR2_H
#define SDLFORMS_VECTOR2_H

namespace Containers{
    struct Vector2 {
    public:
        int *x, *y;

        Vector2() {
            x = new int();
            y = new int();
            *x = 0;
            *y = 0;
        }

        Vector2(int x, int y){
            this->x = new int();
            this->y = new int();
            *this->x = x;
            *this->y = y;
        }

        void Fill(int x, int y){
            *this->x = x;
            *this->y = y;
        }

        ~Vector2() {
            delete x;
            delete y;
        }
    };
}

#endif
