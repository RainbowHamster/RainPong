#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "concepts.h"
#include "config.h"
#include "object.h"
#include "game.h"
#include "evhandler.h"


void renderObjects(SDL_Renderer *renderer, struct Object **objects)
{
  SDL_SetRenderDrawColor(renderer, BG_COLOR.r, BG_COLOR.g, BG_COLOR.b, BG_COLOR.a);
  SDL_RenderClear(renderer);
 
  for(int i = 0; objects[i] != NULL; i++)
  {
    SDL_SetRenderDrawColor(
        renderer,
        objects[i]->color.r,
        objects[i]->color.g,
        objects[i]->color.b,
        objects[i]->color.a
    );

    SDL_Rect rect = {
      objects[i]->pos.x,
      objects[i]->pos.y,
      objects[i]->size.w,
      objects[i]->size.h,
    };

    SDL_RenderFillRect(renderer, &rect);
  }

  SDL_RenderPresent(renderer);
}

void handleSDLError(char* moduleName)
{
    printf("SDL_%s Error: %s\n", moduleName, SDL_GetError());
    exit(1);
}

int main(int argc, char* argv[])
{
  struct Game *game;
  game = malloc(sizeof(struct Game));
  createGame(game);

  if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    handleSDLError("Init");

  atexit(SDL_Quit);

  SDL_Window *window = SDL_CreateWindow(
      WINDOW_TITLE_PREFIX,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      WINDOW_WIDTH,
      WINDOW_HEIGHT,
      SDL_WINDOW_SHOWN);
  if(window == NULL)
    handleSDLError("CreateWindow");

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
  if(renderer == NULL)
    handleSDLError("CreateRenderer");

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) != 0)
    handleSDLError("Mixer");

  if (Mix_AllocateChannels(4) < 0)
    handleSDLError("Mixer");

  Mix_Chunk *backgroundMusic = Mix_LoadWAV(BACKGROUND_MUSIC_PATH);
  Mix_PlayChannel(-1, backgroundMusic, -1);
  
  while(!game->isNeedToQuit)
  {
    char *newWindowTitle;
    newWindowTitle = calloc(WINDOW_TITLE_MAX_LENGTH, sizeof(char));

    handleEvents(game);

    for(int i = 0; game->objects[i] != NULL; i++)
      if(game->objects[i]->behavior != NULL)
        game->objects[i]->behavior(game, game->objects[i]);

    sprintf(newWindowTitle, "%s %d:%d  ver: %s", WINDOW_TITLE_PREFIX,
        game->leftPlayerScore, game->rightPlayerScore, VERSION);
    SDL_SetWindowTitle(window, newWindowTitle);

    renderObjects(renderer, game->objects);

    SDL_Delay(FRAME_DELAY);
  }

  return 0;
}
