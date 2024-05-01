%EJercicio 2 de la practica 2
%Alumno: Leon Francisco Tejeda Moyao
%Paradigmas de Programacion: 3CV2

mujer(pilar).
mujer(belen).
mujer(lucia).
mujer(ana).
mujer(maria).

hombre(tomas).
hombre(pedro).
hombre(jose).

progenitor(belen, pedro).
progenitor(ana, belen).

%Punto A
esMadre(A, B):- %A es madre de B si
    mujer(A), %A es mujer
    progenitor(A, B). %A es progenitor
    
%Punto B
esMadre(belen, pedro). %Belen es madre de pedro?

%Punto C
esMadre(A, belen). %Quien es la madre de Belen?

%Punto D
esMadre(A, maria). %Quien es la madre de Maria?

%Punto E
esMadre(Ana, X). %Ana de quien es madre?