/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef TRINITY_HOMEMOVEMENTGENERATOR_H
#define TRINITY_HOMEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class Creature;

template < class T >
class HomeMovementGenerator;

template <>
class HomeMovementGenerator<Creature> : public MovementGeneratorMedium< Creature, HomeMovementGenerator<Creature> >
{
    public:

        HomeMovementGenerator() : arrived(false), i_recalculateTravel(false) {}
        ~HomeMovementGenerator() {}

        void DoInitialize(Creature*);
        void DoFinalize(Creature*);
        void DoReset(Creature*);
        bool DoUpdate(Creature*, const uint32);
        MovementGeneratorType GetMovementGeneratorType() { return HOME_MOTION_TYPE; }
        void unitSpeedChanged() { i_recalculateTravel = true; }

    private:
        void _setTargetLocation(Creature*);
        bool arrived : 1;
        bool i_recalculateTravel : 1;
};
#endif
