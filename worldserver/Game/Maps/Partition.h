#ifndef PARTITION_H
#define PARTITION_H

#include <QtCore>

#include "Server/WorldSession.h"

typedef QList<Unit*> MapUnitList;

class Map;

class Partition
{
public:
    Partition(Map* map, qint32 partitionId);
    ~Partition();

    Map* GetMap() { return m_map; }
    qint32 GetId() { return m_id; }

    MapUnitList const& GetUnitList() { return m_unitList; }

    void Load();
    void AddCharacterToPartition(Character* character);
    void SendPacket(WorldPacket& data, WorldSession* self = nullptr);

private:
    Map* m_map;
    qint32 m_id;
    MapUnitList m_unitList;
};

#endif // PARTITION_H
