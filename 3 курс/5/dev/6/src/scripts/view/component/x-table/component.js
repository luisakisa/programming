import template from './template.js'
import "../x-input/component.js";
import { async_getProducts as getProducts,async_getBasket as getBasket} from './../../../model/model.js';

class XTable extends HTMLElement {
    
    constructor() { 
      console.log('constructor x-Table...');  
      super();  
      this.id = '';   
      this.x_value = '';  
      this.buttonback='';
      this.empty = '';
      this.attachShadow({ mode: 'open' }); 
      
    }
   
    connectedCallback() {  
      console.log('connectedCallback x-Table...');  
      this._render();   //что происзодит при добавлении элемента на стр
    }
   
    disconnectedCallback() {     
      console.log('disconnectedCallback x-Table...'); //при удалении    
    } 
   
    static get observedAttributes() {
      return ['id','x_value', 'buttonback']; 
   }                    
   
    attributeChangedCallback(attr, oldValue, newValue) {
      console.log('attributeChangedCallback x-Table...'); 
      if (oldValue === newValue) return;
      this[attr] = newValue;   
      console.log(newValue);
     }
     
   
    //**********************************
   
    async _render() {
      console.log('_render x-Table...'); 
       
      if(!this.ownerDocument.defaultView) return;    
     this.shadowRoot.innerHTML = template(this);  
     let t = this.shadowRoot.querySelector(".table-content");
     let products = 0;
     if(this.id == "del") {products = await getBasket(localStorage.getItem("hash"));
     for (let i = 0; i < products.length; i++) {
         t.insertAdjacentHTML('afterBegin', '<div class="table-row"></div>');
         let r = this.shadowRoot.querySelector(".table-row");
         r.addEventListener('click', () => {
             if (r.style.backgroundColor != 'rgb(187, 216, 192)') r.style.backgroundColor = 'rgb(187, 216, 192)';
             else r.style.backgroundColor = '#EEEEEE'
         });
         r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._name}</div>`);
         r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._parametrs}</div>`);
         r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._total}</div>`);}}
     else if(this.id == "add") {products = await getProducts(localStorage.getItem("hash"));
      for (let i = 0; i < products.length; i++) {
        t.insertAdjacentHTML('beforeEnd', `<div class="table-row"> </div>`);
        let r = t.lastElementChild;
        r.addEventListener('click', () => {
            if (r.style.backgroundColor != 'rgb(187, 216, 192)') r.style.backgroundColor = 'rgb(187, 216, 192)';
            else r.style.backgroundColor = '#EEEEEE'
        });
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._name}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._parametrs}</div>`);
        r.insertAdjacentHTML('beforeEnd', `<div class="table-data">${products[i]._total}</div>`);
      }
    }
            
    }
   }
   
   customElements.define('x-table',XTable);