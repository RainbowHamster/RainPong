#ifndef _GAME_H_
#define _GAME_H_

struct Game
{
  /* Next one string declare all objects that
   * need to be rendered and handled their behavior */
  struct Object **objects;
  struct Object *ball;
  struct Object *leftPlayer;
  struct Object *rightPlayer;
  int leftPlayerScore;
  int rightPlayerScore;
  int isNeedToQuit;
};

void createGame(struct Game*);

#endif
