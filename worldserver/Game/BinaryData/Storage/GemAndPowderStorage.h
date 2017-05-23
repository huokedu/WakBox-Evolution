#ifndef BINARYDATA_GEMANDPOWDERSTORAGE_H
#define BINARYDATA_GEMANDPOWDERSTORAGE_H

#include "BinaryData/BinaryDataStorage.h"

template<class T>
class GemAndPowderStorage : public BinaryDataStorage<T>
{
public:
    GemAndPowderStorage() { }

    void Load()
    {
        qint32 size = this->m_rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = this->m_rows[i];
            this->_reader->SetBufferPosition(row.offset);

            GemAndPowderBinaryData entry;

            entry.m_id = this->_reader->ReadInt();

            this->m_entries[entry.m_id] = entry;
        }

        qDebug() << ">> Loaded " << this->m_entries.size() << " entries for GemAndPowderStorage";
    }
};

#endif // BINARYDATA_GEMANDPOWDERSTORAGE_H
