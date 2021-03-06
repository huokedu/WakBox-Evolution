#include "Unit.h"
#include "Utils/Util.h"
#include "Maps/MapMgr.h"

Unit::Unit() : Object()
{
    m_typeId = TYPEID_UNIT;

    m_name = "";
    m_breed = 0;
    m_level = 1;

    m_positionX = 0;
    m_positionY = 0;
    m_positionZ = 0;
    m_direction = 0;
    m_instanceId = 0;

    m_map = nullptr;
}

Unit::~Unit()
{

}

qint32 Unit::GetLastPartitionId()
{
    return Utils::getIntFromTwoInt(
                MapMgr::getMapCoordFromCell(GetPositionX()),
                MapMgr::getMapCoordFromCell(GetPositionY()));
}
