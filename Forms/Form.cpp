#include "Form.h"

using namespace Forms;

void Form::StartWindowLoop()  { //starting loop sector
    std::cout << "Form.cpp >> Rendering Loop Started." << std::endl;
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
                //std::cout << "renderer outline reached";
                Controls->at(i)->Draw();
                //std::cout << "renderer outline completed";
            }
            renderer->CompleteRender();
        }
    }
    delete e;
    std::cout << "Form.cpp >> Rendering Loop Stopped. Closeup action issued?" << std::endl;
}

Form::Form(std::string title, Containers::Vector2 *position, Containers::Vector2 *size) { //parametrized constructor
    TTF_Init();
    this->Location = position;
    this->Size = size;
    this->title = title;

    window = SDL_CreateWindow(title.c_str(), position->x, position->y, size->x, size->y, 0);
    sdlRenderer = SDL_CreateRenderer(window, -1, 0);

    renderer = new Graphics::Renderer(sdlRenderer, window);
    textRenderer = new Graphics::TextRenderer(renderer, window);
    textRenderer->OpenFontFile("font.ttf", 24);

    Controls = new std::vector<IDrawable*>();

    BackgroundColor = new Graphics::Color();
    BackgroundColor->SetColor(Graphics::Black);

    std::cout << "Form.cpp >>> Parent Form Initialization completed." << std::endl;
}


void Form::Close() {
    textRenderer->CloseFontFile();
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
    std::cout << "Form.cpp >>> Bye, world! Being good to know ya. Form extinction completed.";
}

