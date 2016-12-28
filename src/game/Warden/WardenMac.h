/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef _WARDEN_MAC_H
#define _WARDEN_MAC_H

#include "Cryptography/ARC4.h"
#include <map>
#include "Cryptography/BigNumber.h"
#include "ByteBuffer.h"
#include "Warden.h"

class WorldSession;
class Warden;

class WardenMac : public Warden
{
    public:
        WardenMac();
        ~WardenMac();

        void Init(WorldSession* session, BigNumber* k);
        ClientWardenModule* GetModuleForClient();
        void InitializeModule();
        void RequestHash();
        void HandleHashResult(ByteBuffer& buff);
        void RequestData();
        void HandleData(ByteBuffer& buff);
};

#endif
