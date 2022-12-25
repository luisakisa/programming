import template from './template.js'

class XInput extends HTMLElement {
    
 constructor() { 
   console.log('constructor x-input...');  
   super();   
   this.type = '';  
   this.valueEmail = '';  
   this.valuePass = '';  
   this.value = '';  
   this.id = '';   
   this.disabled='';
   this.attachShadow({ mode: 'open' }); 
   this.shadowRoot.addEventListener("change", (event) => {
    console.log("x-text changed");
    event.stopPropagation();
    this.valueEmail = event.target.value;
    this.valuePass = event.target.value;
  });
   
 }

 connectedCallback() {  
   console.log('connectedCallback x-input...');  
   this._render();   //что происзодит при добавлении элемента на стр
 }

 disconnectedCallback() {     
   console.log('disconnectedCallback x-input...'); //при удалении    
 } 

 static get observedAttributes() {
   return ['type','value','id','disabled','valuePass','valueEmail']; 
}                    

 attributeChangedCallback(attr, oldValue, newValue) {
   console.log('attributeChangedCallback x-input...'); 
   if (oldValue === newValue) return;
   this[attr] = newValue;   
   console.log(this[attr]);
  }
  

 //**********************************

 _render() {
   console.log('_render x-input...'); 
   if(!this.ownerDocument.defaultView) return;    
   this.shadowRoot.innerHTML = template(this);  
         
 }
}

customElements.define('x-input',XInput);
console.log('Log:Defining x-input');

