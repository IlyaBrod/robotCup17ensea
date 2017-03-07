#include "../IncludeAll.h"
//static variable
Timer GeneralItem::sinceInitUsTimer;

Serial GeneralItem::DEBUG_PC(USBTX,USBRX);
//static fonction
void GeneralItem::initGeneralItem()
{
	
	GeneralItem::sinceInitUsTimer.reset();
	GeneralItem::sinceInitUsTimer.start();
}
