enum Screen_123456 { SCR_CLOCK };	//Screen indexes
lv_obj_t *screen_123456[1];    //screen pointers
GyroPalmLVGL form_123456[1];   //screen helper methods
Screen_123456 curScreen_123456 = SCR_CLOCK;    //default screen

lv_task_t* tmr_123456;

void lv_task_123456(struct _lv_task_t *data) {
    loop_123456();
}

static void btn_event_123456(lv_obj_t * obj, lv_event_t event)
{
    if (event == LV_EVENT_CLICKED) {
        String btnName = lv_list_get_btn_text(obj);
		Serial.printf("Clicked: %s\n", btnName);

        switch (curScreen_123456)
        {
            case SCR_CLOCK:
				showApp(SCR_HOME);
            break;

            default: break;
		}
	}
}


// Begin AutoGenerated Screens - DO NOT EDIT BELOW
void showApp_123456(int page) {
    if ((Screen_123456) page != curScreen_123456) {
        form_123456[curScreen_123456].removeBar();    //remove old StatusBar before proceeding
    }

    switch (page)
    {
		case SCR_CLOCK:
        {
            //Draw screen UI
            curScreen_123456 = (Screen_123456) page;
            form_123456[curScreen_123456].init(screen_123456[curScreen_123456]);  //now defining screen items
            form_123456[curScreen_123456].createBar(barTask, lv_update_task);
            form_123456[curScreen_123456].setTime(gplm.getTime());
			form_123456[curScreen_123456].createLabel(58, -37, "Hello Clock");    //show element
			form_123456[curScreen_123456].createLED(-58, -37, true);   //show element
			form_123456[curScreen_123456].createButton(0, 67, "Testing", btn_event_123456, true, 214);    //show element

            form_123456[curScreen_123456].showScreen(ANIM_NONE);   //show the screen w/ no animation
        }
        break;


        default: break;
    }
	form_123456[curScreen_123456].setBarCallback(hide_123456);
}
// End AutoGenerated Screens - DO NOT EDIT ABOVE

void show_123456()
{
    showApp_123456(curScreen_123456);
	
	tmr_123456 = lv_task_create(lv_task_123456, 1000, LV_TASK_PRIO_LOWEST, NULL);
}

void loop_123456()
{
	Serial.println("Fetching weather");
}

void hide_123456(int barIntent)
{
	if (barIntent == BAR_SWIPE_LEFT) {
		lv_task_del(tmr_123456); //removes the task
		showApp(SCR_HOME);
	}
}
