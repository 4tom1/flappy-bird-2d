#ifndef _SETTINGS_
#define _SETTINGS_

// ***Window & graphics***
#define HIGHT 650
#define WIDTH 500
#define FRAME_RATE 60

// ***Sound***
#define VOLUME 1 // % proc.

// ***Gameplay settings***

// Bird settings
#define BIRD_SPEED 150 / FRAME_RATE
#define BIRD_ACCELERATION_CHANGE 0.1
#define BIRD_ANIM_FRAME_RATE 12
// Start
#define BIRD_START_JUMP_SPEED 30 / FRAME_RATE
#define BIRD_START_ACCELERATION 1
#define BIRD_START_FLY 5
// Playing
#define BIRD_PLAYING_JUMP_SPEED 180 / FRAME_RATE
#define BIRD_PLAYING_ACCELERATION 1.5
#define BIRD_PLAYING_ROTATION_SPEED 6

// Pipe settings
#define PIPE_CLOSENESS 130
#define PIPE_CONSISTENCY 250
#define PIPE 5
#define PIPE_SPAWNPOINT WIDTH + PIPE_CONSISTENCY / 2
#define PIPE_DESPAWNPOINT -1 * WIDTH - PIPE_CONSISTENCY / 2
#define PIPE_RANDOM_SIZE 50
#define PIPE_SIZE 1.5

#endif