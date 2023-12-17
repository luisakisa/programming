package org.example.lib;

import io.appium.java_client.AppiumDriver;
import io.appium.java_client.android.AndroidDriver;
import junit.framework.TestCase;
import org.openqa.selenium.remote.DesiredCapabilities;

import java.net.URL;

public class CoreTestCase extends TestCase{
    protected AppiumDriver driver;
    private static final String appiumURL = "http://localhost:4723/wd/hub";


    @Override
    protected void setUp() throws Exception{
        super.setUp();

        DesiredCapabilities capabilities = new DesiredCapabilities();

        capabilities.setCapability("appium:automationName", "UiAutomator2");
        capabilities.setCapability("platformName", "Android");
        capabilities.setCapability("deviceName", "Honor-practicum1");
        capabilities.setCapability("platformVersion", "9");
        capabilities.setCapability("appPackage", "org.wikipedia");
        capabilities.setCapability("appActivity", ".main.MainActivity");
        driver = new AndroidDriver(new URL(appiumURL), capabilities);
    }

    @Override
    protected void tearDown() throws Exception {
            driver.quit();
            super.tearDown();
        }
}
