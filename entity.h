#ifndef ENTITY_H
#define ENTITY_H
/*
 * TODO: Add mechanics for holding sprite costume settings
 */

#include "gameMechanics.h"


typedef struct
{
} CostumeData;


typedef struct
{
  RawImgID rawImgID;
} DroppedItem;

typedef struct
{
  Vec2f pos; //Current coordinates on map (given unit is tiles)
  float rad; //radius on map (given unit is tiles)
  float movSpd; //movement speed on map (given unit is tiles per second)
  int facing; //the direction is the entity facing
  unsigned char canCollide:1; //Can collidable entities collide with this one

  int nInventory; //Size of inventory (0 if no inventory and Item *inventory is a null pointer)
  Item *inventory; //storage for inventory (if no inventory then it's a null pointer)

  unsigned char isMob:1; //Is entity a mob or dropped item
  union
  {
    typedef struct
    {
      unsigned char isPlayer:1;
      unsigned char isAlly:1;

      int maxHp; //Maximum health points (full health)
      int hp; //current health points

      float def; //Defense

      float atkAcc; //Attack accuracy
      float atkPow; //Attack power
      float atkSpd; //Attack speed
      float atkCool; //Attack cooldown
    } mob;
    DroppedItem *drop;
  };
} Entity;


/*
 * returns the position farthest along movement for the Entity, entity,
 * that doesn't collide with an entity or non-collide tile
 */
Vec2f entityTryMovement (Entity *entity, GameMap *gameMap, Vec2f movement);

/*
 * return the distance between entity1 and entity2 squared
 */
float entityDistSq (Entity *entity1, Entity *entity2);

/*
 * returns 1 if collision is detected, 0 if not
 */
int isEntityCollidingEntity (Entity *entity1, Entity *entity2);
int isEntityCollidingTile (Entity *entity, int tileX, int tileY);


#endif
