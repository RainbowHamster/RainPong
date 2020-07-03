#include <SDL2/SDL.h>
#include "concepts.h"
#include "config.h"
#include "game.h"
#include "object.h"

void handleEvents(struct Game *game)
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    if (event.type == SDL_QUIT)
    {
      game->isNeedToQuit = 1;
    }

    if (event.type == SDL_KEYUP)
    {
      if (event.key.keysym.scancode == KEY_LEFT_PLAYER_UP || 
          event.key.keysym.scancode == KEY_LEFT_PLAYER_DOWN)
      {
        game->leftPlayer->speed.y = 0;
      }
      if (event.key.keysym.scancode == KEY_RIGHT_PLAYER_UP || 
          event.key.keysym.scancode == KEY_RIGHT_PLAYER_DOWN)
      {
        game->rightPlayer->speed.y = 0;
      }
      if (event.key.keysym.scancode == SDL_SCANCODE_SPACE &&
          game->ball->state != BALL_STATE_FLY)
      {
        game->ball->speed.x = game->ball->speed.max * game->ball->state;
        game->ball->speed.y = game->ball->speed.max * game->ball->state;
        game->ball->state = BALL_STATE_FLY;
      }
    }

    if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.scancode == KEY_LEFT_PLAYER_UP)
      {
        game->leftPlayer->speed.y = game->leftPlayer->speed.max * -1;
      }
      if (event.key.keysym.scancode == KEY_LEFT_PLAYER_DOWN)
      {
        game->leftPlayer->speed.y = game->leftPlayer->speed.max;
      }
      if (event.key.keysym.scancode == KEY_RIGHT_PLAYER_UP)
      {
        game->rightPlayer->speed.y = game->rightPlayer->speed.max * -1;
      }
      if (event.key.keysym.scancode == KEY_RIGHT_PLAYER_DOWN)
      {
        game->rightPlayer->speed.y = game->rightPlayer->speed.max;
      }
    }
  }
}
