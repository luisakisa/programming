package com.company.model.client.net;

import com.company.model.client.Client;
import com.company.model.listeners.Realize;

public class TimeOut extends Thread{
    public static int timeout = 0;
    public static final int MAX_TIME = 5;
    private boolean launched;
    private Realize r;

    public TimeOut(Realize r){
        this.r = r;
        launched = false;
    }

    @Override
    public void run() {
        launched = true;
        while (launched){
            try {
                timeout++;
                if(timeout > MAX_TIME){
                    System.out.println("Превышено время ожидания сервера");
                    r.make();
                }
                sleep(1000);
            }
            catch (Exception e){}
        }
    }

    public boolean isLaunched() {
        return launched;
    }

    public void setLaunched(boolean launched) {
        this.launched = launched;
    }
}
