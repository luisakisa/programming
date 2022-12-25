import template from './template.js'
import {
  delProduct as delProductFromBasket
} from '../../../model/model.js'
import { RouterFactory } from "./../../route/router.js";

import '../../component/x-table/component.js'

class XBasket extends HTMLElement {
    
    constructor() { 
      console.log('constructor x-Basket...');  
      super();   
      this.attachShadow({ mode: 'open' });               
    }
   
    connectedCallback() {  
      console.log('connectedCallback x-Basket...');  
      this._render();   
    }
   
    disconnectedCallback() {     
      console.log('disconnectedCallback x-Basket...');    
    } 
   
    static get observedAttributes() {
      return []; 
   }                    
   
    attributeChangedCallback(attr, prev, next) {
      console.log('attributeChangedCallback x-Basket...');     
    }
    
    //**********************************
    _listenerLogout(event) {
      event.stopPropagation();
       localStorage.clear();
       let router = RouterFactory.createInstance();
       router.go("login");
   }
   _listenerBack(event) {
    event.stopPropagation();
     let router = RouterFactory.createInstance();
     router.go("products");
 }
  
    async _listenerDel(event) {
       event.stopPropagation();
       let node = this.shadowRoot.querySelector(".container")
       let tr = node.childNodes[1].shadowRoot.querySelectorAll('.table-row');
       for (let i = 0; i < tr.length; i++) {
           if (tr[i].style.backgroundColor == 'rgb(187, 216, 192)')
               delProductFromBasket(i + 1);
       }
       this._render();
    }
   
    _render() {//
      console.log('_render x-Basket...');      
      if(!this.ownerDocument.defaultView) return;    
      this.shadowRoot.innerHTML = template(this);  
      this.shadowRoot.getElementById('logout').addEventListener(
        "click",
        this._listenerLogout.bind(this)
      );
      let node = this.shadowRoot.querySelector(".container")
      node.childNodes[1].shadowRoot.querySelector("#del").addEventListener(
        "click",
        this._listenerDel.bind(this)
      );
      node.childNodes[1].shadowRoot.querySelector("#back").addEventListener(
        "click",
        this._listenerBack.bind(this)
      );
    }
   }
   
   customElements.define('x-basket',XBasket);