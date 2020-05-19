/**
 * @file parcels.h
 * @author Kyle Loudon
 * @date 18 May 2020
 * @brief Header of Functions for Sorting Parcels
 * 
 */

#include "pqueue.h"

#ifndef PARCELS_H
#define PARCELS_H

typedef struct _Parcel
{
    char product_name[50];
    int value_payed;
    int weight;
    int priority;
    void (*calculate_priority)(int *priority);
} Parcel;

int get_parcel(PQueue *parcels, Parcel *parcel);

int put_parcel(PQueue *parcels, Parcel *parcel);

#endif 