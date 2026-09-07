@echo off
REM Compila o projeto. Rodar a partir da pasta PA:  .\compilar
REM Quando entrar um arquivo .c novo, acrescente a linha dele aqui.

gcc -std=c99 -O2 -Wall -Isrc -o programa.exe ^
    src/app/main.c ^
    src/menu/menu.c ^
    src/gerador/gerador.c ^
    src/algoritmos/algoritmos.c ^
    src/saida/saida.c

if %errorlevel%==0 (
    echo.
    echo Compilado com sucesso: programa.exe
    echo Para rodar:  .\programa
) else (
    echo.
    echo FALHA na compilacao.
)
