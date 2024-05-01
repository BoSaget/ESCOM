:: Programa hecho por: Leon Francisco Tejeda Moyao
:: Sistemas Operativos Grupo 4CV2
:: Practica 1: "Suma, resta, multiplicación y división"
@echo off
setlocal enabledelayedexpansion
goto Menu


::----------------------------------------------------------------
::Se realiza un menú para ver que es lo que quiere ingresar el usuasio
:Menu
echo "Seleccione una opción"
echo "1- Suma"
echo "2- Resta"
echo "3- Multiplicación"
echo "4- División"
echo "5- Salir"

set /p "opcion="
if "%opcion%"=="1" goto Suma
if "%opcion%"=="2" goto Resta
if "%opcion%"=="3" goto Multiplicacion
if "%opcion%"=="4" goto Division
if "%opcion%"=="5" goto Salir


::----------------------------------------------------------------
:Suma
:: Se limpia pantalla y se indica la opción de manú en la que se encuentra 
cls
echo "---SUMA---"

::Se crean las variables para realizar la suma
set /p "num1= Ingrese el valor del primer numero: "
set /P "num2= ingrese el valor del segundo numero:"
for /f %%i in ('powershell "([float]!num1!) + ([float]!num2!)"') do set "suma=%%i"

:: Se imprimen los resultados de la opración
echo %suma%

goto Menu


::----------------------------------------------------------------
:Resta
:: Se limpia pantalla y se indica la opción de manú en la que se encuentra 
cls
echo "---RESTA---"

::Se crean las variables para realizar la resta
set /p "num1= Ingrese el valor del primer numero: "
set /P "num2= ingrese el valor del segundo numero:"

for /f %%i in ('powershell "([float]!num1!) - ([float]!num2!)"') do set "resta1=%%i"
for /f %%i in ('powershell "([float]!num2!) - ([float]!num1!)"') do set "resta2=%%i"

:: Se imprimen los resultados de la opración
echo %resta1%
echo %resta2%

goto Menu


::----------------------------------------------------------------
:Multiplicacion
:: Se limpia pantalla y se indica la opción de manú en la que se encuentra 
cls
echo "---MULTIPLICACIÓN---"

::Se crean las variables para realizar la multiplicacion
set /p "num1= Ingrese el valor del primer numero: "
set /P "num2= ingrese el valor del segundo numero:"
for /f %%i in ('powershell "([float]!num1!) * ([float]!num2!)"') do set "mult=%%i"

echo %mult%

goto Menu


::----------------------------------------------------------------
:Division
:: Se limpia pantalla y se indica la opción de manú en la que se encuentra 
cls
echo "---DIVISIÓN---"

::Se crean las variables para realizar la división
set /p "num1= Ingrese el valor del primer numero: "
set /P "num2= ingrese el valor del segundo numero:"

if "%num2%"=="0" goto Error

for /f %%i in ('powershell "([float]!num1!) / ([float]!num2!)"') do set "div=%%i"

echo %div%

goto Menu


::----------------------------------------------------------------
:Error
echo "No se puede dividir entre 0, favor de ingresar un nuevo numero"
PAUSE
goto Division

::----------------------------------------------------------------
:Salir
echo "Saliendo"
endlocal
