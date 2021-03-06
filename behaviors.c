#include <stdlib.h>
#include "concepts.h"
#include "object.h"
#include "config.h"
#include "game.h"
#include "behaviors.h"
#include "SDL2/SDL_mixer.h"

void playerBehavior(struct Game *game, struct Object *player)
{
  int lowPos = WINDOW_HEIGHT - player->size.h;

  player->pos.y += player->speed.y;
  if(player->pos.y > lowPos)
    player->pos.y = lowPos;
  else if(player->pos.y < 0)
    player->pos.y = 0;
}

void ballBehavior(struct Game *game, struct Object *ball)
{
  Mix_Chunk *pongSound = Mix_LoadWAV(PONG_SOUND_PATH);
  int lowPos = WINDOW_HEIGHT - ball->size.h;

  if(ball->state == BALL_STATE_LEFT)
  {
    ball->pos.x = game->leftPlayer->pos.x + game->leftPlayer->size.w + 1;
    ball->pos.y = game->leftPlayer->pos.y + (game->leftPlayer->size.h - ball->size.h) / 2;
    return;
  }
  if(ball->state == BALL_STATE_RIGHT)
  {
    ball->pos.x = game->rightPlayer->pos.x - ball->size.w - 1;
    ball->pos.y = game->rightPlayer->pos.y + (game->rightPlayer->size.h - ball->size.h) / 2;
    return;
  }

  ball->pos.y += ball->speed.y;
  ball->pos.x += ball->speed.x;

  if(ball->pos.y < 0)
  {
    ball->pos.y = 0;
    ball->speed.y *= -1;
    Mix_PlayChannel(-1, pongSound, 0);
  }
  else if(ball->pos.y > lowPos)
  {
    ball->pos.y = lowPos;
    ball->speed.y *= -1;
    Mix_PlayChannel(-1, pongSound, 0);
  }

  if(ball->pos.x > WINDOW_WIDTH)
  {
    game->leftPlayerScore++;
    ball->state = BALL_STATE_RIGHT;
  }

  else if(ball->pos.x < 0 - BALL_WIDTH)
  {
    game->rightPlayerScore++;
    ball->state = BALL_STATE_LEFT;
  }
  for(int i = 0; game->objects[i] != NULL; i++)
  {
    if(game->objects[i] != ball)
      if(isColliding(ball, game->objects[i]))
      {
        ball->speed.x *= -1;
        Mix_PlayChannel(-1, pongSound, 0);
      }
  }
}

void isColliding(struct Object* dynamicObject, struct Object* staticObject)
{
  int dynamicObjectLeftEdge   = dynamicObject->pos.x;
  int dynamicObjectTopEdge    = dynamicObject->pos.y;
  int dynamicObjectBottomEdge = dynamicObjectTopEdge + dynamicObject->size.h;
  int dynamicObjectRightEdge  = dynamicObjectLeftEdge + dynamicObject->size.w;

  int staticObjectLeftEdge    = staticObject->pos.x;
  int staticObjectTopEdge     = staticObject->pos.y;
  int staticObjectBottomEdge  = staticObjectTopEdge + staticObject->size.h;
  int staticObjectRightEdge   = staticObjectLeftEdge + staticObject->size.w;

  int yCollision = dynamicObjectTopEdge <= staticObjectBottomEdge &&
                   dynamicObjectBottomEdge >= staticObjectTopEdge;

  if (yCollision & (dynamicObjectLeftEdge <= staticObjectRightEdge &&
                    dynamicObjectRightEdge >= staticObjectLeftEdge))
    return 1;
  return 0;
}
