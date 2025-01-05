#ifndef MAPPROCESS
#define MAPPROCESS

typedef struct mapStructure MAPSTRUCTURE;

struct mapStructure
{
    int mapRow;

    int mapColumn;

    char **mapData;
};

void free1DArray(char *array, int size);

void freeMap(MAPSTRUCTURE *mapStruct);

void loadMap(char mapPath[], MAPSTRUCTURE *mapStruct);

void genMemoryForMap(MAPSTRUCTURE *mapStruct);

void printMap(MAPSTRUCTURE *mapStruct);

#endif // MAPPROCESS