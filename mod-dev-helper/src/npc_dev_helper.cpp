#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "Log.h"

class npc_dev_helper : public CreatureScript
{
public:
    npc_dev_helper() : CreatureScript("npc_dev_helper") { }

    bool OnGossipHello(Player* player, Creature* creature) override
    {
        ClearGossipMenuFor(player);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Wave", GOSSIP_SENDER_MAIN, 1);
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Buff me", GOSSIP_SENDER_MAIN, 2);
        SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32, uint32 action) override
    {
        ClearGossipMenuFor(player);
        CloseGossipMenuFor(player);

        if (action == 1)
        {
            creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
        }
        else if (action == 2)
        {
            creature->CastSpell(player, 10060, false);
            
        }

        return true;
    }
};

void Addmod_dev_helperScripts()
{
    new npc_dev_helper();
}
