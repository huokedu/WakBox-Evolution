#ifndef BINARYDATA_GROUNDSTORAGE_H
#define BINARYDATA_GROUNDSTORAGE_H

#include "BinaryData/BinaryDataStorage.h"

template<class T>
class GroundStorage : public BinaryDataStorage<T>
{
public:
    GroundStorage() { }

    void Load()
    {
        qint32 size = this->m_rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = this->m_rows[i];
            this->_reader->SetBufferPosition(row.offset);

            GroundBinaryData entry;

            entry.m_id = this->_reader->ReadInt();

            qint32 resourceFertilityCount = this->_reader->ReadInt();

            for (qint32 i = 0; i < resourceFertilityCount; ++i)
            {
                qint32 resourceFertilityKey = this->_reader->ReadInt();
                qint16 resourceFertilityValue = this->_reader->ReadShort();

                entry.m_resourceFertility.insert(resourceFertilityKey, resourceFertilityValue);
            }

            qint32 resourceTypeFertilityCount = this->_reader->ReadInt();

            for (qint32 i = 0; i < resourceTypeFertilityCount; ++i)
            {
                qint16 resourceTypeFertilityKey = this->_reader->ReadShort();
                qint16 resourceTypeFertilityValue = this->_reader->ReadShort();

                entry.m_resourceTypeFertility.insert(resourceTypeFertilityKey, resourceTypeFertilityValue);
            }

            this->m_entries[entry.m_id] = entry;
        }

        qDebug() << ">> Loaded " << this->m_entries.size() << " entries for GroundStorage";
    }
};

#endif // BINARYDATA_GROUNDSTORAGE_H
