console.log('Log:Exporting template for x-input');

export default function(vm) {
  if(vm.id == "email"){return ` 
  <div>    
  <input id="${vm.id}" type="${vm.type}" value="${vm.valueEmail}"  ${vm.disabled}><br>
  </div>   
  <style> 
  #error{
    background-color: rgb(228, 201, 235);
    color: red; 
    border: none;
}
  input[type="text"]{
    padding-left: 12px;
    position: relative;
    display: flex;
    flex-direction: row;
    font-size: 14px;
    border-color: rgba(31, 33, 65, 0.25);
    border-radius: 4px;
    border-width: 1px;}
    input[type="text"]:focus {
        color: rgba(31, 33, 65, 0.75);
        outline: 1px rgba(31, 33, 65, 0.5);
        border-width: 1px;
        border-color: rgba(31, 33, 65, 0.5);
      }
input[type="password"]{
    padding-left: 12px;
    position: relative;
    display: flex;
    flex-direction: row;
    font-size: 14px;
    border-color: rgba(31, 33, 65, 0.25);
    border-radius: 4px;
    border-width: 1px;}
    input[type="password"]:focus {
        color: rgba(31, 33, 65, 0.75);
        outline: 1px rgba(31, 33, 65, 0.5);
        border-width: 1px;
        border-color: rgba(31, 33, 65, 0.5);
      }
input[type="button"]{color: #ffffff;
    padding-top: 9px;
    padding-bottom: 9px;
    padding-left: 19px;
    padding-right: 19px;
    border: none;
    background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
    border-radius: 22px;}   
    </style>       
`}
   else if(vm.id == "password"){
    return ` 
    <div>    
    <input id="${vm.id}" type="${vm.type}" value="${vm.valuePass}"  ${vm.disabled}><br>
    </div>   
    <style> 
    #error{
      background-color: rgb(228, 201, 235);
      color: red; 
      border: none;
  }
    input[type="text"]{
      padding-left: 12px;
      position: relative;
      display: flex;
      flex-direction: row;
      font-size: 14px;
      border-color: rgba(31, 33, 65, 0.25);
      border-radius: 4px;
      border-width: 1px;}
      input[type="text"]:focus {
          color: rgba(31, 33, 65, 0.75);
          outline: 1px rgba(31, 33, 65, 0.5);
          border-width: 1px;
          border-color: rgba(31, 33, 65, 0.5);
        }
  input[type="password"]{
      padding-left: 12px;
      position: relative;
      display: flex;
      flex-direction: row;
      font-size: 14px;
      border-color: rgba(31, 33, 65, 0.25);
      border-radius: 4px;
      border-width: 1px;}
      input[type="password"]:focus {
          color: rgba(31, 33, 65, 0.75);
          outline: 1px rgba(31, 33, 65, 0.5);
          border-width: 1px;
          border-color: rgba(31, 33, 65, 0.5);
        }
  input[type="button"]{color: #ffffff;
      padding-top: 9px;
      padding-bottom: 9px;
      padding-left: 19px;
      padding-right: 19px;
      border: none;
      background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
      border-radius: 22px;}   
      </style>       
  `
   }
   else{return ` 
  <div>    
  <input id="${vm.id}" type="${vm.type}" value="${vm.value}"  ${vm.disabled}><br>
  </div>   
  <style> 
  #error{
    background-color: rgb(228, 201, 235);
    color: red; 
    border: none;
}
  input[type="text"]{
    padding-left: 12px;
    position: relative;
    display: flex;
    flex-direction: row;
    font-size: 14px;
    border-color: rgba(31, 33, 65, 0.25);
    border-radius: 4px;
    border-width: 1px;}
    input[type="text"]:focus {
        color: rgba(31, 33, 65, 0.75);
        outline: 1px rgba(31, 33, 65, 0.5);
        border-width: 1px;
        border-color: rgba(31, 33, 65, 0.5);
      }
input[type="password"]{
    padding-left: 12px;
    position: relative;
    display: flex;
    flex-direction: row;
    font-size: 14px;
    border-color: rgba(31, 33, 65, 0.25);
    border-radius: 4px;
    border-width: 1px;}
    input[type="password"]:focus {
        color: rgba(31, 33, 65, 0.75);
        outline: 1px rgba(31, 33, 65, 0.5);
        border-width: 1px;
        border-color: rgba(31, 33, 65, 0.5);
      }
input[type="button"]{color: #ffffff;
    padding-top: 9px;
    padding-bottom: 9px;
    padding-left: 19px;
    padding-right: 19px;
    border: none;
    background: linear-gradient(180deg, #bc9cff 0%, #8ba4f9 100%);
    border-radius: 22px;}   
    </style>       
`}
    }