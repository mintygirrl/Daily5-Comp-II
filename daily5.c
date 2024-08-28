#include <stdio.h>

/***********************************************************
Author: Fallon Weiss
Date: 1/29/24
Effort: 4 hours.
Purpose: To challenge ourselves to think out of the box and print
the bits through an array instead of through a function call as we
have done previously.
***********************************************************/

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = { 0 };

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);

    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);
    display_flags(flag_holder, 5);
    return 0;
}

void set_flag(unsigned int flag_holder[], int flag_position)
{
    int constant = sizeof(int) * 8;
    int compare = 1 << flag_position;
    int split = flag_position / constant;
    flag_holder[split] = flag_holder[split] | compare;
    //this should work ^^
}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    int compare = 1 << flag_position;
    int constant = sizeof(int) * 8;
    compare = ~compare;
    int split = flag_position / constant;
    flag_holder[split] = flag_holder[split] & compare;
    //this should work^^
}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int constant = sizeof(int) * 8;
    int split = flag_position / constant;
    int versus = flag_holder[split] >> flag_position;
    int compare = 1 & versus;
    return compare;
    //this should work^^
}

void display_flags_as_array(unsigned int flag_holder)
{
    //read in a pointer to an integer
    //check_flag
    unsigned int* f = &flag_holder;
    int constant = sizeof(int) * 8;
    int i;
    for(i=0; i<=constant-1; i++)
    {
        printf("%d", check_flag(f, i));
        if(i%4 == 3)
        {
            printf(" ");
        }
    }

}

void display_flags(unsigned int flag_holder[], int size)
{
   //display_flags_as_array
   //modify such that it's backwards

    int i;
    for(i = 0; i <= size-1; i++)
    {
        display_flags_as_array(flag_holder[i]);
        printf("\n");
    }
   
}

 