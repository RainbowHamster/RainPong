#ifndef _OBJECT_H_
#define _OBJECT_H_

struct Object
{
  int state;
  struct Pos   pos;
  struct Size  size;
  struct Color color;
  struct Speed speed;
  void (*behavior)(struct Game *game, struct Object *self);
};

#endif
