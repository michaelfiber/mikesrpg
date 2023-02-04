#include "npc.h"
#include "global.h"
#include "drawimage.h"

int nextNpcId = 0;

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

Image GenerateNpcImage(NpcColorSchemeHsv scheme)
{
	Color *data = (Color *)MemAlloc(sizeof(Color) * NpcWidth * NpcHeight);
	Image img = {
		.data = data,
		.width = NpcWidth,
		.height = NpcHeight,
		.mipmaps = 1,
		.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8};

	ClearImage(&img, ColorAlpha(WHITE, 0.0f));

	DrawImageRec(&img, NpcWidth / 2 - NpcWidth / 4, 0, NpcWidth / 2, NpcWidth / 2, ColorFromHSV(scheme.skin.x, scheme.skin.y, scheme.skin.z));

	TraceLog(LOG_WARNING, "TODO: Actually draw an NPC");
	
	return img;
}