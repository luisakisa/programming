package com.company.model.listeners;

public class Event {
    protected boolean event;

    public Event(){
        event = false;
    }

    public Event(boolean event){
        this.event = event;
    }

    public void setEvent(boolean event) {
        this.event = event;
    }

    public boolean isEvent() {
        return event;
    }
}
