/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef SWPCORE_TOTEM_H
#define SWPCORE_TOTEM_H

#include "TemporarySummon.h"

enum TotemType
{
    TOTEM_PASSIVE    = 0,
    TOTEM_ACTIVE     = 1,
    TOTEM_STATUE     = 2 // copied straight from moongose, may need more implementation to work
};
// Some Totems cast spells that are not in creature DB
#define SENTRY_TOTEM_SPELLID  6495

#define SENTRY_TOTEM_ENTRY    3968
#define EARTHBIND_TOTEM_ENTRY 2630

class Totem : public Minion
{
    public:
        explicit Totem(SummonPropertiesEntry const *properties, uint64 owner);
        virtual ~Totem(){};
        void Update(uint32 time);
        void InitStats(uint32 duration);
        void InitSummon();
        void UnSummon(uint32 msTime = 0);
        uint32 GetSpell(uint8 slot = 0) const { return m_spells[slot]; }
        uint32 GetTotemDuration() const { return m_duration; }
        void SetTotemDuration(uint32 duration) { m_duration = duration; }
        TotemType GetTotemType() const { return m_type; }

        bool UpdateStats(Stats /*stat*/) { return true; }
        bool UpdateAllStats() { return true; }
        void UpdateResistances(uint32 /*school*/) {}
        void UpdateArmor() {}
        void UpdateMaxHealth() {}
        void UpdateMaxPower(Powers /*power*/) {}
        void UpdateAttackPowerAndDamage(bool /*ranged*/) {}
        void UpdateDamagePhysical(WeaponAttackType /*attType*/) {}

        bool IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index) const;

    protected:
        TotemType m_type;
        uint32 m_duration;
};
#endif
