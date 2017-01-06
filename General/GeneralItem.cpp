#include "../IncludeAll.h"
//static variable
Timer GeneralItem::sinceInitUsTimer;


//static fonction
void GeneralItem::initGeneralItem()
{
	GeneralItem::sinceInitUsTimer.reset();
	GeneralItem::sinceInitUsTimer.start();
}
