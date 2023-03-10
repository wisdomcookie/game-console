#include "baseclass.h"

int BaseClass::id_cnt = 0;

BaseClass::BaseClass()
{
    id = id_cnt; //Uniquely identify the object

    id_cnt++;    //Increment the created object count

    //SHOW_WHERE;  //Be careful of the ordering here
}
