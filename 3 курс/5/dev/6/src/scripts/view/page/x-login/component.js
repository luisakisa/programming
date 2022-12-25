import template from './template.js'

import '../../composition/x-login_input/component.js'

class XLogin extends HTMLElement {
    
 constructor() { 
   console.log('constructor x-login...');  
   super();   
   this.attachShadow({ mode: 'open' });               
 }

 connectedCallback() {  
   console.log('connectedCallback x-login...');  
   this._render();   
 }

 disconnectedCallback() {     
   console.log('disconnectedCallback x-login...');    
 } 

 static get observedAttributes() {
   return []; 
}                    

 attributeChangedCallback(attr, prev, next) {
   console.log('attributeChangedCallback x-login...');     
 }
 
 //**********************************
 
 _render() {
   console.log('_render x-login...');      
   if(!this.ownerDocument.defaultView) return;    
   this.shadowRoot.innerHTML = template(this);      
 }
}

customElements.define('x-login',XLogin);
console.log('Log:Defining x-login');