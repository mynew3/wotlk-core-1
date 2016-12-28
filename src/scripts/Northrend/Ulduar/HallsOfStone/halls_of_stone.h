/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
*/

#ifndef DEF_HALLS_OF_STONE_H
#define DEF_HALLS_OF_STONE_H

#include "ScriptPCH.h"

enum Encounter
{
    BOSS_KRYSTALLUS             = 0,
    BOSS_MAIDEN_OF_GRIEF        = 1,
    BOSS_TRIBUNAL_OF_AGES       = 2,
    BOSS_SJONNIR                = 3,
    BRANN_BRONZEBEARD           = 4,
    MAX_ENCOUNTER               = 5,

    DATA_BRANN_ACHIEVEMENT,
    DATA_SJONNIR_ACHIEVEMENT,
};

enum gobjects
{
    GO_TRIBUNAL_CONSOLE         = 193907,
    GO_KADDRAK                  = 191671,
    GO_MARNAK                   = 191670,
    GO_ABEDNEUM                 = 191669,
    GO_SKY_FLOOR                = 191527,
    GO_SJONNIR_CONSOLE          = 193906,
    GO_SJONNIR_DOOR             = 191296,
    GO_TRIBUNAL_CHEST           = 190586,
    GO_TRIBUNAL_CHEST_H         = 193996,
    GO_LEFT_PIPE                = 192163,
    GO_RIGHT_PIPE               = 192164,
};

enum npcs
{
    NPC_KADDRAK                 = 30898,
    NPC_MARNAK                  = 30897,
    NPC_ABEDNEUM                = 30899,
    NPC_SJONNIR                 = 27978,
    NPC_BRANN                   = 28070,
};

#endif
