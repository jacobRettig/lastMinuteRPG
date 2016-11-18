#ifndef MAP_H
#define MAP_H

#include "gameMechanics"

typedef struct
{
  const int type; //type of tile (used to identify which union to use)

  /*
   * if there is no event triggered by interacting with this tile then it is left as a null pointer
   * otherwise when ever an action is done to this tile this will be called with all the relevant info
   */
  void (*eventTrigger) (GameMap *gameMap, Entity *entityCause, int actionCode, Vec2i tileCoord);

  union
  {
    typedef struct
    {
      unsigned char isLocked:1;
      unsigned char isOpen:1;
      rawImgID imgOpen;
      rawImgID imgClosed;
    } door;
    typedef struct
    {
      unsigned char isLocked:1;
      unsigned char canOpen:1;
      unsigned char isOpen:1;
      rawImgID imgLocked;
      rawImgID imgUnlocked;
      rawImgID imgOpen;
    } chest;
  };
} TileInfo;


typedef struct
{
  /*
   * is 0 if object is solid and entities can NOT pass through or 1 if
   * entities can
   */
  unsigned char canCollide:1;

  RawImgID baseTile; //first raw tile to be drawn

  /*
   * if not a null pointer then contains a list of raw tiles to be drawn
   * from start until a null pointer is reached
   */
  RawImgID *stackedTiles;

  /*
   * place to store extra info such as if need be
   * otherwise left as a null pointer
   */
  TileInfo *extraInfo;
} Tile;


typedef struct
{
  /*
   * Bounds for GameMap's tile map (x, y are offsets for coords and w,h are
   * width, height for tile map
   */
  Vec2i coords;
  Vec2ui size;
  RawImgID defaultTileImg; //default image shown by each new tile
  Tile *tileMap; //tile map

  int nEntities; //number of entities with values in entities
  Entity *entities [MAX_ENTITIES]; //contains pointers to all entities on GameMap
} GameMap;


/*
 * Generate a new GameMap
 * params:
 *  left: leftmost coordinate in tileMap
 *  top: topmost coordinate in tileMap
 *  width: width of tileMap
 *  height: height of tileMap
 *  defaultTileID: ID for image that all tiles default to
 */
GameMap *newGameMap (int left, int top, unsigned int width, unsigned int height, RawImgID defaultTileID);

/*
 * Frees up all memory taken up by tileMap, and entities (including player)
 */
void deleteGameMap (GameMap *gameMap);

/*
 * runs through all the entities to check for invalid collisions
 * returns -1 if there are no invalid collisions else returns
 * the index of the first entity that has an invalid collision
 */
int invalidCollisions (GameMap *gameMap);

/*
 * gets tile at position specified with x, y in tileMap
 */
Tile *getTileAt (GameMap *gameMap, int x, int y);

/*
 * modifies the game map to match coordinates, all new tiles are filled with the default tile image and aren't collidable
 * params:
 *  gameMap: game map to be modified
 *  left: leftmost coordinate in tileMap
 *  top: topmost coordinate in tileMap
 *  width: width of tileMap
 *  height: height of tileMap
 */
void resizeGameMap (GameMap *gameMap, int left, int top, unsigned int width, unsigned int height);

/*
 * Add entity to entities list
 * returns pointer to position in entities on success or
 * a null pointer if there is no space available or entity parameter is a null pointer
 */
Entity **addEntity (GameMap *gameMap, Entity *entity);

/*
 * Searches through entities list and finds given entity
 * return entity pointer being removed from entities on success
 * otherwise returns a  null pointer if not located or entity parameter is a null pointer
 * (Note only removes first instance if it is in entities list twice which ideally should never happen)
 */
Entity *removeEntity (GameMap *gameMap, Entity *entity);

/*
 * gives tile default values using rawImgID
 */
void initTile (Tile *tile, RawImgID rawImgID);

/*
 * frees dynamic memory that might be allocated in tile
 */
void deleteTileContents (Tile *tile);

/*
 * generates and returns a C string in JSON format containing state of gameMap
 */
const char *getGameMapJSON (GameMap *gameMap);

/*
 * generates and returns a GameMap from C string in JSON format containing the state of a GameMap
 */
GameMap *loadGameMapJSON (const char *gameMapJSON);

/*
 * updates gameMap (this is the function running in the primary game loop)
 */
void updateGameMap (GameMap *gameMap);

/*
 * renders gameMap
 */
void renderGameMap (GameMap *gameMap);


#endif
