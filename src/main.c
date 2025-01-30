#include <stdio.h>

#include "mapProcess.h"

#include "ASTAR.h"

int main()
{
    char mapPath[] = "map_data/map.txt";

    struct mapStructure mapStruct;

    MAPSTRUCTURE *mapStructPtr = &mapStruct;

    loadMap(mapPath, mapStructPtr);

    printf("Done loading map\n");

    aStar(mapStruct.mapData, mapStruct.start, mapStruct.end, mapStruct.mapRow, mapStruct.mapColumn);

    freeMap(mapStructPtr);

    return 0;
}