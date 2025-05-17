
#include<string>
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3/SDL_filesystem.h>
#include<SDL3/SDL_log.h>



// use SDL App Callbacks :
// https://wiki.libsdl.org/SDL3/SDL_MAIN_USE_CALLBACKS
// based on lazyfoo --> see examples in repo for more sophisticated setups
// #define SDL_MAIN_USE_CALLBACKS 1

bool init();
bool loadMedia();
void close();

// alternative --> bundle SDL App components to struct
// typedef struct
// {
//     SDL_Window* FIWindow;
//     SDL_Renderer* FIRenderer;
//     Uint64 last_step;
// } AppState;

// then initialize to nullptr using     AppState* state = (AppState*)SDL_calloc(1, sizeof(AppState));

SDL_Surface* FISurface{nullptr};
SDL_Surface* FIHelloWorld{nullptr};
SDL_Window* FIWindow{nullptr};
SDL_Renderer* FIRenderer{nullptr};
int64_t last_step;



int main(int, char**){
    int exitCode = 0;
    if(!init()){
        SDL_Log("Could not initialize program!\n");
        exitCode = 1;
    }
    else{
        if (!loadMedia()){
            SDL_Log("Unable to load image!\n");
            exitCode = 2;
        }
    }

    bool quit = false;

    SDL_Event event;
    SDL_zero(event);

    while(!quit){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_EVENT_QUIT){
                quit = true;
            }
        }
        SDL_FillSurfaceRect(FISurface, nullptr, SDL_MapSurfaceRGB(FISurface, 0xFF, 0xFF, 0xFF));

        SDL_BlitSurface(FIHelloWorld, nullptr, FISurface, nullptr );

        SDL_UpdateWindowSurface(FIWindow);
    }

    return exitCode;
}

bool init()
{
    bool success = false;
    
    // initialize SDL
    if( !SDL_Init( SDL_INIT_VIDEO )){
        SDL_Log("Could not initialize %s\n", SDL_GetError());
        return success;
    }



    if(FIWindow = SDL_CreateWindow("Template",1600,600,SDL_WINDOW_RESIZABLE); FIWindow == nullptr){
        SDL_Log("Window could not be created: %s\n", SDL_GetError());
        return success;
    }

    FISurface = SDL_GetWindowSurface(FIWindow);
    success = true;
    return success;

}

bool loadMedia(){
    bool success = false;
    std::string imageLocation = std::string(SDL_GetBasePath()) + "assets/hello.bmp";

    printf("Working Directory: %s\n", SDL_GetBasePath() );

    if (FIHelloWorld = SDL_LoadBMP(imageLocation.c_str()); FIHelloWorld == nullptr)
    {
        SDL_Log("Unable to load image: %s\n", SDL_GetError());
        return success;
    }

    success = true;
    return success;

}

void close(){
    // clean surface
    SDL_DestroySurface(FIHelloWorld);
    FIHelloWorld = nullptr;

    // destroy window
    SDL_DestroyWindow(FIWindow);

    // quit SDL Subsystems
    SDL_Quit();

}
