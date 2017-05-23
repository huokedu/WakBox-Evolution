#ifndef BINARYDATA_ZAAPSTORAGE_H
#define BINARYDATA_ZAAPSTORAGE_H

#include "BinaryData/BinaryDataStorage.h"

template<class T>
class ZaapStorage : public BinaryDataStorage<T>
{
public:
    ZaapStorage() { }

    void Load()
    {
        qint32 size = this->m_rows.size();

        for (qint32 i = 0; i < size; ++i)
        {
            Row row = this->m_rows[i];
            this->_reader->SetBufferPosition(row.offset);

            ZaapBinaryData entry;

            entry.m_zaapId = this->_reader->ReadInt();
            entry.m_exitX = this->_reader->ReadInt();
            entry.m_exitY = this->_reader->ReadInt();
            entry.m_exitWorldId = this->_reader->ReadInt();
            entry.m_visualId = this->_reader->ReadInt();
            entry.m_uiGfxId = this->_reader->ReadInt();
            entry.m_landmarkTravelType = this->_reader->ReadByte();
            entry.m_zaapBase = this->_reader->ReadBool();
            entry.m_destinationCriteria = this->_reader->ReadString();
            entry.if (buffer.get() != 0) { = this->_reader->ReadByte();

            this->m_entries[entry.m_id] = entry;
        }

        qDebug() << ">> Loaded " << this->m_entries.size() << " entries for ZaapStorage";
    }
};

#endif // BINARYDATA_ZAAPSTORAGE_H
