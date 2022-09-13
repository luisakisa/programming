package com.company.model.rendering;

public class Screen {
    private int[][] screen;
    private double[] width;

    public Screen(){
        this.screen = new int[800][5];
        this.width = new double[800];
    }

    public int[][] getScreen(){return this.screen;}

    public double[] getWidth() {
        return width;
    }

    public void setScreen(int[][] screen, double[] width){
        this.screen = screen;
        this.width = width;
    }
}
