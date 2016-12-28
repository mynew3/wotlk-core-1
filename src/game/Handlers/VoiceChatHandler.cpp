/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#include "Common.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"

void WorldSession::HandleVoiceSessionEnableOpcode(WorldPacket& recvData)
{
    ;//sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_VOICE_SESSION_ENABLE");
    // uint8 isVoiceEnabled, uint8 isMicrophoneEnabled
    recvData.read_skip<uint8>();
    recvData.read_skip<uint8>();
}

void WorldSession::HandleChannelVoiceOnOpcode(WorldPacket& /*recvData*/)
{
    ;//sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_CHANNEL_VOICE_ON");
    // Enable Voice button in channel context menu
}

void WorldSession::HandleSetActiveVoiceChannel(WorldPacket& recvData)
{
    ;//sLog->outDebug(LOG_FILTER_NETWORKIO, "WORLD: CMSG_SET_ACTIVE_VOICE_CHANNEL");
    recvData.read_skip<uint32>();
    recvData.read_skip<char*>();
}

