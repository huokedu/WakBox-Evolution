#ifndef BINARYDATA_REWARDDISPLAYERINTERACTIVEELEMENTPARAMSTORAGE_H
#define BINARYDATA_REWARDDISPLAYERINTERACTIVEELEMENTPARAMSTORAGE_H

#include "BinaryData/BinaryDataStorage.h"

template<class T>
class RewardDisplayerInteractiveElementParamStorage : public BinaryDataStorage<T>
{
public:
    RewardDisplayerInteractiveElementParamStorage() { }

    void Load()
    {
        qint32 size = this->m_rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = this->m_rows[i];
            this->_reader->SetBufferPosition(row.offset);

            RewardDisplayerInteractiveElementParamBinaryData entry;

            entry.m_id = this->_reader->ReadInt();
            entry.m_itemIds = this->_reader->ReadIntArray();

            this->m_entries[entry.m_id] = entry;
        }

        qDebug() << ">> Loaded " << this->m_entries.size() << " entries for RewardDisplayerInteractiveElementParamStorage";
    }
};

#endif // BINARYDATA_REWARDDISPLAYERINTERACTIVEELEMENTPARAMSTORAGE_H
