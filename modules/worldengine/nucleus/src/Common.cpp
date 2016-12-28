/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#include "Common.h"

char const* localeNames[TOTAL_LOCALES] = {
  "enUS",
  "koKR",
  "frFR",
  "deDE",
  "zhCN",
  "zhTW",
  "esES",
  "esMX",
  "ruRU"
};

LocaleConstant GetLocaleByName(const std::string& name)
{
    for (uint32 i = 0; i < TOTAL_LOCALES; ++i)
        if (name==localeNames[i])
            return LocaleConstant(i);

    return LOCALE_enUS;                                     // including enGB case
}

void CleanStringForMysqlQuery(std::string& str)
{
    std::string::size_type n = 0;
    while ((n=str.find('\\')) != str.npos) str.erase(n,1);
    while ((n=str.find('"')) != str.npos) str.erase(n,1);
    while ((n=str.find('\'')) != str.npos) str.erase(n,1);
}

