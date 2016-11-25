#ifndef GAME_MECHANICS_H
#define GAME_MECHANICS_H

//max number of RawImg globally stored in RAW_IMGS
#define RAW_IMGS_SIZE 100
//Size of unit tile in pixels
#define TILE_SIZE 32
//max entities stored in GameMap
#define MAX_ENTITIES 300

//Cardinal directions
#define DIRECTION_N 0
#define DIRECTION_E 1
#define DIRECTION_S 2
#define DIRECTION_W 3

//Item types used by ItemPrototype
#define ITEM_TYPE_SWORD 0
#define ITEM_TYPE_SPEAR 1
#define ITEM_TYPE_WAND 2
#define ITEM_TYPE_BOW 3
#define ITEM_TYPE_ARROW 4
#define ITEM_TYPE_ARMOUR 5
#define ITEM_TYPE_MISC 6


/*
 * Simple 2D vectors
 */
typedef struct {float x, y;} Vec2f;
typedef struct {int x, y;} Vec2i;
typedef struct {unsigned int x, y;} Vec2ui;
typedef struct {char x, y;} Vec2ui;
typedef struct {unsigned char x, y;} Vec2uc;

/*
 * Simple Geometric shapes
 */
typedef struct
{
  float x, y, width, height;
} Rectangle;
typedef struct
{
  float x, y, radius;
} Circle;


/*
 * float hypot (x*x + y*y)
 */
inline float fhypot (float x, float y);

/*
 * returns the distance squared from a rectangle and a 2D float vector
 */
inline float hypotRectVec2f (Rectangle rect, Vec2f vec);

/*
 * returns the distance from a rectangle and a 2D float vector
 */
inline float distRectVec2f (Rectangle rect, Vec2f vec);

/*
 * returns 1 if rectangle and a 2D float vector overlap
 * else returns a 0 if tangent or not overlapping
 */
inline int isOverlapRectVect2f (Rectangle rect, Vec2f vec);

/*
 * returns 1 if rectangle and a circle overlap (not just tangent)
 * else returns a 0 if tangent or not overlapping
 */
inline int isOverlapRectCircle (Rectangle rect, Circle circle);

/*
 * returns the distance from a rectangle and a 2D float vector
 */
inline float distRectCircle (Rectangle rect, Circle circle);

/*
 * returns 1 if two circles overlap (not just tangent)
 * else returns a 0 if tangent or not overlapping
 */
inline int isOverlapCircleCircle (Circle circle1, Circle circle2);

/*
 * returns the distance from two circles
 */
inline float distanceCircleCircle (Circle circle1, Circle circle2);


/*
 * the offset of each RawImg stored in RAW_IMGS used to identify each one
 */
typedef unsigned char RawImgID;

/*
 * sprite sheet object (mostly for organization)
 */
typedef struct
{
  const char *name; //name of sprite sheet
  void *img; //image object
} SpriteSheet;

/*
 * Each sub-image found in a spritesheet
 */
typedef struct
{
  Vec2ui ssCoords; //sprite sheet coords (top left being origin) for the sub-image (in pixels)
  Vec2ui ssSize; //sprite sheet size (w, h) for the sub-image (in pixels)
  SpriteSheet *ss; //sprite sheet pointer
} RawImg;

/*
 * Global list of all RawImg used
 */
static RawImg RAW_IMGS [RAW_IMGS_SIZE];

/*
 * Prototype for items and storage for item properties
 */
typedef struct
{
  const int type; //one of the ITEM_TYPE_{something}
  const int maxUses; //if negative then unlimited
  const char *name; //item name

  /*
   * if 1 then when usesRemaining will be increased instead of taking
   * another spot in inventory otherwise if 0 then it will just take up
   * another spot in inventory when picked up
   */
  const unsigned char canBeStacked:1;

  RawImgID imgIconID; //Icon to display when dropped or in inventory
  SpriteSheet *ss; //if equipment then this is it's sprite sheet

  //equipment buffs
  const float movSpd;
  const int hp;
  const float def;
  const float atkAcc;
  const float atkPow;
  const float atkSpd;
  const float atkCool;
} ItemPrototype;

/*
 * Individual instance of item
 */
typedef struct
{
  ItemPrototype *prototype; //item's properties

  //modified property(s)
  int usesRemaining; //if negative then unlimited
  unsigned char isEquipted:1; //1 if it is, 0 if not
} Item;


#endif
