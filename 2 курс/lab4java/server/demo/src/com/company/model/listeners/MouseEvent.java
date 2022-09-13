package com.company.model.listeners;

public class MouseEvent extends Event{
    private double deltaX;

    public MouseEvent(){
        event = false;
        deltaX = 0;
    }

    public MouseEvent(boolean event, double deltaX){
        this.event = event;
        this.deltaX = deltaX;
    }

    public void setEvent(boolean event) {
        this.event = event;
    }

    public boolean isEvent() {
        return event;
    }

    public void setDeltaX(double deltaX) {
        this.deltaX = deltaX;
    }

    public double getDeltaX() {
        return deltaX;
    }
}
