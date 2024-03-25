//
// Created by Vincent on 25.03.24.
//

#ifndef SDLFORMS_VECTOR1_H
#define SDLFORMS_VECTOR1_H

namespace Containers{
    struct Vector1 {
    public:
        int x;

        Vector1() {
            x = 0;
        }

        Vector1(int x, int y){
            this->x = x;
        }

        void Fill(int x, int y)
        {
            this->x = x;
        }
    };
}

#endif //SDLFORMS_VECTOR1_H
