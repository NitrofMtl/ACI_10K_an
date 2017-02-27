// This file is part of uHTTP.
//
// uHTTP is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// uHTTP is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Nome-Programma.  If not, see <http://www.gnu.org/licenses/>.


		/*/////////////////////////////////////////////////
	First, read a value, then convert it to volt, then resistance


	Reading is base on a lookup table and use y=mx+b between interval
	where x = the resistance and y, the temperature==>
	to find m: take the between value on the table==>
		(y2-y1)/(x2-x1)
	then, find b = y - mx1
	finaly, apply the formula to the read resistance
		reading = m*(resistance read) +b
		/////////////////////////////////////////////////*/



#ifndef ACI_10K_an
#define ACI_10K_an

#if (ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif


#ifndef rRef
#define rRef 10000
#endif

class Aci_10K {
private:
	//lookup table
	const float resistance[39];
	const int16_t temp_C[39];
	float _vRef = 5;
	int _RESO = 1023;
public:
	Aci_10K();
	Aci_10K(float vRef, int RESO);
	float getTemp(int reading);
};

#endif