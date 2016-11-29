#include <time.h>
#include <stdlib.h>

#include "draw.h"
#include "sprite2.h"


int spriteBodies [N_SPRITE_GENDERS][N_SPRITE_BODIES] = {
  {//male
    loadTexture("assets/body/male/light.webp"),
    loadTexture("assets/body/male/orc.webp")
  },{//female
    loadTexture("assets/body/female/light.webp"),
    loadTexture("assets/body/female/orc.webp")
  }
}

int spriteHair [N_SPRITE_GENDERS][N_SPRITE_HAIR_TYPE][N_SPRITE_HAIR_COLOR] = {
  {//male
    {//bangs
      loadTexture("assets/hair/male/bangs/black.webp"),
      loadTexture("assets/hair/male/bangs/blonde.webp"),
      loadTexture("assets/hair/male/bangs/blue.webp")
    },{//long
      loadTexture("assets/hair/male/long/black.webp"),
      loadTexture("assets/hair/male/long/blonde.webp"),
      loadTexture("assets/hair/male/long/blue.webp")
    }
  },{//female
    {//bangs
      loadTexture("assets/hair/female/bangs/black.webp"),
      loadTexture("assets/hair/female/bangs/blonde.webp"),
      loadTexture("assets/hair/female/bangs/blue.webp")
    },{//long
      loadTexture("assets/hair/female/long/black.webp"),
      loadTexture("assets/hair/female/long/blonde.webp"),
      loadTexture("assets/hair/female/long/blue.webp")
    }
  }
}

int spriteTorso [N_SPRITE_GENDERS][N_SPRITE_TORSO] = {
  {//male
    loadTexture("assets/torso/shirts/longsleeve/male/brown_longsleeve.webp"),
    loadTexture("assets/torso/shirts/longsleeve/male/maroon_longsleeve.webp"),
    loadTexture("assets/torso/leather/chest_male.webp"),
    loadTexture("assets/torso/chain/mail_male.webp"),
    loadTexture("assets/torso/chain/tabard/jacket_male.webp")
  },{//female
    loadTexture("assets/torso/shirts/sleeveless/female/brown_sleeveless.webp"),
    loadTexture("assets/torso/shirts/sleeveless/female/maroon_sleeveless.webp"),
    loadTexture("assets/torso/leather/chest_female.webp"),
    loadTexture("assets/torso/chain/mail_female.webp"),
    loadTexture("assets/torso/chain/tabard/jacket_female.webp")
  }
}

int spriteLegs [N_SPRITE_GENDERS][N_SPRITE_LEGS] = {
  {//male
    loadTexture("assets/legs/pants/male/red_pants_male.webp"),
    loadTexture("assets/legs/pants/male/teal_pants_male.webp"),
    loadTexture("assets/legs/pants/male/white_pants_male.webp"),
    loadTexture("assets/legs/armor/male/metal_pants_male.webp")
  },{//female
    loadTexture("assets/legs/pants/female/red_pants_female.webp"),
    loadTexture("assets/legs/pants/female/teal_pants_female.webp"),
    loadTexture("assets/legs/pants/female/white_pants_female.webp"),
    loadTexture("assets/legs/armor/female/metal_pants_female.webp")
  }
}

int spriteFeet [N_SPRITE_GENDERS][N_SPRITE_FEET] = {
  {//male
    loadTexture("assets/feet/shoes/male/black_shoes_male.webp"),
    loadTexture("assets/feet/shoes/male/brown_shoes_male.webp"),
    loadTexture("assets/feet/shoes/male/maroon_shoes_male.webp"),
    loadTexture("assets/feet/armor/male/metal_boots_male.webp")
  },{//female
    loadTexture("assets/feet/shoes/female/black_shoes_female.webp"),
    loadTexture("assets/feet/shoes/female/brown_shoes_female.webp"),
    loadTexture("assets/feet/shoes/female/maroon_shoes_female.webp"),
    loadTexture("assets/feet/armor/female/metal_boots_female.webp")
  }
}


Sprite genRandom (void)
{
  Sprite sprite;
  int gender, body, hairType, hairColor, torso, legs, feet;
  
  srand(time((void *)0));

  sprite.x = 0.0f;
  sprite.y = 0.0f;
  sprite.aniStart = 0.0f;
  sprite.aniSpeed = 1.0f;
  sprite.aniPhase = 0;

  gender = rand() % N_SPRITE_GENDERS;
  body = rand() % N_SPRITE_BODIES;
  hairType = rand() % N_SPRITE_HAIR_TYPE;
  hairColor = rand() % (N_SPRITE_HAIR_COLOR + 1);
  torso = rand() % (N_SPRITE_TORSO + 1);
  legs = rand() % (N_SPRITE_LEGS + 1);
  feet = rand() % (N_SPRITE_FEET + 1);
  
  sprite.spriteLayers[SPRITE_BODY_LAYER] = spriteBodies[gender][body];
  
  if (hairColor == N_SPRITE_HAIR_COLOR)
    sprite.spriteLayers[SPRITE_HAIR_LAYER] = -1;
  else
    sprite.spriteLayers[SPRITE_HAIR_LAYER] = spriteHair[gender][hairType][hairColor];

  if (torso == N_SPRITE_TORSO)
    sprite.spriteLayers[SPRITE_TORSO_LAYER] = -1;
  else
    sprite.spriteLayers[SPRITE_TORSO_LAYER] = spriteTorso[gender][torso];

  if (legs == N_SPRITE_LEGS)
    sprite.spriteLayers[SPRITE_LEGS_LAYER] = -1;
  else
    sprite.spriteLayers[SPRITE_LEGS_LAYER] = spriteLegs[gender][legs];

  if (feet == N_SPRITE_FEET)
    sprite.spriteLayers[SPRITE_FEET_LAYER] = -1;
  else
    sprite.spriteLayers[SPRITE_FEET_LAYER] = spriteFeet[gender][feet];

  return sprite;
}


void drawSprite (Sprite *sprite, float aniTime)
{
  int yCell = aniPhase;
  int xCell = (int)((aniTime - sprite->aniStart)*sprite->aniSpeed/ANIMATION_SPEED) % spritePhaseStages[aniPhase];
  float tx1 = xCell*SPRITE_WIDTH/(float)ANIMATION_WIDTH;
  float ty1 = (yCell+1)*SPRITE_HEIGHT/(float)ANIMATION_HEIGHT;
  float tx2 = (xCell+1)*SPRITE_WIDTH/(float)ANIMATION_WIDTH;
  float ty2 = yCell*SPRITE_HEIGHT/(float)ANIMATION_HEIGHT;

  float px1 = sprite->x - ANIMATION_X_OFFSET;
  float py1 = sprite->y + SPRITE_SIZE_H - ANIMATION_Y_OFFSET;
  float px2 = sprite->x + SPRITE_SIZE_W - ANIMATION_X_OFFSET;
  float py2 = sprite->y - ANIMATION_Y_OFFSET;
  vec2 p1 = {px1, py1};
  vec2 p2 = {px2, py2};
  vec2 t1 = {tx1, ty1};
  vec2 t2 = {tx2, ty2};

  for (int i = 0; i < N_SPRITE_LAYERS; i++)
    if (sprite->spriteLayers[i] != -1)
      draw_tex(sprite->spriteLayers[i], p1, p2, t1, t2);
}
