/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef TRINITY_MOVEMENTGENERATOR_IMPL_H
#define TRINITY_MOVEMENTGENERATOR_IMPL_H

#include "MovementGenerator.h"

template<class MOVEMENT_GEN>
inline MovementGenerator*
MovementGeneratorFactory<MOVEMENT_GEN>::Create(void * /*data*/) const
{
    return (new MOVEMENT_GEN());
}
#endif
