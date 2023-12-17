package org.example.lib.ui;

import io.appium.java_client.AppiumDriver;
import org.openqa.selenium.By;

public class ListPageObject extends MainPageObject{

    public ListPageObject(AppiumDriver driver){
        super(driver);
    }

    private static final String
            MORE_ELEMENT = "//*[@content-desc='{SUBSTRING}']",
            TITLE_ELEMENT = "//*[@text='{SUBSTRING}']";

    private static String getResultElement(String substring){
        return TITLE_ELEMENT.replace("{SUBSTRING}", substring);
    }

    private static String getResultMoreElement(String substring){
        return MORE_ELEMENT.replace("{SUBSTRING}", substring);
    }

    public void waitForMore(String substring){

        String search_result_xpath = getResultMoreElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void waitForDelete(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void waitForOk(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }
}
