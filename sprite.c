#include <string.h>
#include "sprite.h"

static CostumeList *COSTUME_LIST = {.mobBodyCostumes=newMobBodyCostumes(), .extraCostumes=newExtraCostumes()};


/*
 * creates a new dynamically allocated Costume with newly allocated C strings
 */
static Costume newCostume (const char *name, int hasImage, int drawLayer, const char *fpath)
{
  Costume *costume;

  if (!(costume = malloc(sizeof(Costume))))
    fprintf(stderr, "Error: Failed in newCostume when trying to malloc %d Bytes for the Costume\n", (int)sizeof(Costume));
  else if (!(costume->name = malloc(sizeof(const char)*(strlen(name) + 1))))
  {
    fprintf(stderr, "Error: Failed in newCostume when trying to malloc %d Bytes for name \"%s\"\n", (int)(sizeof(char)*(strlen(name) + 1)), name);
    free(costume);
  }else if (!(costume->fpath = malloc(sizeof(const char)*(strlen(fpath) + 1))))
  {
    free(costume->name);
    free(costume);
    fprintf(stderr, "Error: Failed in newCostume when trying to malloc %d Bytes for fpath \"%s\"\n", (int)(sizeof(char)*(strlen(fpath) + 1)), fpath);
  }else{
    costume->drawLayer = drawLayer;
    strcpy(costume->name, name);
    strcpy(costume->fpath, fpath);
    costume->ss = (void *)0;

    if (hasImage)
      costume->hasImage = 1;
    else
      costume->hasImage = 0;

    return costume;
  }

  return (Costume *)0;
}


/*
 * deletes all dynamically allocated data in a Costume (not the Costume pointer itself)
 */
static void deleteCostume (Costume *costume)
{
  if (costume->ss)
    free(costume->ss);
  free(costume->fpath);
  free(costume->name);
  free(costume);
}


/*
 * adds a Costume to a MobBodyPart
 */
static void addToBodyPartCostume (MobBodyPart *mobBodyPart, Costume *costume)
{
  if (mobBodyPart && costume)
  {
    Costume *tmpCostumes;
    if (!mobBodyPart->costumes)
    {
      if (!(mobBodyPart->costumes = malloc(sizeof(Costume))))
        fprintf(stderr, "Error: Failed in addToBodyPartCostume to malloc memory of size %d Bytes\n", sizeof(Costume));
      else
        mobBodyPart->costumes[mobBodyPart->nCostumes++] = costume;
    }else if (!(tmpCostumes = realloc(mobBodyPart->costumes, sizeof(Costume)*mobBodyPart->nCostumes + 1)))
      fprintf(stderr, "Error: Failed in addToBodyPartCostume to realloc memory of size %d Bytes\n", sizeof(Costume) * (mobBodyPart->nCostumes + 1));
    else{
      mobBodyPart->costumes = tmpCostumes;
      memcpy(mobBodyPart->costumes + nCostumes++, costume, sizeof(Costume));
      free(costume);
    }
  }
}


/*
 * creates a new dynamically allocated ExtraCostume with newly allocated C strings
 */
static ExtraCostume *newExtraCostume (Costume *costume, int isMale, int isFemale)
{
  ExtraCostume *extraCostume;
  if (!(extraCostume = malloc(sizeof(ExtraCostume))))
    fprintf(stderr, "Error: Failed in newExtraCostume trying to malloc %d Bytes for ExtraCostume\n", sizeof(ExtraCostume));
  else {
    extraCostume->isMale = isMale;
    extraCostume->isFemale = isFemale;
    extraCostume->nInvalidBodies = 0;
    extraCostume->invalidBodies = (const char **)0;
    return extraCostume;
  }

  return (ExtraCostume *)0;
}


/*
 * deletes all dynamically allocated data in a ExtraCostume (not the ExtraCostume pointer itself)
 */
static void deleteExtraCostume (ExtraCostume *extraCostume)
{
  if (extraCostume)
  {
    for (int i = 0; i < extraCostume->nInvalidBodies; i++)
      free(extraCostume->invalidBodies[i]);
    if (extraCostume->invalidBodies)
      free(extraCostume->invalidBodies);
    free(extraCostume);
  }
}


