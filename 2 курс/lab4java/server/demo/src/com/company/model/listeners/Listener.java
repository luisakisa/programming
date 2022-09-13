package com.company.model.listeners;

import com.company.model.math.Angles;

public class Listener extends Thread{
    private Event event;
    private Realize realize;
    private boolean launched;
    private boolean pause;

    public Listener(Event event, Realize realize){
        this.event = event;
        this.realize = realize;
        pause = false;
        launched = false;
    }

    @Override
    public void run() {
        launched = true;
        while (launched){
            try { Thread.currentThread().sleep(1); } catch (Exception e) {}
            if(!pause) {
                if(event.isEvent()) {
                    realize.make();
                }
            }
        }
    }

    public boolean isLaunched() {
        return launched;
    }

    public boolean isPause() {
        return pause;
    }

    public void setLaunched(boolean launched) {
        this.launched = launched;
    }

    public void setPause(boolean pause) {
        this.pause = pause;
    }
}
