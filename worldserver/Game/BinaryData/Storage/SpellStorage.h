#ifndef BINARYDATA_SPELLSTORAGE_H
#define BINARYDATA_SPELLSTORAGE_H

#include "BinaryData/BinaryDataStorage.h"

template<class T>
class SpellStorage : public BinaryDataStorage<T>
{
public:
    SpellStorage() { }

    void Load()
    {
        qint32 size = this->m_rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = this->m_rows[i];
            this->_reader->SetBufferPosition(row.offset);

            SpellBinaryData entry;

            entry.m_id = this->_reader->ReadInt();
            entry.m_scriptId = this->_reader->ReadInt();
            entry.m_gfxId = this->_reader->ReadInt();
            entry.m_maxLevel = this->_reader->ReadShort();
            entry.m_breedId = this->_reader->ReadShort();
            entry.m_castMaxPerTarget = this->_reader->ReadShort();
            entry.m_castMaxPerTurn = this->_reader->ReadFloat();
            entry.m_castMaxPerTurnIncr = this->_reader->ReadFloat();
            entry.m_castMinInterval = this->_reader->ReadShort();
            entry.m_testLineOfSight = this->_reader->ReadBool();
            entry.m_castOnlyLine = this->_reader->ReadBool();
            entry.m_castOnlyInDiag = this->_reader->ReadBool();
            entry.m_testFreeCell = this->_reader->ReadBool();
            entry.m_testNotBorderCell = this->_reader->ReadBool();
            entry.m_testDirectPath = this->_reader->ReadBool();
            entry.m_targetFilter = this->_reader->ReadInt();
            entry.m_castCriterion = this->_reader->ReadString();
            entry.m_PA_base = this->_reader->ReadFloat();
            entry.m_PA_inc = this->_reader->ReadFloat();
            entry.m_PM_base = this->_reader->ReadFloat();
            entry.m_PM_inc = this->_reader->ReadFloat();
            entry.m_PW_base = this->_reader->ReadFloat();
            entry.m_PW_inc = this->_reader->ReadFloat();
            entry.m_rangeMaxBase = this->_reader->ReadFloat();
            entry.m_rangeMaxInc = this->_reader->ReadFloat();
            entry.m_rangeMinBase = this->_reader->ReadFloat();
            entry.m_rangeMinLevelIncrement = this->_reader->ReadFloat();
            entry.m_maxEffectCap = this->_reader->ReadShort();
            entry.m_element = this->_reader->ReadShort();
            entry.m_xpGainPercentage = this->_reader->ReadShort();
            entry.m_spellType = this->_reader->ReadShort();
            entry.m_uiPosition = this->_reader->ReadShort();
            entry.m_learnCriteria = this->_reader->ReadString();
            entry.m_passive = this->_reader->ReadByte();
            entry.m_useAutomaticDescription = this->_reader->ReadBool();
            entry.m_showInTimeline = this->_reader->ReadBool();
            entry.m_canCastWhenCarrying = this->_reader->ReadBool();
            entry.m_actionOnCriticalMiss = this->_reader->ReadByte();
            entry.m_spellCastRangeIsDynamic = this->_reader->ReadBool();
            entry.m_castSpellWillBreakInvisibility = this->_reader->ReadBool();
            entry.m_castOnRandomCell = this->_reader->ReadBool();
            entry.m_tunnelable = this->_reader->ReadBool();
            entry.m_canCastOnCasterCell = this->_reader->ReadBool();
            entry.m_associatedWithItemUse = this->_reader->ReadBool();
            entry.m_properties = this->_reader->ReadIntArray();
            entry.m_effectIds = this->_reader->ReadIntArray();

            qint32 baseCastParameterCount = this->_reader->ReadInt();

            for (qint32 i = 0; i < baseCastParameterCount; ++i)
            {
                TByteObjectHashMap<CustomCharac>(baseCastParameterCount); tByteObjectHashMap<CustomCharac>(baseCastParameterCount);;


                entry.m_baseCastParameters.push_back(tByteObjectHashMap<CustomCharac>(baseCastParameterCount););
            }


            qint32 baseCastParameterKey = this->_reader->ReadByte();

            for (qint32 i = 0; i < baseCastParameterKey; ++i)
            {
                CustomCharac(); customCharac();;


                entry.final CustomCharac baseCastParameterValue.push_back(customCharac(););
            }


            qint32 alternativeCastCount = this->_reader->ReadInt();

            for (qint32 i = 0; i < alternativeCastCount; ++i)
            {
                THashMap<String, CastParam>(alternativeCastCount); tHashMap<String, CastParam>(alternativeCastCount);;


                entry.m_alternativeCasts.push_back(tHashMap<String, CastParam>(alternativeCastCount););
            }


            qint32 alternativeCastKey = this->_reader->ReadString();

            for (qint32 i = 0; i < alternativeCastKey; ++i)
            {
                CastParam(); castParam();;


                entry.final CastParam alternativeCastValue.push_back(castParam(););
            }


            this->m_entries[entry.m_id] = entry;
        }

        qDebug() << ">> Loaded " << this->m_entries.size() << " entries for SpellStorage";
    }
};

#endif // BINARYDATA_SPELLSTORAGE_H
