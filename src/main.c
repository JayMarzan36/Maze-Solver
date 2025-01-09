#include <stdio.h>

#include "mapProcess.h"

int main()
{
    char testMapPath[] = "map_data/test_map.txt";

    struct mapStructure mapStruct;

    MAPSTRUCTURE *mapStructPtr = &mapStruct;

    loadMap(testMapPath, mapStructPtr);

    printf("Done loading map\n");

    printf("Map Row : %i\nMap Column : %i\nStart : (%d , %d)\nEnd : (%d , %d)\n", mapStruct.mapRow, mapStruct.mapColumn, mapStruct.start[0], mapStruct.start[1], mapStruct.end[0], mapStruct.end[1]);

    printMap(mapStructPtr);

    return 0;
}