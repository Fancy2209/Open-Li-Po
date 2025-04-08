#pragma once
#include "EFile.h"
#include "Directory.h"

// TODO: EFileLoc is a enum (i think?), just make it a int for now, implement actual EFileLoc at some point
#define EFileLoc int

class EFileManager
{
    public:
        EFileManager();
	    ~EFileManager();

        void AddFilePackage(const char *file){};
        void AddReadPath(const char *path, bool param1){};
        void SetWritePath(const char *path){};

};