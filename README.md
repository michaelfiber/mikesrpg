# Mike's RPG

## Goal
Use random generation in place of actual creativity wherever possible.

### WORLD Generation
WORLD refers to a world map. Simplex noise is used to generate a heightmap. The results are stratified into a biome types (from least to greatest height):

Biome Types (from least to greatest height):
- Water
- Sand
- Grass
- Rocky
- Snow
- Peak

Then the map is looped over from top left to bottom right and WORLD features are generated randomly based on set probabilities for each type of feature to appear in each type of biome.

WORLD features:
- Water - None planned yet
- Sand 
	- Shipwreck (very rare)
- Grass
	- Village
	- Ruin (rare)
	- Cave (very rare)
	- Horde Village (extremely rare)
- Rocky
	- Cave (rare)
	- Horde village (very rare)
- Snow
	- Ice Cave (very rare)
	- Evil Castle (extremely rare)
- Peak
	- Evil Castle (extremely rare) - 1 guaranteed?

WORLD features are generated at the beginning and stored in a linked list so that some persistent state can be associated with each feature. 

Each pixel of the WORLD map can be viewed as a LOCAL map. When the player moves around the LOCAL map they can find any WORLD features that were placed there. 

### LOCAL Generation
Grid based local map. Use the biome set by the WORLD map to determine types of ground tiles that can be generated. Seed rng with WORLD map coordinates of the LOCAL map. Work through all cells of the LOCAL map from top left to bottom right randomly setting tile values. 

If there is a WORLD Feature assigned to this LOCAL map it must be randomly placed based on seeded rng. NPCs are randomly generated to go with the WORLD feature where applicable as well.  Details of the WORLD feature and associated NPCs can be stored in the WORLD feature linked list, collected treasure, killed NPCs, etc should be maintained across LOCAL map reloads. The ground terrain won't be changeable so it will generate on the fly each time the local map loads. 

### NPC Generation
There are human NPCs, horde NPCs and great evil NPCs. Each NPC is drawn as a single image sprite made up of colored rectangles. They are generated using the ID of their associated WORLD feature as rng seed and then colors are generated along color patterns preset based on NPC type.  
- Human NPCs
	- turqoise hue skin
	- multi colored clothes (variations on local primary and secondary color preferences)
	- generated around Villages
- Horde NPCs 
	- pink hue skin
	- drab colored clothes
	- generated raound horde villages and caves
- Great evil NPCs 
	- green hue skin
	- black and red colored clothes
	- generated around ice caves and evil castles