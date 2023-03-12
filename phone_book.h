#pragma once
#include "show\show.h"
#include "search\search.h"
#include "create\create.h"
#include "update\update.h"
#include "delete\delete.h"
#include "delete_all\delete_all.h"

void _getchar()
{
    getchar();
    fflush(stdin);
}

void _fscanf(FILE *_Stream, const char *_Format, ...)
{
    fscanf(_Stream, _Format);
    fflush(_Stream);
}

void _fgets(char *_Buffer, int _MaxCount, FILE *_Stream)
{
    fgets(_Buffer, _MaxCount, _Stream);
    _Buffer[strlen(_Buffer) - 1] = '\0';
    fflush(_Stream);
}