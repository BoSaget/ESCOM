$(document).ready(function(){
    $(".fas").mouseover(function(){
        $(this).css("cursor","pointer");
    });

    $(".editar").click(function(){
        let producto = $(this).attr("data-producto");
        $.ajax({
            url:"./gmenuEditar.php",
            method:"post",
            data:{producto:producto},
            cache:false,
            success:function(respAX){
                alert(respAX);
            }
        });
    });

    $(".eliminar").click(function(){
        let producto = $(this).attr("data-producto");
        $.confirm({
            theme: "dark",
            title: 'Borrar',
            content: '¿Está seguro de eliminar este producto?',
            buttons: {
                Si: function () {
                    $.ajax({
                        url:"./gmenuEliminar.php",
                        method:"post",
                        data:{producto:producto},
                        cache:false,
                        success:function(respAX){
                            alert(respAX);
                        }
                    });
                },
                No: function () {
                },
            }
        });
    });
});