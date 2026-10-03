# AGENTS.md

Tento repozitar (`clearn`) slouzi k vyuce jazyka C (task 53).
Cil: jednoduche, male priklady po lekcich, ktere jdou rychle zkompilovat a spustit.

## Struktura projektu

- Koreni konfigurace je v `CMakeLists.txt` (jazyk C, standard C17, prisne warningy).
- Lekce jsou ve slozce `lekce/NN-nazev/`.
- Kazda lekce ma vlastni `CMakeLists.txt` a pridava spustitelne soubory pres `add_executable(...)`.
- Nova lekce se zapojuje v korenovem `CMakeLists.txt` pres `add_subdirectory(...)`.

## Jak pracovat pri upravach

- Drz zmeny male a lokalni (idealne jedna lekce = jedna zmena).
- Pri pridani noveho prikladu:
  1. vytvor `*.c` soubor ve spravne lekci,
  2. pridej target do `lekce/.../CMakeLists.txt`,
  3. over, ze je lekce zahrnuta v korenovem `CMakeLists.txt`.
- Zachovej C17 kompatibilitu (`set(CMAKE_C_STANDARD 17)`).

## Build a overeni

- Hlavni workflow je CLion (cmake-build-* adresare).
- Pro MSVC pres presety pouzij:
  - `cmake --preset debug`
  - `cmake --build --preset debug`
- Po zmene vzdy over, ze se projekt zkompiluje bez novych warningu.

## Konvence v kodu

- Preferuj citelny vyukovy kod pred "chytrymi" zkratkami.
- Pouzivej jednoduche nazvy funkci a promennych, ktere popisuji ucel prikladu.
- Nepridavej externi knihovny; zustan u standardni knihovny C, pokud neni duvod jinak.

## Kontext k tasku

- Sylabus je mimo repo v `%OneDrive%\Tasks\5-Uceni\53-C Learn\sylabus.md`.
- Tento soubor (`AGENTS.md`) ma pomahat AI agentum drzet se vyukoveho zameru repozitare.

