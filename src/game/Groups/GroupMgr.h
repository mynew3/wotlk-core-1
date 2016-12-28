/*
 * Copyright (C) 2014-2017 SWPCore <http://www.wowswp.com/>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 */

#ifndef _GROUPMGR_H
#define _GROUPMGR_H

#include "Group.h"

class GroupMgr
{
    friend class ACE_Singleton<GroupMgr, ACE_Null_Mutex>;
private:
    GroupMgr();
    ~GroupMgr();

public:
    typedef std::map<uint32, Group*> GroupContainer;

    Group* GetGroupByGUID(uint32 guid) const;

    void InitGroupIds();
    void RegisterGroupId(uint32 groupId);
    uint32 GenerateGroupId();

    void LoadGroups();
    void AddGroup(Group* group);
    void RemoveGroup(Group* group);


protected:
    typedef std::vector<bool> GroupIds;
    GroupIds         _groupIds;
    uint32           _nextGroupId;
    GroupContainer   GroupStore;
};

#define sGroupMgr ACE_Singleton<GroupMgr, ACE_Null_Mutex>::instance()

#endif
