package org.example.lib.ui;

import io.appium.java_client.AppiumDriver;
import org.junit.Assert;
import org.openqa.selenium.By;
import org.openqa.selenium.WebElement;

public class SearchPageObject extends MainPageObject{

    public SearchPageObject(AppiumDriver driver){
        super(driver);
    }

    private static final String
            SEARCH_INIT_ELEMENT = "//*[contains(@text,'Поиск по Википедии')]",
            SEARCH_INPUT = "//*[contains(@text,'Поиск по Википедии')]",
            SEARCH_RESULT = "//*[@text='{SUBSTRING}']";

    public void initSearchInput(){
        this.waitForElementAndClick(By.xpath(SEARCH_INIT_ELEMENT),
                "Невозможно нажать на поле ввода", 15);

        this.waitForElementPresent(By.xpath(SEARCH_INIT_ELEMENT),
                "Невозможно найти поле ввода", 15);
    }

    public void typeSearchLine(String search_line){
        this.waitForElementAndSendKeys(By.xpath(SEARCH_INPUT), search_line,
                "Невозможно найти поле ввода", 15);
    }

    private static String getResultSearchElement(String substring){
        return SEARCH_RESULT.replace("{SUBSTRING}", substring);
    }

    public void waitForSearchResult(String substring){

        String search_result_xpath = getResultSearchElement(substring);

        this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно нажать '" + substring + "'", 15);
    }

    public void getAndCheckResult(String substring){
        String search_result_xpath = getResultSearchElement(substring);

        this.waitForElementPresent(By.xpath(search_result_xpath),
                "Невозможно найти заголовок", 15);

        WebElement title_element = this.waitForElementAndClick(By.xpath(search_result_xpath), "Невозможно найти '" + substring + "'", 15);

        String result = title_element.getText();

        Assert.assertEquals("Найдено несовпадение в названии статьи",
                substring, result);
    }
}
