import template from './template.js'
import {addProductToBasket
} from '../../../model/model.js'
import { RouterFactory } from "./../../route/router.js";

import '../../component/x-table/component.js'

class XProducts extends HTMLElement {
    
    constructor() { 
      console.log('constructor x-Products...');  
      super();   
      this.attachShadow({ mode: 'open' });        
    }
   
    connectedCallback() {  
      console.log('connectedCallback x-Products...');  
      this._render();   
    }
   
    disconnectedCallback() {     
      console.log('disconnectedCallback x-Products...');    
    } 
   
    static get observedAttributes() {
      return []; 
   }                    
   
    attributeChangedCallback(attr, prev, next) {
      console.log('attributeChangedCallback x-Products...');     
    }
    
    //**********************************
    _listenerToBasket(event) {
       event.stopPropagation();
      let router = RouterFactory.createInstance();

          router.go("basket");
    }
    _listenerAdd(event) {
       event.stopPropagation(); 
       let node = this.shadowRoot.querySelector(".container")
       let tr =node.childNodes[1].shadowRoot.querySelectorAll('.table-row');
       console.log(node.childNodes[1].shadowRoot.querySelectorAll('.table-row'))
      for (let i = 0; i < tr.length; i++) {
        if (tr[i].style.backgroundColor == 'rgb(187, 216, 192)')
            addProductToBasket(i + 1);
    }
    }
    _listenerLogout(event) {
       event.stopPropagation();
        localStorage.clear();
        let router = RouterFactory.createInstance();
        router.go("login");
    }
   
    _render() {//
      console.log('_render x-Products...');      
      if(!this.ownerDocument.defaultView) return;    
      this.shadowRoot.innerHTML = template(this);  
      this.shadowRoot.getElementById('to-basket').addEventListener(
        "click",
        this._listenerToBasket.bind(this)
      );    
      let node = this.shadowRoot.querySelector(".container")
      node.childNodes[1].shadowRoot.querySelector("#add").addEventListener(
        "click",
        this._listenerAdd.bind(this)
      );
      this.shadowRoot.getElementById('logout').addEventListener(
        "click",
        this._listenerLogout.bind(this)
      );
    }
   }
   
   customElements.define('x-products',XProducts);