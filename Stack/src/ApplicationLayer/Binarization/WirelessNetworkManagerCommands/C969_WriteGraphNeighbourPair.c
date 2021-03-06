/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C969_WriteGraphNeighbourPair.h"

uint8_t Compose_C969_WriteGraphNeighbourPair_Req(C969_WriteGraphNeighbourPair_Req* request, ComposerContext* context,
                                                 BinaryStream* toStream)
{
  context->cmdId = CMDID_C969_WriteGraphNeighbourPair;

  STREAM_WRITE_UINT16(toStream, request->m_unGraphID);
  STREAM_WRITE_UINT16(toStream, request->m_unNeighborNickname);

  return RCS_N00_Success;
}

/**
* @Debinarize
*/
uint8_t Parse_C969_WriteGraphNeighbourPair_Req(C969_WriteGraphNeighbourPair_Req* request, ParserContext* context,
                                               BinaryStream* fromStream)
{
  STREAM_READ_UINT16(fromStream, &request->m_unGraphID);
  STREAM_READ_UINT16(fromStream, &request->m_unNeighborNickname);

  return RCS_N00_Success;
}

/**
*
*/
uint8_t Compose_C969_WriteGraphNeighbourPair_Resp(C969_WriteGraphNeighbourPair_Resp* response, ComposerContext* context,
                                                  BinaryStream* toStream)
{
  context->cmdId = CMDID_C969_WriteGraphNeighbourPair;

  STREAM_WRITE_UINT16(toStream, response->m_unGraphID);
  STREAM_WRITE_UINT16(toStream, response->m_unNeighborNickname);
  STREAM_WRITE_UINT8(toStream, response->m_ucRemainingConnectionsNo);

  return RCS_N00_Success;
}

/**
*
*/
uint8_t Parse_C969_WriteGraphNeighbourPair_Resp(C969_WriteGraphNeighbourPair_Resp* response, ParserContext* context,
                                                BinaryStream* fromStream)
{
  STREAM_READ_UINT16(fromStream, &response->m_unGraphID);
  STREAM_READ_UINT16(fromStream, &response->m_unNeighborNickname);
  STREAM_READ_UINT8(fromStream, &response->m_ucRemainingConnectionsNo);

  return RCS_N00_Success;
}

