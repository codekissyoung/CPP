#ifndef __COMMON_H__
#define __COMMON_H__

struct Reading{
    int hour;
    double temperature;
    Reading(int h, double t) : hour(h), temperature(t){}
};

void skip_to_int();
int get_int();
int get_int(int low, int high);

#endif
