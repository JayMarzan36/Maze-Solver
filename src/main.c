#include <stdio.h>

#include "mapProcess.h"

#include "ASTAR.h"

int main()
{
    char testMapPath[] = "map_data/test_map.txt";

    struct mapStructure mapStruct;

    MAPSTRUCTURE *mapStructPtr = &mapStruct;

    loadMap(testMapPath, mapStructPtr);

    printf("Done loading map\n");

    printf("Start : (%d , %d)\nEnd : (%d , %d)\n", mapStruct.start[0], mapStruct.start[1], mapStruct.end[0], mapStruct.end[1]);

    printMap(mapStructPtr);

    aStar(mapStruct.mapData, mapStruct.start, mapStruct.end, mapStruct.mapRow, mapStruct.mapColumn);

    printf("Done A* algorithm\n");

    freeMap(mapStructPtr);

    return 0;
}