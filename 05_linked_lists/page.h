/* Header for the Second-Chance Page Replacement */

#ifndef PAGE_H
#define PAGE_H

#include "clist.h"

/* Define a structure for information about pages. */
typedef struct Page_
{
    int number;
    int reference;
} Page;

/* --------------------- Public Interface ------------------------ */

int replace_page(CListElmt **current);


#endif;