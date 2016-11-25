#ifndef SPRITE_H
#define SPRITE_H

typedef struct
{
  int drawLayer;
  int hasImage:1;
  const char *name, *fpath;
  void *ss;
} Costume;


typedef struct
{
  const char *name;
  int nCostumes;
  Costume *costumes;
} MobBodyPart;

typedef struct
{
  MobBodyPart body, nose, eyes, ears;
} MobBodyCostumes;

typedef struct
{
  Costume costume;

  int isMale:1;
  int isFemale:1;

  int nInvalidBodies;
  const char **invalidBodies;
} ExtraCostume;

typedef struct
{
  const char *name;
  int nExtraCostumes;
  ExtraCostume *extraCostumes;
} ExtraCostumePart;

typedef struct
{
  int nExtraCostumeParts;
  ExtraCostumePart *extraCostumeParts;
} ExtraCostumes;

typedef struct
{
  MobBodyCostumes mobBodyCostumes;
  ExtraCostumes extraCostumes;
} CostumeList;

/*
 * creates a new dynamically allocated Costume with newly allocated C strings
 */
static Costume *newCostume (const char *name, int hasImage, int drawLayer, const char *fpath);

/*
 * deletes all dynamically allocated data in a Costume (not the Costume pointer itself)
 */
static void deleteCostume (Costume *costume);

/*
 * adds a Costume to a MobBodyPart
 */
static void addToBodyPartCostume (MobBodyPart *mobBodyPart, Costume costume);

/*
 * creates a new dynamically allocated ExtraCostume with newly allocated C strings
 */
static ExtraCostume *newExtraCostume (Costume *costume, int isMale, int isFemale);

/*
 * deletes all dynamically allocated data in a ExtraCostume (not the ExtraCostume pointer itself)
 */
static void deleteExtraCostume (ExtraCostume *extraCostume);

/*
 * adds an ExtraCostume to ExtraCostumePart
 */
static void addToExtraCostumePart (ExtraCostumePart *extraCostumePart, ExtraCostume *extraCostume);

/*
 * creates a new dynamically allocated ExtraCostumePart with newly allocated name
 */
static ExtraCostumePart *newExtraCostumePart (const char *name);

/*
 * creates a new dynamically allocated ExtraCostumes
 */
static ExtraCostumes *newExtraCostumes (void);

/*
 * creates a new dynamically allocated MobBodyCostumes
 */
static MobBodyCostumes *newMobBodyCostumes (void);


extern static CostumeList *COSTUME_LIST;

#endif
