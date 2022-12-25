console.log('Log:Exporting template for x-login_input');

export default function(vm) {return ` 
<div class="container">
<p>login</p>
<x-input id="email" type="text"></x-input>
<p>password</p>
<x-input id="password" type="password"></x-input>
<x-input id="enter" type="button" value="enter"></x-input>
<x-input id="error" type="text" ${vm.error} style="color: red; border: none;" disabled=disabled></x-input>

</div>   
<style>.container{
    background-color: rgb(228, 201, 235);
    margin: 150px 600px;
    padding: 70px 50px;
    border-radius: 4px;
    position:fixed;
}
p{
    color: #5e2eaa;
}
</style>
`}