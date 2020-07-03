#include "concepts.h"
#include "config.h"
#include <SDL2/SDL.h>

const struct Color BG_COLOR     = {0, 0, 0, 255};
const struct Color PLAYER_COLOR = {255, 255, 255, 255};
const struct Color BALL_COLOR   = {255, 255, 255, 255};

const int KEY_LEFT_PLAYER_UP    = SDL_SCANCODE_W;
const int KEY_LEFT_PLAYER_DOWN  = SDL_SCANCODE_S;
const int KEY_RIGHT_PLAYER_UP   = SDL_SCANCODE_UP;
const int KEY_RIGHT_PLAYER_DOWN = SDL_SCANCODE_DOWN;
const int KEY_BALL_LAUNCH       = SDL_SCANCODE_SPACE;
