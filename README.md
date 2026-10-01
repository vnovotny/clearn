# CLearn

Cvičný repozitář ke studiu jazyka C (task 53, sylabus v `%OneDrive%\Tasks\5-Učení\53-C Learn\sylabus.md`).

- Otevřít ve Visual Studiu: **File → Open → Folder…** → tahle složka; VS načte `CMakePresets.json` (x64 Debug / Release).
- Z příkazové řádky (Developer PowerShell for VS): `cmake --preset debug` a `cmake --build --preset debug`.
- Každá lekce = složka `lekce/NN-nazev/` s vlastním `CMakeLists.txt`, přidaná přes `add_subdirectory` v kořeni.
