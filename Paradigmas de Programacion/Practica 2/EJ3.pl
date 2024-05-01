%EJercicio 3 de la practica 2
%Alumno: Leon Francisco Tejeda Moyao
%Paradigmas de Programacion: 3CV2

%Punto A
mujer(matilde).
mujer(vanda).
mujer(marcella).
mujer(alexandra).
mujer(bibi).
mujer(aracely).
mujer(stephanie).
mujer(isabella).
mujer(michelle).

hombre(rafael_key).
hombre(sergio).
hombre(luis_gallego).
hombre(alejandro).
hombre(sergio2).
hombre(luis_miguel).
hombre(alexander).
hombre(miguel).
hombre(daniel).

%Punto B
%A es padre de B
padreDe(rafael_key, luis_gallego).
padreDe(sergio, marcella).
padreDe(luis_gallego, alejandro).
padreDe(luis_gallego, sergio2).
padreDe(luis_gallego, luis_miguel).
padreDe(alejandro, isabella).
padreDe(alejandro, alexander).
padreDe(luis_miguel, miguel).
padreDe(luis_miguel, daniel).
padreDe(luis_miguel, michelle).

%A es madre de B
madreDe(matilde, luis_gallego).
madreDe(vanda, marcella).
madreDe(marcella, alejandro).
madreDe(marcella, sergio2).
madreDe(marcella, luis_miguel).
madreDe(alexandra, isabella).
madreDe(bibi, alexander).
madreDe(aracely, miguel).
madreDe(aracely, daniel).
madreDe(stephanie, michelle).

%A es conyuge actual de B
conyugeDe(rafael_key, matilde).
conyugeDe(matilde, rafael_key).
conyugeDe(sergio, vanda).
conyugeDe(vanda, sergio).
conyugeDe(alejandro, bibi).
conyugeDe(bibi, alejandro).
conyugeDe(luis_miguel, aracely).
conyugeDe(aracely, luis_miguel).

%A es progetinor de B
progenitorDe(rafael_key, luis_gallego).
progenitorDe(sergio, marcella).
progenitorDe(luis_gallego, alejandro).
progenitorDe(luis_gallego, sergio2).
progenitorDe(luis_gallego, luis_miguel).
progenitorDe(alejandro, isabella).
progenitorDe(alejandro, alexander).
progenitorDe(luis_miguel, miguel).
progenitorDe(luis_miguel, daniel).
progenitorDe(luis_miguel, michelle).
progenitorDe(matilde, luis_gallego).
progenitorDe(vanda, marcella).
progenitorDe(marcella, alejandro).
progenitorDe(marcella, sergio2).
progenitorDe(marcella, luis_miguel).
progenitorDe(alexandra, isabella).
progenitorDe(bibi, alexander).
progenitorDe(aracely, miguel).
progenitorDe(aracely, daniel).
progenitorDe(stephanie, michelle).

%A es hijo de B
hijoDe(luis_gallego, rafael_key).
hijoDe(luis_gallego, matilde).
hijoDe(alejandro, luis_gallego).
hijoDe(alejandro, marcella).
hijoDe(sergio2, luis_gallego).
hijoDe(sergio2, marcella).
hijoDe(luis_miguel, luis_gallego).
hijoDe(luis_miguel, marcella).
hijoDe(alexander, bibi).
hijoDe(alexander, alexandra).
hijoDe(miguel, luis_miguel).
hijoDe(miguel, aracely).
hijoDe(daniel, luis_miguel).
hijoDe(daniel, aracely).

%A es hija de B
hijaDe(marcella, sergio).
hijaDe(marcella, vanda).
hijaDe(isabella, alexandra).
hijaDe(isabella, alejandro).
hijaDe(michelle, luis_miguel).
hijaDe(michelle, stephanie).

%Punto C
abueloDe(A, B):- %A es abuelo de B
    hombre(A),
    padreDe(C, B), padreDe(A, C); %El padre C de B tiene un padre A
    madreDe(C, B), padreDe(A, C). %La madre C de B tiene un padre A

abuelaDe(A, B):- %A es abuela de B
    mujer(A),
    padreDe(C, B), madreDe(A, C); %El padre C de B tiene una madre A
    madreDe(C, B), madreDe(A, C). %La madre C de B tiene una madre A

