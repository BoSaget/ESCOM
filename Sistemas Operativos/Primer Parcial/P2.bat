:: Programa hecho por: Leon Francisco Tejeda Moyao
:: Sistemas Operativos Grupo 4CV2
:: Practica 2: "Máximo, Minimo y Promedio"
@echo off
:: enabledelayedexpansion Habilita el entorno para que el programa se ejecute hasta encontrar un endlocal
setlocal enabledelayedexpansion

::Se le pide al usuario ingresar un valor, este es el largo del arreglo
set /p "largo=Ingrese el largo del arreglo: "

:: Se inicializa el arreglo
set "arreglo="

:: Se inicializan las variables
set "min="
set "max="
set "sum=0"

:: Se rellena el valor del arreglo con numeros aleatorios de entre 0 y 99
for /l %%i in (1, 1, %largo%) do (
    set /a "valor=!random! %% 100 + 1"
    set "arreglo=!arreglo! !valor!"
)

:: Se imprime el arrelgo generado
echo El arreglo resultante fue:
echo %arreglo%

::Se separan los numeros del arreglo
for %%i in (%arreglo%) do (
    set "numero=%%i"
    
    ::Se van actualizando los valores de máximo y minimo.
    if not defined min (set "min=!numero!") else if !numero! lss !min! set "min=!numero!"
    if not defined max (set "max=!numero!") else if !numero! gtr !max! set "max=!numero!"
    
    ::Se va haciendo una suma para al final realizar el promedio
    set /a "sum+=numero"
)

::Se calcula el promedio
set /a "prom=sum / largo"

:: Se procede a mostrar los resultados
echo El valor Minimo fue: %min%
echo El valor Máximo fue: %max%
echo El promeido fue: %prom%

endlocal
