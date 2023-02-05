#ifndef NPC_H
#define NPC_H

#include "raylib.h"

#define NPC_HUMAN 0
#define NPC_HORDE 1
#define NPC_GREAT_EVIL 2

typedef struct NpcColorSchemeHsv
{
	Vector3 skin;
	Vector3 primary;
	Vector3 secondary;
} NpcColorSchemeHsv;

typedef struct Npc
{
	Image *img;
} Npc;

Color ColorFromVector3(Vector3 hsv);
Npc *GenerateNpc(int type);
Image GenerateNpcImage(int npcType);

#endif