%NOTA: NO admite medios hermanos, para que admita se deberá cambiar a operador OR (;)
hermanoDe(A, B):- %A es hermano de B
    hombre(A),
    A\=B, %A tiene que ser diferente de B
    padreDe(P, A), %P es el padre de A
    padreDe(P, B), %P es el padre de B
    madreDe(M, A), %M es la madre de A
    madreDe(M, B). %M es la madre de B

hermanaDe(A, B):- %A es hermana de B
    mujer(A),
    A\=B, %A tiene que ser diferente de B
    padreDe(P, A), %P es el padre de A
    padreDe(P, B), %P es el padre de B
    madreDe(M, A), %M es la madre de A
    madreDe(M, B). %M es la madre de B

primoDe(A, B):- %A es primo de B
    hombre(A),
    padreDe(P1, A), padreDe(P2, B), hermanoDe(P1, P2); %Si el padre P1 de A y el padre P2 de B y P1 es hermano de P2
    padreDe(P1, A), madreDe(M2, B), hermanoDe(P1, M2); %Si el padre P1 de A y la madre M1 de B y P1 es hermano de M2
    madreDe(M1, A), padreDe(P2, B), hermanaDe(M1, P2); %Si la madre M1 de A y el padre P2 de B y M1 es hermana de P2
    madreDe(M1, A), madreDe(M2, B), hermanaDe(M1, M2). %Si la madre M1 de A y la madre M2 de B y M1 es hermana de M2

primaDe(A, B):- %A prima de B
    mujer(A),
    padreDe(P1, A), padreDe(P2, B), hermanoDe(P1, P2); %Si el padre P1 de A y el padre P2 de B y P1 es hermano de P2
    padreDe(P1, A), madreDe(M2, B), hermanoDe(P1, M2); %Si el padre P1 de A y la madre M1 de B y P1 es hermano de M2
    madreDe(M1, A), padreDe(P2, B), hermanaDe(M1, P2); %Si la madre M1 de A y el padre P2 de B y M1 es hermana de P2
    madreDe(M1, A), madreDe(M2, B), hermanaDe(M1, M2). %Si la madre M1 de A y la madre M2 de B y M1 es hermana de M2

tioDe(A, B):- %A es tio de B
    hombre(A),
    hermanoDe(H, A), padreDe(H, B); %Si el hermano A de H es padre de un hijo B
    hermanoDe(H, A), madreDe(H, B); %Si el hermano A de H es madre de una hija B
    hermanaDe(H, A), padreDe(H, B); %Si la hermana A de H es padre tiene un hijo B
    hermanaDe(H, A), madreDe(H, B). %Si la hermana A de H es madre de  una hija B

tiaDe(A, B):- %A es tia de B
    mujer(A),
    hermanoDe(H, A), padreDe(H, B); %Si el hermano A de H es padre de un hijo B
    hermanoDe(H, A), madreDe(H, B); %Si el hermano A de H es madre de una hija B
    hermanaDe(H, A), padreDe(H, B); %Si la hermana A de H es padre tiene un hijo B
    hermanaDe(H, A), madreDe(H, B). %Si la hermana A de H es madre de  una hija B

descendienteDe(A, B):- %A es descendiente de B
    padreDe(B, A). %B es padre de A
descendienteDe(A, B):- %A es descendiente de B
    padreDe(P, A), descendienteDe(B, P); %Si el padre P de A es descendiente de B
    madreDe(M, A), descendienteDe(B, M); %Si la madre M de A es descendiente de B
    abueloDe(P, A), descendienteDe(B, P); %Si el abuelo P de A es descendiente de B
    abuelaDe(M, A), descendienteDe(B, M); %Si la abueña M de A es descendiente de B
    hermanoDe(P, A), descendienteDe(B, P); %Si el hermano P de A es descendiente de B
    hermanoDe(M, A), descendienteDe(B, M); %Si la hermana M de A es descendiente de B
    primoDe(P, A), descendienteDe(B, P); %Si el primo P de A es descendiente de B
    primaDe(M, A), descendienteDe(B, M); %Si la prima M de A es descendiente de B
    tioDe(P, A), descendienteDe(B, P); %Si el tio P de A es descendiente de B
    tiaDe(M, A), descendienteDe(B, M). %Si la tia M de A es descendiente de B

ancestro(X, Y).
ancestro(X, Y):-
    ancestro(Z, Y), progenitorDe(X, Y). progenitorDe(X, Z).