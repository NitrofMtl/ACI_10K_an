#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "ACI_10K_an.h"


Aci_10K::Aci_10K() : resistance{ //resistance array
	186.1,209.0,235.4,265.8,301,341.9,389.6,445.2,510.6,587.6,678.6,786.6,
	915.4,1070,1255,1479,1752,2083,2488,2986,3602,4368,5326,6531,8057,10000,
	12492,15711,19899,25391,32650,42326,55326,72951,97072,130410,176960,242660,336450
	},
	temp_C{ //temperature array in celcius
	150,145,140,135,130,125,120,115,110,105,100,95,90,85,80,75,70,65,60,
	55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40
	}
	{
	}


Aci_10K::Aci_10K(float vRef, int RESO) : resistance{ //resistance array
	186.1,209.0,235.4,265.8,301,341.9,389.6,445.2,510.6,587.6,678.6,786.6,
	915.4,1070,1255,1479,1752,2083,2488,2986,3602,4368,5326,6531,8057,10000,
	12492,15711,19899,25391,32650,42326,55326,72951,97072,130410,176960,242660,336450
	},
	temp_C{ //temperature array in celcius
	150,145,140,135,130,125,120,115,110,105,100,95,90,85,80,75,70,65,60,
	55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40
	}
	{
		_vRef = vRef;
		if(RESO==12) _RESO = 4095;
	}


float Aci_10K::getTemp(int reading){//input a bitrade value from analog input
	float Vin = 0;
	Vin = reading*_vRef/_RESO;	//find voltage in the input
	float r = (Vin / (_vRef - Vin) * rRef); //calculate the resistance
	//find between resistance in the table
	int i = 0;
	while(resistance[i]<r)i++;	
	//find m and b value of y=mx+b ==>	
	float m = (temp_C[i]-temp_C[i-1])/(resistance[i]-resistance[i-1]);// m = (y1-y2)/(x1-x2)	
	float b = temp_C[i-1]-(m*resistance[i-1]);//find b = y1 - m*x1*/
	float temp = m*r+b; //y=mx+b
	return temp;
}

