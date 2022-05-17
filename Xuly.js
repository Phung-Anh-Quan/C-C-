var username = document.querySelector('username')
var passwornd = document.querySelector(' passwornd')
var name = document.querySelector('name')
var emaill = document.querySelector('emaill')
var phone = document.querySelector('phone')
var register = document.querySelector('register')


function validate()
{
    var flag = true;
    
    // 1 username
    var username = getValue('username');
    if (username == '' || username.length < 5 || !/^[a-zA-Z0-9]+$/.test(username)){
        flag = false;
        showError('username', 'Vui lòng kiểm tra lại Username');
    }
    
    // 2. password
    var password = getValue('password');
    var repassword = getValue('repassword');
    if (password == '' || password.length < 8 || password != repassword){
        flag = false;
        showError('password', 'Vui lòng kiểm tra lại Password');
    }
    
    // 3. Phone
    //cho phép cut copy paste drag drop trong thẻ input
$(document).ready(function() {
    $('.quantity-input').bind("cut copy paste drag drop", function(e) {
        e.preventDefault();
    });     
  });
  function isNumberKey(e) {
      var charCode = (e.which) ? e.which : e.keyCode;
      if (charCode > 31 && (charCode < 48 || charCode > 57))
          return false;
      return true;
  }
    // 4 .full name
    var name = getValue('name');
    if (name == '' || name.length < 100 || !/^[a-zA-Z]+$/.test(name)){
        flag = false;
        showError('name', 'Vui lòng kiểm tra lại tên');
    }
    // 4. Email
    var email = getValue('email');
    var mailformat = /^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:.[a-zA-Z0-9-]+)*$/;
    if (!mailformat.test(email)){
        flag = false;
        
        showError('phone', 'Vui lòng kiểm tra lại Email');
    }
    
    return flag;
}