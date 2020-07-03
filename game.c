#include <stdlib.h>
#include "concepts.h"
#include "config.h"
#include "object.h"
#include "game.h"
#include "behaviors.h"

void createGame(struct Game *game)
{
  struct Object leftPlayer = {
    .size  = {PLAYER_WIDTH, PLAYER_HEIGHT},
    .pos   = {PLAYER_OFFSET, (WINDOW_HEIGHT - PLAYER_HEIGHT) / 2},
    .color = PLAYER_COLOR,
    .speed = {0, 0, PLAYER_MAX_SPEED},
    .behavior = &playerBehavior,
  };

  struct Object rightPlayer = {
    .size  = {PLAYER_WIDTH, PLAYER_HEIGHT},
    .pos   = {WINDOW_WIDTH - PLAYER_WIDTH - PLAYER_OFFSET,
             (WINDOW_HEIGHT - PLAYER_HEIGHT) / 2},
    .color = PLAYER_COLOR,
    .speed = {0, 0, PLAYER_MAX_SPEED},
    .behavior = &playerBehavior,
  };

  struct Object ball = {
    .size  = {BALL_WIDTH, BALL_HEIGHT},
    .pos   = {0, 0},
    .color = BALL_COLOR,
    .speed = {0, 0, BALL_MAXSPD},
    .state = BALL_STATE_LEFT,
    .behavior = &ballBehavior,
  };

  struct Game tempGame = {
    .ball  = malloc(sizeof(struct Object)),
    .leftPlayer  = malloc(sizeof(struct Object)),
    .rightPlayer = malloc(sizeof(struct Object)),
    .leftPlayerScore = 0,
    .rightPlayerScore = 0,
    .objects = calloc(4, sizeof(struct Object*)),
    .isNeedToQuit = 0
  };
  *tempGame.leftPlayer  = leftPlayer;
  *tempGame.rightPlayer = rightPlayer;
  *tempGame.ball  = ball;

  for(int i = 0; i < 4; i++)
    tempGame.objects[i] = malloc(sizeof(struct Object));

  tempGame.objects[0] = tempGame.leftPlayer;
  tempGame.objects[1] = tempGame.rightPlayer;
  tempGame.objects[2] = tempGame.ball;
  tempGame.objects[3] = NULL;

  *game = tempGame;
}
