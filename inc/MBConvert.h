/**
 * @file   MBConvert.h
 * @Author icke2063
 * @date   16.06.2013
 * @brief  Simple class to convert
 *
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

#ifndef MBCONVERT_H_
#define MBCONVERT_H_

namespace MB_Framework {

class MBConvert {
public:
	MBConvert(){}
	virtual ~MBConvert(){}

	/**
	 * convert short value to BigEndian
	 * @param dst	destination pointer
	 * @param src	source pointer
	 * @param count	count of values (short) to convert
	 */
	void ShorttoBigEndian(uint8_t *dst, const uint16_t *src, size_t count){
		size_t i;
		for(i=0;i<count;i++){
			dst[2*i] 		= (uint8_t)(src[i]>>8);		//high
			dst[(2*i)+1]	= (uint8_t)(src[i]);	//low
		}
	}

	/**
	 * convert short value from BigEndian to maschine specific endianess
	 * @param dst	destination pointer
	 * @param src	source pointer
	 * @param count	count of values(short) to convert
	 */
	void BigEndiantoShort(uint16_t *dst, const uint8_t *src, size_t count){
		size_t i;
		for(i=0;i<count;i++){
			dst[i] 	= (uint16_t)(src[2*i]<<8);	//high
			dst[i]	|= (uint16_t)(src[(2*i)+1]);	//low
		}
	}

};

} /* namespace MB_Framework */
#endif /* MBCONVERT_H_ */
