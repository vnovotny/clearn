# CLearn

Cvičný repozitář ke studiu jazyka C (task 53, sylabus v `%OneDrive%\Tasks\5-Učení\53-C Learn\sylabus.md`).

- Hlavní IDE: **CLion** (File → Open → tahle složka; výchozí toolchain = bundled MinGW-w64 GCC, profily Debug/Release si CLion vytvoří sám v `cmake-build-*`).
- Volitelně MSVC: `CMakePresets.json` (Ninja + `cl`) z Developer PowerShell for VS: `cmake --preset debug` a `cmake --build --preset debug`; v CLionu lze jako toolchain zvolit i Visual Studio.
- Každá lekce = složka `lekce/NN-nazev/` s vlastním `CMakeLists.txt`, přidaná přes `add_subdirectory` v kořeni.
