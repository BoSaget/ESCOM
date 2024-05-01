$(document).ready(function(){
    $('.dropdown-trigger').dropdown();
    $('.sidenav').sidenav();
    $('.slider').slider();
    $("form#login").validetta({
      bubblePosition:"bottom",
      bubbleGapTop: 5,
      bubbleGapLeft: -1,
      realTime: true,
      onValid:function(e){
        e.preventDefault();
        $.ajax({
          url:"login.php",
          method:"post",
          data:$("form#login").serialize(),
          cache:false,
          success:function(respAX){
            let AX = JSON.parse(respAX);
            let tipo;
            if(AX.codigo != 1)
              tipo = "grey"; 
            else 
              tipo = "white";
            
            $.alert({
              theme: "dark",
              title:"<h3>Mensaje</h3>",
              content:AX.msj,
              type:tipo,
              icon:"fas fa-info-circle fa-2x",
              boxWidth: "50%",
              useBootstrap: false,
              onDestroy:function(){
                if(AX.codigo == -1)
                  window.location.href = "./admin/adminindex.php";
                else if(AX.codigo == 1)
                  window.location.href = "./login/loginindex.php";
              }
            });
          }
        });
      }
    });
  });