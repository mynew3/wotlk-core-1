/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#include "Group.h"
#include "GroupReference.h"

void GroupReference::targetObjectBuildLink()
{
    // called from link()
    getTarget()->LinkMember(this);
}

void GroupReference::targetObjectDestroyLink()
{
    // called from unlink()
}

void GroupReference::sourceObjectDestroyLink()
{
    // called from invalidate()
}

