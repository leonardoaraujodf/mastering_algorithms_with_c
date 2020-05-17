#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "list.h"
#include "bistree.h"
#include "traverse.h"

#define SEED 31UL
#define NUMBER_OCCURENCES 5

typedef struct _Info
{
    unsigned int value;
    unsigned int element_number;
    struct tm * localtime;
} Info;

int compare_values(const void *key1, const void *key2)
{
    unsigned int value1 = ((Info *)key1)->value;
    unsigned int value2 = ((Info *)key2)->value;

    if (value1 > value2)
        return 1;
    else if (value1 == value2)
        return 0;
    else
        return -1;

}

void destroy_info(void *data)
{
    free((Info *)data);
}

int main()
{
    /* Initializes the random number generator */
    srand(SEED);

    unsigned int i;
    time_t raw_time;
    BisTree * tree = (BisTree *)malloc(sizeof(BisTree));
    Info ** occurrences = (Info **)malloc(NUMBER_OCCURENCES * sizeof(Info *));
    bistree_init(tree, compare_values, destroy_info);

    for (i = 0; i < NUMBER_OCCURENCES; i++)
    {
        int retval;

        occurrences[i] = (Info *)malloc(sizeof(Info));
        time(&raw_time);
        occurrences[i]->localtime = localtime(&raw_time);
        occurrences[i]->element_number = i;
        occurrences[i]->value = rand() % 10000;

        printf("Element localtime: %s\n", asctime(occurrences[i]->localtime));
        printf("Element number: %u\n", occurrences[i]->element_number);
        printf("Element value: %u\n", occurrences[i]->value);

        if ((retval = bistree_insert(tree, (void *)occurrences[i])) != 0)
        {
            if (retval == 1)
            {
                printf("Node already in the tree!\n");
                free(occurrences[i]);
                continue;
            }
            else
            {
                printf("Error trying to insert node in the tree!\n");
                exit(1);
            }
        }

        usleep( ((rand() % 400000) + 100000) );

    }

    List * list = (List *)malloc(sizeof(List));
    list_init(list, NULL);

    inorder(tree->root, list);

    ListElmt *member;
    Info *actual_info;

    for(member = list_head(list); member != NULL; member = list_next(member))
    {
        actual_info = (Info *)(((AvlNode *)member->data)->data);
        printf("---------------------------\n");
        printf("Element number: %u\n", actual_info->element_number);
        printf("Element value: %u\n", actual_info->value);
        printf("Element localtime: %s\n", asctime(actual_info->localtime));
        printf("---------------------------\n");
    }

    list_destroy(list);
    free(list);
    bistree_destroy(tree);
    free(occurrences);
    free(tree);

    return 0;
}