#include "Form.h"

using namespace Forms;

void Form::StartWindowLoop()  { //starting loop sector
    std::cout << "WinLoopStarted" << std::endl;
    auto *e = new SDL_Event();
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(e) != 0) {
            switch (e->type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e->key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        case SDLK_w:
                            break;
                    }
                    break;
                case SDL_WINDOWEVENT:
                    break;
                case SDL_MOUSEMOTION:
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    break;
                case SDL_MOUSEBUTTONUP:
                    break;
            }
            renderer->SetColor(BackgroundColor);
            renderer->ClearRenderer();
            for (int i = 0; i < Controls->size(); ++i)
            {
                Controls->at(i)->Draw();
            }
            renderer->CompleteRender();
        }
    }
}

Form::Form(std::string title, Containers::Vector2 *position, Containers::Vector2 *size) { //parametrized constructor
    this->Location = position;
    this->Size = size;
    this->title = title;

    window = SDL_CreateWindow(title.c_str(), position->x, position->y, size->x, size->y, 0);
    sdlRenderer = SDL_CreateRenderer(window, -1, 0);

    renderer = new Graphics::Renderer(sdlRenderer, window);
    Controls = new std::vector<IDrawable*>();

    BackgroundColor = new Graphics::Color();
    BackgroundColor->SetColor(Graphics::Black);

    std::cout << "Form Init Completed" << std::endl;
}


void Form::Close() {
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Form::~Form() {
    delete Location;
    delete Size;
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    std::cout << "Bye, bro!";
}

