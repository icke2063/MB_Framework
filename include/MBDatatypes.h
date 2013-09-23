/**
 * @file   MBDatatypes.h
 * @Author icke2063
 * @date   13.06.2013
 * @brief  Default modbus datatypes
 * Copyright © 2013 icke2063 <icke2063@gmail.com>
 *
 * This framework is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef MBDATATYPES_H_
#define MBDATATYPES_H_

#pragma pack(push, enter_datatype, 1)

typedef union {
	struct {
		uint8_t bit0 :1;
		uint8_t bit1 :1;
		uint8_t bit2 :1;
		uint8_t bit3 :1;
		uint8_t bit4 :1;
		uint8_t bit5 :1;
		uint8_t bit6 :1;
		uint8_t bit7 :1;
	} u;
	uint8_t value;

} BYTE_UNION;

typedef struct {
	BYTE_UNION high_byte; //big endian
	BYTE_UNION low_byte; //big endian
} mb_register;

#pragma pack(pop, enter_datatype)

#endif /* MBDATATYPES_H_ */