/*
 * adds an ExtraCostume to ExtraCostumePart
 */
static void addToExtraCostumePart (ExtraCostumePart *extraCostumePart, ExtraCostume *extraCostume)
{
  if (extraCostumePart && extraCostume)
  {
    ExtraCostume *tmpExtraCostumes;
    if (!extraCostumePart->extraCostumes)
    {
      if (!(extraCostumePart->extraCostumes = malloc(sizeof(ExtraCostume))))
        fprintf(stderr, "Error: Failed in addToExtraCostumePart to malloc memory of size %d Bytes for ExtraCostume\n", sizeof(ExtraCostume));
      else
        extraCostumePart->extraCostumes[extraCostumePart->nExtraCostumes++] = extraCostume;
    }else if (!(tmpExtraCostumes = realloc(extraCostumePart->extraCostumes, sizeof(ExtraCostume)*extraCostumePart->nExtraCostumes + 1)))
      fprintf(stderr, "Error: Failed in addToExtraCostumePart to realloc memory of size %d Bytes\n", sizeof(ExtraCostume) * (extraCostumePart->nExtraCostumes + 1));
    else{
      extraCostumePart->extraCostumes = tmpExtraCostumes;
      memcpy(extraCostumePart->extraCostumes + nExtraCostumes++, extraCostume, sizeof(ExtraCostume));
      free(extraCostume);
    }
  }
}


/*
 * creates a new dynamically allocated ExtraCostumePart with newly allocated name
 */
static ExtraCostumePart *newExtraCostumePart (const char *name)
{
  ExtraCostumePart *extraCostumePart;
  if (!(extraCostumePart = malloc(sizeof(ExtraCostumePart))))
    fprintf(stderr, "Error: Failed in newExtraCostumePart to malloc memory of size %d Bytes for ExtraCostume Part\n", sizeof(ExtraCostumePart));
  else if (!(extraCostumePart->name = malloc(sizeof(const char)*(strlen(name) + 1))))
  {
    fprintf(stderr, "Error: Failed in newExtraCostumePart to malloc memory of size %d Bytes for name\n", sizeof(const char)*(strlen(name) + 1));
    free(extraCostumePart);
  }else {
    strcpy(extraCostumePart->name, name);
    extraCostumePart->nExtraCostumes = 0;
    extraCostumePart->extraCostumes = (ExtraCostume *)0;
    return extraCostume;
  }

  return (ExtraCostume *)0;
}


/*
 * creates a new dynamically allocated ExtraCostumes
 */
static ExtraCostumes *newExtraCostumes (void)
{
  ExtraCostumes *extraCostumes;
  ExtraCostumePart *prt;
  if (!(extraCostumes = malloc(sizeof(ExtraCostumes))))
  {
    fprintf(stderr, "Error: Failed in newExtraCostumes to malloc memory of size %d Bytes for ExtraCostumes\n", sizeof(ExtraCostumes));
    return (ExtraCostumes *)0;
  }else {
    extraCostumes->nExtraCostumeParts = 0;
    extraCostumes->extraCostumeParts = (ExtraCostumePart *)0;
    
    //TODO instead of using separate part make new part in extraParts
    if (!(prt = newExtraPart("cape clip")))
      fprintf(stderr, "Error: Failed in newExtraCostumes to make a newExtraPart\n");
    else{
      addToExtraCostumePart(prt, newExtraCostume(newCostume("black", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_black.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("blue", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_blue.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("brown", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_brown.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("gray", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_gray.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("green", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_green.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("lavendar", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_lavendar.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("maroon", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_maroon.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("pink", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_pink.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("red", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_red.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("white", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_white.webp"), 0, 1)); 
      addToExtraCostumePart(prt, newExtraCostume(newCostume("yellow", 0, 1, "assets/accessories/neck/capeclip/female/capeclip_yellow.webp"), 0, 1));
    }
  }
}


/*
 * creates a new dynamically allocated MobBodyCostumes
 */
static MobBodyCostumes *newMobBodyCostumes (void);
