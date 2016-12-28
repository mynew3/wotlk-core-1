/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "naxxramas.h"
#include "SpellInfo.h"

enum Yells
{
    SAY_GREET       = 0,
    SAY_AGGRO       = 1,
    SAY_SLAY        = 2,
    SAY_DEATH       = 3
};

enum Spells
{
    SPELL_POISON_BOLT_VOLLEY_10         = 28796,
    SPELL_POISON_BOLT_VOLLEY_25         = 54098,
    SPELL_RAIN_OF_FIRE_10               = 28794,
    SPELL_RAIN_OF_FIRE_25               = 54099,
    SPELL_FRENZY_10                     = 28798,
    SPELL_FRENZY_25                     = 54100,
    SPELL_WIDOWS_EMBRACE                = 28732,
};

enum Events
{
    EVENT_SPELL_POISON_BOLT             = 1,
    EVENT_SPELL_RAIN_OF_FIRE            = 2,
    EVENT_SPELL_FRENZY                  = 3,
};

enum Misc
{
    NPC_NAXXRAMAS_WORSHIPPER            = 16506,
    NPC_NAXXRAMAS_FOLLOWER              = 16505,
};

class boss_faerlina : public CreatureScript
{
public:
    boss_faerlina() : CreatureScript("boss_faerlina") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_faerlinaAI (pCreature);
    }

    struct boss_faerlinaAI : public ScriptedAI
    {
        boss_faerlinaAI(Creature *c) : ScriptedAI(c), summons(me)
        {
            pInstance = me->GetInstanceScript();
            sayGreet = false;
        }

        InstanceScript* pInstance;
        EventMap events;
        SummonList summons;
        bool sayGreet;

        void SummonHelpers()
        {
            me->SummonCreature(NPC_NAXXRAMAS_WORSHIPPER, 3362.66f, -3620.97f, 261.08f, 4.57276f);
            me->SummonCreature(NPC_NAXXRAMAS_WORSHIPPER, 3344.3f, -3618.31f, 261.08f, 4.69494f);
            me->SummonCreature(NPC_NAXXRAMAS_WORSHIPPER, 3356.71f, -3620.05f, 261.08f, 4.57276f);
            me->SummonCreature(NPC_NAXXRAMAS_WORSHIPPER, 3350.26f, -3619.11f, 261.08f, 4.67748f);

            // Followers
            if (Is25ManRaid())
            {
                me->SummonCreature(NPC_NAXXRAMAS_FOLLOWER, 3347.49f, -3617.59f, 261.0f, 4.49f);
                me->SummonCreature(NPC_NAXXRAMAS_FOLLOWER, 3359.64f, -3619.16f, 261.0f, 4.56f);
            }
        }

        void JustSummoned(Creature* cr) { summons.Summon(cr); }

        void Reset()
        {
            events.Reset();
            summons.DespawnAll();
            SummonHelpers();
            if (pInstance)
                pInstance->SetData(EVENT_FAERLINA, NOT_STARTED);
        }

        void EnterCombat(Unit *who)
        {
            me->SetInCombatWithZone();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_SPELL_POISON_BOLT, urand(12000,15000));
            events.ScheduleEvent(EVENT_SPELL_RAIN_OF_FIRE, urand(6000,18000));
            events.ScheduleEvent(EVENT_SPELL_FRENZY, urand(60000,80000), 1);
            events.SetPhase(1);

            if (pInstance)
                pInstance->SetData(EVENT_FAERLINA, IN_PROGRESS);
        }

        void MoveInLineOfSight(Unit *who)
        {
            if (!sayGreet && who->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_GREET);
                sayGreet = true;
            }

            ScriptedAI::MoveInLineOfSight(who);
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!urand(0,3))
                Talk(SAY_SLAY);

            if (pInstance)
                pInstance->SetData(DATA_IMMORTAL_FAIL, 0);
        }

        void JustDied(Unit* Killer)
        {
            Talk(SAY_DEATH);
            if (pInstance)
                pInstance->SetData(EVENT_FAERLINA, DONE);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.GetEvent())
            {
                case EVENT_SPELL_POISON_BOLT:
                    if (!me->HasAura(SPELL_WIDOWS_EMBRACE))
                        me->CastCustomSpell(RAID_MODE(SPELL_POISON_BOLT_VOLLEY_10, SPELL_POISON_BOLT_VOLLEY_25), SPELLVALUE_MAX_TARGETS, 3, me, false);
                    events.RepeatEvent(14000);
                    break;
                case EVENT_SPELL_RAIN_OF_FIRE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(target, RAID_MODE(SPELL_RAIN_OF_FIRE_10, SPELL_RAIN_OF_FIRE_25), false);
                    events.RepeatEvent(12000);
                    break;
                case EVENT_SPELL_FRENZY:
                    me->MonsterTextEmote("%s goes into a frenzy!", 0, true);
                    me->CastSpell(me, RAID_MODE(SPELL_FRENZY_10, SPELL_FRENZY_25), true);
                    events.RepeatEvent(70000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
        
        void SpellHit(Unit* caster, const SpellInfo *spell)
        {
            if (spell->Id == SPELL_WIDOWS_EMBRACE)
            {
                me->MonsterTextEmote("%s is affected by Widow's Embrace!", 0, true);
                if (me->HasAura(RAID_MODE(SPELL_FRENZY_10, SPELL_FRENZY_25)))
                {
                    me->RemoveAurasDueToSpell(RAID_MODE(SPELL_FRENZY_10, SPELL_FRENZY_25));
                    events.DelayEvents(60000, 1);
                }
                else
                    events.DelayEvents(30000, 1);

                if (pInstance)
                    pInstance->SetData(DATA_FRENZY_REMOVED, 0);
            }
        }
    };
};

void AddSC_boss_faerlina()
{
    new boss_faerlina();
}
