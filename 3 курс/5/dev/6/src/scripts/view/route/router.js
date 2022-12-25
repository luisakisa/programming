console.log('Log:Exporting router');

class Router  {
    
   constructor() { 
      this._default = ''; 
      this._routes = [];       
   }
         
   add(url,view) {
      this._routes.push({'url':url,'view':view}); 
   }
   
   default(url) {
      this._default = url;  
   }
   
   async go(url='') {
       
     let view = null;
     
     if (url==='') {
       url = this._default;  
     }
     
     this._routes.forEach(route => {
        if (route.url === url) {
           view = route.view;  
        } 
     });
     
     if (view!==null) {        
        await import('./../page/'+view+'/component.js');
        let nodeView =  document.createElement(view);
        
        let nodeApp = document.getElementById('app');        
        nodeApp.removeChild(nodeApp.childNodes[0]);
        nodeApp.appendChild(nodeView); 
        
        history.pushState(null,null,url);
     }   
        
   }
   
}

class RouterFactory {
   
   static _router = null;
   
   static _createInstance() {
     return new Router();      
   }
      
   static createInstance() {
      if (RouterFactory._router === null) {
        RouterFactory._router = RouterFactory._createInstance();  
      }      
      return RouterFactory._router;
   }
}

export {RouterFactory};