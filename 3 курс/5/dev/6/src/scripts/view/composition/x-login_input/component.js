import template from './template.js'
import "../../component/x-input/component.js";
import { RouterFactory } from "./../../route/router.js";
import { async_login as login} from './../../../model/model.js'
class XLoginInput extends HTMLElement {
    
 constructor() { 
   console.log('constructor x-input...');  
   super();   
   this.error = '';
  this.attachShadow({ mode: 'open' });   
       
 }

 connectedCallback() {  
   console.log('connectedCallback x-input...');  
   this._render();   //что происзодит при добавлении элемента на стр
 }

 disconnectedCallback() {     
   console.log('disconnectedCallback x-input...'); //при удалении    
 } 

 static get observedAttributes() {
   return ['x-error']; 
}                    

 attributeChangedCallback(attr, prev, next) {
   console.log('attributeChangedCallback x-input...');     
   if(prev !== next) {
    if (attr==='x-error') {       
      this.error = next;
    } 
  }
  }

 //**********************************
 async _listener(event) {
  console.log("x-login_button clicked");
   event.stopPropagation();
  let node = this.shadowRoot.querySelector(".container")
  let user = {
    email: node.childNodes[3].valueEmail,
    password: node.childNodes[7].valuePass
};
  let router = RouterFactory.createInstance();
  console.log(user)
  let hash = await login(JSON.stringify(user));
  if (hash == "nothash") {
      this.error = "value='User not founded try again'";
      this._render()
  } else if (hash == "") {

  } else {
      localStorage.setItem("login", user.email);
      localStorage.setItem("pass", user.password);
      localStorage.setItem("hash", hash);
      router.go("products");
  };
 
}

 _render() {
   console.log('_render x-login_input...');      
   this.shadowRoot.innerHTML = template(this);  
   this.shadowRoot.getElementById('enter').addEventListener(
    "click",
    this._listener.bind(this)
  );
}
}

customElements.define('x-login_input',XLoginInput);
console.log('Log:Defining x-logon_input');