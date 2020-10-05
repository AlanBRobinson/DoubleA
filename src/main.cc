#include "./SDL.h"
#include <stdio.h>
#include "./Camera.cc"
#include "./Player.cc"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
  bool running = true;
  SDL_Window* window = NULL;
  SDL_Surface*  screenSurface = NULL;
  printf( "Started");
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
  } else {
    //Create window
    window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( window == NULL ) {
      printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    } else {
      //Get window surface
      screenSurface = SDL_GetWindowSurface( window );
    }
  }

  auto camera = new Camera(screenSurface);
  auto player = new Player();
  while(running) {
    SDL_Event event;
    /* DRAWING */
    //Fill the surface white
    SDL_FillRect(
      screenSurface,
      NULL,
      SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF )
    );
    player->draw(camera);

    //Update the surface
    SDL_UpdateWindowSurface( window );
    /* INPUT POLLING */
    while( SDL_PollEvent( &event ) ){
      /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
      switch( event.type ){
        case SDL_KEYDOWN:
          printf( "Key press detected\n" );
          running = false;

          SDL_Quit();
          exit( 0 );
          break;

        case SDL_KEYUP:
          printf( "Key release detected\n" );
          break;

        default:
          break;
      }
    }
    //Wait two seconds
    SDL_Delay( 1000 );
  }
  return 1;
}

// int WinMain(int argc, char *argv[]) {
//   return main(argc, argv);
// }
