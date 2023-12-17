package org.example;

import org.example.lib.CoreTestCase;
import org.example.lib.ui.MainPageObject;
import org.example.lib.ui.SearchPageObject;
import org.junit.Test;

public class ExampleKemSuTest extends CoreTestCase{

    private MainPageObject MainPageObject;

    protected void setUp() throws Exception{
        super.setUp();
        MainPageObject = new MainPageObject(driver);
    }

    @Test
    public void firstTest(){
        System.out.println("Our first test");
    }

    @Test
    public void testSearchElement(){
        SearchPageObject SearchPageObject = new SearchPageObject(driver);

        SearchPageObject.initSearchInput();
        SearchPageObject.typeSearchLine("Кемеровский государственный университет");
        SearchPageObject.waitForSearchResult("высшее учебное заведение в Кемерове");
        SearchPageObject.getAndCheckResult("Кемеровский государственный университет");
    }
}
