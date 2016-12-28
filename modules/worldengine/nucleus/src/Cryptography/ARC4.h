/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef _AUTH_SARC4_H
#define _AUTH_SARC4_H

#include "Define.h"
#include <openssl/evp.h>

class ARC4
{
    public:
        ARC4(uint8 len);
        ARC4(uint8 *seed, uint8 len);
        ~ARC4();
        void Init(uint8 *seed);
        void UpdateData(int len, uint8 *data);
    private:
        EVP_CIPHER_CTX m_ctx;
};

#endif
