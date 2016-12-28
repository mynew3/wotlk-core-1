/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#include "VMapFactory.h"
#include "VMapManager2.h"

namespace VMAP
{
    IVMapManager* gVMapManager = NULL;

    //===============================================
    // just return the instance
    IVMapManager* VMapFactory::createOrGetVMapManager()
    {
        if (gVMapManager == 0)
            gVMapManager= new VMapManager2();                // should be taken from config ... Please change if you like :-)
        return gVMapManager;
    }

    //===============================================
    // delete all internal data structures
    void VMapFactory::clear()
    {
        delete gVMapManager;
        gVMapManager = NULL;
    }
}
