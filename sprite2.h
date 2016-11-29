#ifndef SPRITE2_H
#define SPRITE2_H


#define ANIMATION_SPEED 1.0f

#define ANIMATION_PHASE_SPELL_CAST 0
#define ANIMATION_PHASE_THRUST 1
#define ANIMATION_PHASE_WALK 2
#define ANIMATION_PHASE_SLASH 3
#define ANIMATION_PHASE_SHOOT 4
#define ANIMATION_PHASE_HURT 5

#define ANIMATION_DIRECTION_N 0
#define ANIMATION_DIRECTION_W 1
#define ANIMATION_DIRECTION_S 2
#define ANIMATION_DIRECTION_E 3

#define SPRITE_HEIGHT 64
#define SPRITE_WIDTH 64
#define SPRITE_SIZE_W 0.4f
#define SPRITE_SIZE_H 0.4f
#define ANIMATION_HEIGHT 1344
#define ANIMATION_WIDTH 832
#define ANIMATION_X_OFFSET 0.2f
#define ANIMATION_Y_OFFSET 0.4f

#define N_SPRITE_LAYERS 5
#define SPRITE_BODY_LAYER 0
#define SPRITE_HAIR_LAYER 1
#define SPRITE_TORSO_LAYER 4
#define SPRITE_LEGS_LAYER 3
#define SPRITE_FEET_LAYER 3

#define N_SPRITE_GENDERS 2
#define N_SPRITE_BODIES 2
#define N_SPRITE_HAIR_TYPE 2
#define N_SPRITE_HAIR_COLOR 3
#define N_SPRITE_TORSO 5
#define N_SPRITE_LEGS 4
#define N_SPRITE_FEET 4


typedef struct
{
  float x, y, aniStart, aniSpeed;
  int aniPhase, gender;
  int spriteLayers [N_SPRITE_LAYERS];
} Sprite;


const int spritePhaseStages [21] {
  7, 7, 7, 7,
  8, 8, 8, 8,
  9, 9, 9, 9,
  6, 6, 6, 6,
  13, 13, 13, 13,
  6
}

void drawSprite (Sprite *sprite, float aniTime);
Sprite genRandom (void);

extern int spriteBodies [N_SPRITE_GENDERS][N_SPRITE_BODIES];
extern int spriteHair [N_SPRITE_GENDERS][N_SPRITE_HAIR_TYPE][N_SPRITE_HAIR_COLOR];
extern int spriteTorso [N_SPRITE_GENDERS][N_SPRITE_TORSO];
extern int spriteLegs [N_SPRITE_GENDERS][N_SPRITE_LEGS];
extern int spriteFeet [N_SPRITE_GENDERS][N_SPRITE_FEET];

#endif
