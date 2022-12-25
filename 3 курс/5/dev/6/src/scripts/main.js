(async ()=>{ await true;//функция async вып-ся синхронно до первого await

    let routerModule = await import('./view/route/router.js');
    let router = routerModule.RouterFactory.createInstance();
    
    router.add('login'  ,  'x-login');
    router.add('products',  'x-products');
    router.add('basket',  'x-basket');
      
    if (localStorage.getItem('login') == null) {
        router.default('login');
    } else {
        router.default('products');
    }
    
    
    router.go();
    
    })();
    
    