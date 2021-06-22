#include "./SDL.h"
#include <stdio.h>
#include "./Camera.cc"
#include "./Player.cc"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


void handleArrow(SDL_Keycode key, Player*player) {
  switch(key) {
    case SDLK_UP: {
      printf("SDLK_UP\n");
      // do "up arrow stuff"
      player->speed = player->speed.addVector(Vector(0, -2));
      break;
    }
    case SDLK_DOWN: {
      printf("SDLK_DOWN\n");
      // do "down arrow stuff"
      player->speed = player->speed.addVector(Vector(0, 2));
      break;
    }
    case SDLK_LEFT: {
      printf("SDLK_LEFT\n");
      player->speed = player->speed.addVector(Vector(-2, 0));
      // do "left arrow stuff"
      break;
    }
    case SDLK_RIGHT: {
      printf("SDLK_RIGHT\n");
      player->speed = player->speed.addVector(Vector(2, 0));
      // do "right arrow stuff"
      break;
    }
    case SDLK_ESCAPE: {
      printf("Existing\n");
      SDL_Quit();
      exit( 0 );
      break;
    }
  }
}

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
    /** RUN TICKS */
    player->tick();

    /* DRAWING */
    //Fill the surface white
    SDL_FillRect(
      screenSurface,
      NULL,
      SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF )
    );

    player->draw(camera);
    player->decelerate();
    player->decelerate();
    player->decelerate();

    //Update the surface
    SDL_UpdateWindowSurface( window );

    /* INPUT POLLING */
    while( SDL_PollEvent( &event ) ){
      /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
      switch( event.type ){
        case SDL_KEYDOWN: {
          printf( "Key press detected\n" );
          auto key = event.key.keysym.sym;
          handleArrow(key, player);
          break;
        }

        case SDL_KEYUP: {
          printf( "Key release detected\n" );
          break;
        }

        default:
          break;
      }
    }
    //Wait two seconds
    SDL_Delay( 100 );
  }
  return 1;
}

// int WinMain(int argc, char *argv[]) {
//   return main(argc, argv);
// }