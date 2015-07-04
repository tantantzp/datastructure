#ifndef _TEMPERATURE_H_


int GetNumOfStation(void);

void GetStationInfo(int no, int *x, int *y, int *temp);

int GetQuery(int *x1, int *y1, int *x2, int *y2);

void Response(int temp);


#include "temperature_lib.h"


#endif //_TEMPERATURE_H_
