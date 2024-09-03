#ifndef _SETTINGS_
#define _SETTINGS_

// ***Window & graphics***
#define HIGHT 650
#define WIDTH 500
#define FRAME_RATE 60

// ***Sound***
#define VOLUME 1 // % proc.

// ***Gameplay settings***

#define HIGHT_LIMIT -50

// Bird settings
#define BIRD_POS_Z 4
#define BIRD_SPEED 180 / FRAME_RATE
#define BIRD_ACCELERATION_CHANGE 0.1
#define BIRD_ANIM_FRAME_RATE 12
#define BIRD_COLLIDER_WIDTH 1 // % proc.
#define BIRD_COLLIDER_HIGHT 1 // % proc.
// Start
#define BIRD_START_JUMP_SPEED 30 / FRAME_RATE
#define BIRD_START_ACCELERATION 1 
#define BIRD_START_FLY 5
// Playing
#define BIRD_PLAYING_JUMP_SPEED 180 / FRAME_RATE
#define BIRD_PLAYING_ACCELERATION 1.5
#define BIRD_PLAYING_ROTATION_SPEED 6

// Pipe settings
#define PIPE_POS_Z 3 
#define PIPE_CLOSENESS 130
#define PIPE_CONSISTENCY 250
#define PIPE (WIDTH + PIPE_CONSISTENCY) / PIPE_CONSISTENCY
#define PIPE_SPAWNPOINT WIDTH + PIPE_CONSISTENCY / 2
#define PIPE_DESPAWNPOINT PIPE_CONSISTENCY / 2 * -1
#define PIPE_RANDOM 100
#define PIPE_SIZE 1.5

// Base settings
#define BASE_POS_Z 4
#define BASE_COLLIDER_HIGHT 85

// Board settings
#define	BOARD_POS_Z 10
#define BOARD_HIGHT 100
#define BOARD_SCORE_HIGHT 75
#define BOARD_BEST_HIGHT 205
#define BOARD_NUMBER_SIZE 1.5

// Restart button settings
#define RESBUT_POS_Z 10
#define RESBUT_HIGHT 150

// Score settings
#define SCORE_POS_Z 10

// Background settings
#define BACKGROUND_POS_Z 1

#endif