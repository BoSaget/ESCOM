%EJercicio 1 de la practica 2
%Alumno: Leon Francisco Tejeda Moyao
%Paradigmas de Programacion: 3CV2

padreDe(juan, maria). %Juan es padre de María
padreDe(pablo, juan). %Pablo es padre de Juan
padreDe(pablo, marcela). %Pablo es padre de Marcela
padreDe(carlos, débora). %Carlos es padre de Débora

esHermano(A, B):- %A es hermano de B si
    A\=B,
    padreDe(C,A), %C es el padre de A
    padreDe(C,B). %Y C es el padre de B