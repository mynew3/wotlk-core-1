/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

/// \addtogroup Trinityd
/// @{
/// \file

#ifndef __WORLDRUNNABLE_H
#define __WORLDRUNNABLE_H

/// Heartbeat thread for the World
class WorldRunnable : public ACORE::Runnable
{
    public:
        void run();
};

class AuctionListingRunnable : public ACORE::Runnable
{
    public:
        void run();
};
#endif
/// @}
