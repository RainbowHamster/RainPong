#ifndef _CONFIG_H_
#define _CONFIG_H_

#define VERSION                 "0.8"
#define WINDOW_WIDTH            640
#define WINDOW_HEIGHT           480
#define WINDOW_TITLE_PREFIX     "RainPong"
#define WINDOW_TITLE_MAX_LENGTH 100
#define PLAYER_WIDTH            10
#define PLAYER_HEIGHT           50
#define BALL_WIDTH              10
#define BALL_HEIGHT             10
#define FRAME_DELAY             10
#define PLAYER_OFFSET           10
#define PLAYER_MAX_SPEED        5
#define BALL_MAXSPD             5
#define BALL_STATE_FLY          0
#define BALL_STATE_LEFT         1
#define BALL_STATE_RIGHT        -1
#define BACKGROUND_MUSIC_PATH   "/home/rh/workdir/pong2/resources/bgsound.wav"
#define PONG_SOUND_PATH         "/home/rh/workdir/pong2/resources/pong.wav"

extern const struct Color BG_COLOR;
extern const struct Color PLAYER_COLOR;
extern const struct Color BALL_COLOR;
extern const int KEY_LEFT_PLAYER_UP;
extern const int KEY_LEFT_PLAYER_DOWN;
extern const int KEY_RIGHT_PLAYER_UP;
extern const int KEY_RIGHT_PLAYER_DOWN;
extern const int KEY_BALL_LAUNCH;

#endif
