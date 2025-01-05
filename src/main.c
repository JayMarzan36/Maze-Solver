#include <stdio.h>

#include "mapProcess.h"

int main()
{
    char testMapPath[] = "map_data/test_map.txt";

    struct mapStructure mapStruct;

    MAPSTRUCTURE *mapStructPtr = &mapStruct;

    loadMap(testMapPath, mapStructPtr);

    printf("Done loading map\n");

    printf("Map Row : %i\nMap Column : %i\n", mapStruct.mapRow, mapStruct.mapColumn);

    printMap(mapStructPtr);

    return 0;
}