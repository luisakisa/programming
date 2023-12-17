package org.example.lib.ui;

import io.appium.java_client.AppiumDriver;
import org.openqa.selenium.By;

public class ArticlePageObject extends MainPageObject{

    public ArticlePageObject(AppiumDriver driver){
        super(driver);
    }

    private static final String
            TITLE_LIST_INIT_ELEMENT = "//*[@resource-id='org.wikipedia:id/text_input']",
            TITLE_ELEMENT = "//*[@text='{SUBSTRING}']";

    private static String getResultElement(String substring){
        return TITLE_ELEMENT.replace("{SUBSTRING}", substring);
    }

    public void waitForSave(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void waitForAddList(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void waitForOk(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void waitForCheckList(String substring){

        String search_result_xpath = getResultElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void initTitleListInput(){
        this.waitForElementAndClick(By.xpath(TITLE_LIST_INIT_ELEMENT),
                "Невозможно нажать на поле ввода", 15);
    }

    public void typeTitleList(String search_line){
        this.waitForElementAndSendKeys(By.xpath(TITLE_LIST_INIT_ELEMENT), search_line,
                "Невозможно найти поле ввода", 15);
    }
}
