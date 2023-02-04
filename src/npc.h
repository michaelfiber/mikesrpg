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

NpcColorSchemeHsv npcColorSchemes[] = {
	{// NPC_HUMAN
	 .skin = (Vector3){170.0f, 1.0, 1.0f},
	 .primary = (Vector3){250.0f, 1.0f, 1.0f},
	 .secondary = (Vector3){52.0f, 1.0f, 1.0f},
	 {// NPC_HORDE
	  .skin = (Vector3){324.0f, 1.0f, 1.0f},
	  .primary = (Vector3){24.0f, 1.0f, 1.0f},
	  .secondary = (Vector3){82.0f, 1.0f, 1.0f}},
	 {// NPC_GREAT_EVIL
	  .skin = (Vector3){105.0f, 1.0f, 1.0f},
	  .primary = (Vector3){0.0f, 1.0f, 1.0f},
	  .secondary = (Vector3){0.0f, 1.0f, 1.0f}}}};

typedef struct Npc
{
	Image *img;
} Npc;

Npc *GenerateNpc(int type);
Image GenerateNpcImage(NpcColorSchemeHsv scheme);

#endif