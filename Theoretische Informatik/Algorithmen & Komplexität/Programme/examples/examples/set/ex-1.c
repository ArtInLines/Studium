/*****************************************************************************
*                                                                            *
*  ex-1.c                                                                    *
*  ======                                                                    *
*                                                                            *
*  Description: Illustrates using a set (see Chapter 7).                     *
*                                                                            *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "set.h"

/*****************************************************************************
*                                                                            *
*  ------------------------------- print_set ------------------------------  *
*                                                                            *
*****************************************************************************/

static void print_set(const Set *set) {

ListElmt           *member;

int                *data,
                   size,
                   i;

/*****************************************************************************
*                                                                            *
*  Display the set.                                                          *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Set size is %d\n", size = set_size(set));

i = 0;
member = list_head(set);

while (i < size) {

   data = list_data(member);
   fprintf(stdout, "set[%03d]=%03d\n", i, *data);
   member = list_next(member);
   i++;

}

return;

}

/*****************************************************************************
*                                                                            *
*  ------------------------------- match_int ------------------------------  *
*                                                                            *
*****************************************************************************/

static int match_int(const void *key1, const void *key2) {

/*****************************************************************************
*                                                                            *
*  Determine whether two integers match.                                     *
*                                                                            *
*****************************************************************************/

return !memcmp(key1, key2, sizeof(int));

}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv) {

Set                set,
                   set1,
                   set2;

int                *data,
                   retval,
                   i;

/*****************************************************************************
*                                                                            *
*  Initialize the set.                                                       *
*                                                                            *
*****************************************************************************/

set_init(&set, match_int, free);

/*****************************************************************************
*                                                                            *
*  Perform some set operations.                                              *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Inserting 10 members\n");

for (i = 9; i >= 0; i--) {

   if ((data = (int *)malloc(sizeof(int))) == NULL)
      return 1;

   *data = i + 1;

   if ((retval = set_insert(&set, data)) < 0)
      return 1;
   else if (retval == 1)
      free(data);

}

print_set(&set);

fprintf(stdout, "Inserting the same members again\n");

for (i = 9; i >= 0; i--) {

   if ((data = (int *)malloc(sizeof(int))) == NULL)
      return 1;

   *data = i + 1;

   if ((retval = set_insert(&set, data)) < 0)
      return 1;
   else if (retval == 1)
      free(data);

}

print_set(&set);

fprintf(stdout, "Inserting 200 and 100\n");

if ((data = (int *)malloc(sizeof(int))) == NULL)
   return 1;

*data = 200;

if ((retval = set_insert(&set, data)) < 0)
   return 1;
else if (retval == 1)
   free(data);

if ((data = (int *)malloc(sizeof(int))) == NULL)
   return 1;

*data = 100;

if ((retval = set_insert(&set, data)) < 0)
   return 1;
else if (retval == 1)
   free(data);

print_set(&set);

fprintf(stdout, "Removing 100, 5, and 10\n");

i = 100;
data = &i;

if (set_remove(&set, (void **)&data) == 0)
   free(data);

i = 5;
data = &i;

if (set_remove(&set, (void **)&data) == 0)
   free(data);

i = 10;
data = &i;

if (set_remove(&set, (void **)&data) == 0)
   free(data);

print_set(&set);

fprintf(stdout, "Removing three members\n");

if (list_rem_next(&set, NULL, (void **)&data) == 0)
   free(data);

if (list_rem_next(&set, NULL, (void **)&data) == 0)
   free(data);

if (list_rem_next(&set, NULL, (void **)&data) == 0)
   free(data);

print_set(&set);

fprintf(stdout, "Removing all members\n");

while (set_size(&set) > 0) {

   if (list_rem_next(&set, NULL, (void **)&data) == 0)
      free(data);
   
}

print_set(&set);

/*****************************************************************************
*                                                                            *
*  Initialize two sets.                                                      *
*                                                                            *
*****************************************************************************/

set_init(&set1, match_int, free);
set_init(&set2, match_int, free);

/*****************************************************************************
*                                                                            *
*  Perform some set operations.                                              *
*                                                                            *
*****************************************************************************/

for (i = 9; i >= 0; i--) {

   if ((data = (int *)malloc(sizeof(int))) == NULL)
      return 1;

   *data = i + 1;

   if ((retval = set_insert(&set1, data)) < 0)
      return 1;
   else if (retval == 1)
      free(data);

   if (i == 5 || i == 6 || i == 7) {

      if ((data = (int *)malloc(sizeof(int))) == NULL)
         return 1;

      *data = i * 10;

      if ((retval = set_insert(&set2, data)) < 0)
         return 1;
      else if (retval == 1)
         free(data);

      }

   else if (i == 3 || i == 1) {

      if ((data = (int *)malloc(sizeof(int))) == NULL)
         return 1;

      *data = i;

      if ((retval = set_insert(&set2, data)) < 0)
         return 1;
      else if (retval == 1)
         free(data);

   }

}

fprintf(stdout, "Set 1 for testing unions, intersections, and differences\n");
print_set(&set1);
fprintf(stdout, "Set 2 for testing unions, intersections, and differences\n");
print_set(&set2);

fprintf(stdout, "Determining the union of the two sets\n");

if (set_union(&set, &set1, &set2) != 0)
   return 1;

print_set(&set);

fprintf(stdout, "Destroying the union\n");
set_destroy(&set);

fprintf(stdout, "Determining the intersection of the two sets\n");

if (set_intersection(&set, &set1, &set2) != 0)
   return 1;

print_set(&set);

fprintf(stdout, "Testing whether the intersection equals Set 1...Value=%d "
   "(0=OK)\n", set_is_equal(&set, &set1));

fprintf(stdout, "Testing whether Set 1 equals itself...Value=%d (1=OK)\n",
   set_is_equal(&set1, &set1));

fprintf(stdout, "Testing whether the intersection is a subset of Set 1..."
   "Value=%d (1=OK)\n", set_is_subset(&set, &set1));

fprintf(stdout, "Testing whether Set 2 is a subset of Set 1...Value=%d "
   "(0=OK)\n", set_is_subset(&set2, &set1));

fprintf(stdout, "Destroying the intersection\n");
set_destroy(&set);

fprintf(stdout, "Determining the difference of the two sets\n");

if (set_difference(&set, &set1, &set2) != 0)
   return 1;

print_set(&set);

i = 3;
fprintf(stdout, "Testing whether %03d is in difference...Value=%d (0=OK)\n",i,
   set_is_member(&set, &i));

i = 5;
fprintf(stdout, "Testing whether %03d is in difference...Value=%d (1=OK)\n",i,
   set_is_member(&set, &i));

/*****************************************************************************
*                                                                            *
*  Destroy the sets.                                                         *
*                                                                            *
*****************************************************************************/

fprintf(stdout, "Destroying the sets\n");
set_destroy(&set);
set_destroy(&set1);
set_destroy(&set2);

return 0;

}
