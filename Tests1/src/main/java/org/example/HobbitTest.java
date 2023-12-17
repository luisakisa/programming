package org.example;

import org.example.lib.CoreTestCase;
import org.example.lib.ui.ArticlePageObject;
import org.example.lib.ui.ListPageObject;
import org.example.lib.ui.MainPageObject;
import org.example.lib.ui.SearchPageObject;
import org.junit.Test;

public class HobbitTest extends CoreTestCase {

    private MainPageObject MainPageObject;

    protected void setUp() throws Exception{
        super.setUp();
        MainPageObject = new MainPageObject(driver);
    }

    @Test
    public void testAddAndDeleteArticle(){
        SearchPageObject SearchPageObject = new SearchPageObject(driver);
        SearchPageObject.initSearchInput();
        SearchPageObject.typeSearchLine("Хоббит, или Туда и обратно");
        SearchPageObject.waitForSearchResult("повесть английского писателя Джона Р. Р. Толкина");

        ArticlePageObject ArticlePageObject = new ArticlePageObject(driver);
        ArticlePageObject.waitForSave("Сохранить");
        ArticlePageObject.waitForAddList("Добавить в список");
        ArticlePageObject.initTitleListInput();
        ArticlePageObject.typeTitleList("Хоббит");
        ArticlePageObject.waitForOk("ОК");
        ArticlePageObject.waitForCheckList("Посмотреть список");

        ListPageObject ListPageObject = new ListPageObject(driver);
        ListPageObject.waitForMore("Ещё");
        ListPageObject.waitForDelete("Удалить список");
        ListPageObject.waitForOk("ОК");
    }
}
