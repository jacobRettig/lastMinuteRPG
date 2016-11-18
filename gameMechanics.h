#ifndef GAME_MECHANICS_H
#define GAME_MECHANICS_H

typedef struct
{
  float x, y; //Current coordinates on map (given unit is tiles)
  float rad; //radius on map (given unit is tiles)
  float movSpd; //movement speed on map (given unit is tiles per second)

  int maxHp; //Maximum health points (full health)
  int hp; //current health points

  float atkAcc; //Attack accuracy
  float atkPow; //Attack power
  float atkSpd; //Attack speed
  float atkCool; //Attack cooldown
} Entity;

#endif
