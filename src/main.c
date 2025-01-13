#include <stdio.h>

#include "mapProcess.h"

#include "ASTAR.h"

int main()
{
    char testMapPath[] = "map_data/map3.txt";

    struct mapStructure mapStruct;

    MAPSTRUCTURE *mapStructPtr = &mapStruct;

    loadMap(testMapPath, mapStructPtr);

    printf("Done loading map\n");

    // printMap(mapStructPtr);

    aStar(mapStruct.mapData, mapStruct.start, mapStruct.end, mapStruct.mapRow, mapStruct.mapColumn);

    printf("Done A* algorithm\n");

    freeMap(mapStructPtr);

    return 0;
}