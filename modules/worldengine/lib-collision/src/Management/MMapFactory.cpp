/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#include "MMapFactory.h"
#include "World.h"
#include <set>

namespace MMAP
{
    // ######################## MMapFactory ########################
    // our global singleton copy
    MMapManager *g_MMapManager = NULL;
    bool MMapFactory::forbiddenMaps[1000] = {0};

    MMapManager* MMapFactory::createOrGetMMapManager()
    {
        if (g_MMapManager == NULL)
            g_MMapManager = new MMapManager();

        return g_MMapManager;
    }

    bool MMapFactory::IsPathfindingEnabled(const Map* map, bool force)
    {
        if (!map) return false;
        return !forbiddenMaps[map->GetId()] && (sWorld->getBoolConfig(CONFIG_ENABLE_MMAPS) ? true : map->IsBattlegroundOrArena());
    }

    void MMapFactory::InitializeDisabledMaps()
    {
        memset(&forbiddenMaps, 0, sizeof(forbiddenMaps));
        int32 f[] = {616 /*EoE*/, 649 /*ToC25*/, 650 /*ToC5*/, -1};
        uint32 i = 0;
        while (f[i] >= 0)
            forbiddenMaps[f[i++]] = true;
    }

    void MMapFactory::clear()
    {
        if (g_MMapManager)
        {
            delete g_MMapManager;
            g_MMapManager = NULL;
        }
    }
}