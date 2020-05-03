/* Header for the frame management */
#ifndef _FRAMES_H_
#define _FRAMES_H_

#include "list.h"

int alloc_frame(List *frames);

int free_frame(List *frames, int frame_number);

#endif