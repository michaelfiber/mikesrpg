#include "npc.h"
#include "global.h"
#include "drawimage.h"

int nextNpcId = 0;

NpcColorSchemeHsv npcColorSchemes[] = {
	{// NPC_HUMAN
	 .skin = (Vector3){170.0f, 1.0, 1.0f},
	 .primary = (Vector3){250.0f, 1.0f, 1.0f},
	 .secondary = (Vector3){52.0f, 1.0f, 1.0f}},
	{// NPC_HORDE
	 .skin = (Vector3){324.0f, 1.0f, 1.0f},
	 .primary = (Vector3){24.0f, 1.0f, 1.0f},
	 .secondary = (Vector3){82.0f, 1.0f, 1.0f}},
	{// NPC_GREAT_EVIL
	 .skin = (Vector3){105.0f, 1.0f, 1.0f},
	 .primary = (Vector3){0.0f, 0.0f, 0.1f},
	 .secondary = (Vector3){0.0f, 1.0f, 0.5f}}};

Npc *GenerateNpc(int type)
{
	Npc *npc = (Npc *)MemAlloc(sizeof(Npc));

	switch (type)
	{
	case NPC_HUMAN:
		break;
	case NPC_HORDE:
		break;
	case NPC_GREAT_EVIL:
		break;
	}

	return npc;
}

Image GenerateNpcImage(int npcType)
{
	if (npcType > NPC_GREAT_EVIL)
	{
		return (Image){};
	}

	NpcColorSchemeHsv scheme = npcColorSchemes[npcType];
	Color *data = (Color *)MemAlloc(sizeof(Color) * NpcWidth * NpcHeight);
	Image img = {
		.data = data,
		.width = NpcWidth,
		.height = NpcHeight,
		.mipmaps = 1,
		.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};

	ClearImage(&img, ColorAlpha(WHITE, 0.0f));

	DrawImageRec(&img, NpcWidth / 2 - NpcWidth / 4, 0, NpcWidth / 2, NpcWidth / 2, ColorFromVector3(scheme.skin));
	DrawImageRec(&img, 0, NpcWidth / 2, NpcWidth, NpcHeight / 2, ColorFromVector3(scheme.primary));
	DrawImageRec(&img, NpcWidth / 5, NpcWidth / 2 + NpcHeight / 2, 3 * NpcWidth / 5, NpcHeight - NpcWidth / 2 - NpcHeight / 2, ColorFromVector3(scheme.secondary));

	TraceLog(LOG_WARNING, "TODO: Add randomness to NPC colors.");

	return img;
}

Color ColorFromVector3(Vector3 hsv)
{
	return ColorFromHSV(hsv.x, hsv.y, hsv.z);
}