#ifndef __MAIN_H__
#define __MAIN_H__



//STATE

typedef enum {
	
  STATE_SHOW_TIME,
  STATE_SET_TIME,
	
	STATE_SHOW_TIMER,
	STATE_SET_TIMER,
	
	STATE_SHOW_STOPWATCH,
	STATE_SET_STOPWATCH,
	
  STATE_SET_ALARM,
  STATE_ALARM_ON,
} State;

//EVENT
typedef enum {
    EVENT_NONE,
    EVENT_BUTTON_PRESS,
    EVENT_TIMEOUT,
    EVENT_ALARM_TRIGGER,
} Event;

#endif
