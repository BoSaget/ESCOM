%EJercicio 4 de la practica 2
%Alumno: Leon Francisco Tejeda Moyao
%Paradigmas de Programacion: 3CV2

esPrimo(2).
esPrimo(3).
esPrimo(X) :-
    integer(X),
    X > 3,
    X mod 2 =\= 0,
    \+ divisible(X, 3). %Se inicia con 3 debido a que en la linea de arriba se verificó que no fuera un numero par


divisible(X, D) :-
    X mod D =:= 0. %Se checa que el residuo de X/D sea diferente de 0
divisible(X, D) :-
    D * D < X,
    D1 is D + 2, %Se suma de 2 en 2, debido a que solo checa los números impares
    divisible(X, D1).