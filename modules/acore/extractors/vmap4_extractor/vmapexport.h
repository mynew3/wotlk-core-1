/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef VMAPEXPORT_H
#define VMAPEXPORT_H

#include <string>

enum ModelFlags
{
    MOD_M2 = 1,
    MOD_WORLDSPAWN = 1<<1,
    MOD_HAS_BOUND = 1<<2
};

extern const char * szWorkDirWmo;
extern const char * szRawVMAPMagic;                         // vmap magic string for extracted raw vmap data

bool FileExists(const char * file);
void strToLower(char* str);

bool ExtractSingleWmo(std::string& fname);
bool ExtractSingleModel(std::string& fname);

void ExtractGameobjectModels();

#endif
