# cpp-crypto-hack-exercises

Structura proiectului este organizata pe exercitii independente, plus un `include` comun pentru cod reutilizabil.

## Structura recomandata

```text
.
├── CMakeLists.txt                # orchestrator principal
├── include/
│   └── common/                   # cod reutilizabil pentru toate exercitiile
├── exercises/
│   ├── CMakeLists.txt            # include fiecare exercitiu
│   ├── exercise01/
│   │   ├── CMakeLists.txt
│   │   ├── include/exercise01/
│   │   ├── src/
│   │   └── tests/
│   └── exercise02/               # urmatorul exercitiu
│       ├── CMakeLists.txt
│       ├── include/exercise02/
│       ├── src/
│       └── tests/
└── build/
```

## Cum adaugi un exercitiu nou

1. Copiaza folderul `exercises/exercise01` in `exercises/exercise02`.
2. In `exercises/exercise02/CMakeLists.txt`, schimba `EXERCISE_NAME` in `exercise02`.
3. Adauga `add_subdirectory(exercise02)` in `exercises/CMakeLists.txt`.
4. Ruleaza configurare/build din nou.

## Include comun pentru toate exercitiile

Orice header din `include/common` este disponibil in orice exercitiu prin:

```cpp
#include "common/nume_header.hpp"
```

Acest lucru este facut prin target-ul `common_headers` definit in CMake-ul principal.