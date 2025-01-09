#include "mapProcess.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void loadMap(char mapPath[], MAPSTRUCTURE *mapStruct)
{

    printf("Loading map\n");

    FILE *filePtr;

    filePtr = fopen(mapPath, "r");

    if (filePtr == NULL)
    {
        printf("Error opening file\n");

        fclose(filePtr);

        free(filePtr);

        filePtr = NULL;

        exit(EXIT_FAILURE);
    }
    else
    {

        printf("Reading map meta-data\n");

        mapStruct->mapData = NULL;

        if (fscanf(filePtr, "%d %d\n", &mapStruct->mapRow, &mapStruct->mapColumn) != 2)
        {

            printf("Error reading map meta data\n");

            fclose(filePtr);

            exit(EXIT_FAILURE);
        }

        genMemoryForMap(mapStruct);

        int tempRow = 0, tempCol = 0;

        char tempChar;

        printf("Reading map data\n");

        while ((tempChar = fgetc(filePtr)) != '$')
        {
            if (tempRow >= mapStruct->mapRow + 1 || tempCol >= mapStruct->mapColumn + 1)
            {
                printf("Out of bounds: tempRow = %d, tempCol = %d\n", tempRow, tempCol);
                exit(EXIT_FAILURE);
            }

            if (tempChar == '\n')
            {

                tempRow++;

                tempCol = 0;
            }
            else
            {

                if (tempChar == 's')
                {
                    (mapStruct->start) = malloc(2 * sizeof(int));
                    (mapStruct->start)[0] = tempRow;
                    (mapStruct->start)[1] = tempCol;
                }
                else if (tempChar == 'g')
                {
                    (mapStruct->end) = malloc(2 * sizeof(int));
                    (mapStruct->end)[0] = tempRow;
                    (mapStruct->end)[1] = tempCol;
                }

                if (tempChar == '#')
                {
                    (mapStruct->mapData)[tempRow][tempCol++] = 1;
                }
                else
                {
                    (mapStruct->mapData)[tempRow][tempCol++] = 0;
                }
            }
        }

        fclose(filePtr);

        printf("Loaded map data\n");
    }
}

void genMemoryForMap(MAPSTRUCTURE *mapStruct)
{

    if (mapStruct->mapData == NULL)
    {
        freeMap(mapStruct);

        printf("Allocating memory space for mapData\n");

        mapStruct->mapData = malloc(mapStruct->mapRow * sizeof(char *));

        if (mapStruct->mapData == NULL)
        {
            printf("Error allocating memory for mapData rows\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < mapStruct->mapRow; i++)
        {
            mapStruct->mapData[i] = malloc(mapStruct->mapColumn * sizeof(char));

            if (mapStruct->mapData[i] == NULL)
            {
                printf("Error allocating memory for mapData columns\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    else
    {
        printf("mapData is already allocated\n");
    }
}

void free1DArray(char *array, int size)
{
    free(array);
    array = NULL;
    printf("Successfully Freed 1D-Array\n");
}

void freeMap(MAPSTRUCTURE *mapStruct)
{
    if (mapStruct->mapData != NULL)
    {
        for (int i = 0; i < mapStruct->mapRow; i++)
        {
            free(mapStruct->mapData[i]);
        }

        free(mapStruct->mapData);
        mapStruct->mapData = NULL;

        printf("Successfully Freed mapData\n");
    }
}

void printMap(MAPSTRUCTURE *mapStruct)
{
    for (int i = 0; i < mapStruct->mapRow; i++)
    {
        for (int j = 0; j < mapStruct->mapColumn; j++)
        {
            printf("%d",mapStruct->mapData[i][j]);
        }
        printf("\n");
    }
}