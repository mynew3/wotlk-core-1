/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef _FOLLOWERREFMANAGER
#define _FOLLOWERREFMANAGER

#include "RefManager.h"

class Unit;
class TargetedMovementGeneratorBase;

class FollowerRefManager : public RefManager<Unit, TargetedMovementGeneratorBase>
{

};
#endif
