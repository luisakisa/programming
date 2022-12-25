console.log('Log:Exporting template for x-rable');

export default function(vm)

{return `  
<link rel="stylesheet" href="./style/style.css">
<div class="table">
<div class="table-header">
    <div class="header__item">
        <th id="name" class="filter__link" href="#">Name</th>
    </div>
    <div class="header__item">
        <th id="wins" class="filter__link filter__link--number" href="#">Parametrs</th>
    </div>
    <div class="header__item">
        <th id="total" class="filter__link filter__link--number" href="#">Total</a>
    </div>
</div>
<div class="table-content">
${vm.empty}
</div>
<div class="table-buttons">
    ${vm.buttonback}
    <input type="button" id=${vm.id} value=${vm.x_value}></td>
</div>    
`}
