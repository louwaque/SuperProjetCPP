# SuperProjetCPP

[![Build Status](https://travis-ci.org/L0L022/SuperProjetCPP.svg?branch=master)](https://travis-ci.org/L0L022/SuperProjetCPP)

Projet C++ 2017 sur le dessin de formes

## Documentation

La doc est disponible sur ce [site](https://l0l022.github.io/SuperProjetCPP/html/) ou peut être généré à l'aide de la commande ```make doc```.

## Sources

Les sources sont disponibles [ici](https://github.com/L0L022/SuperProjetCPP).

## Dépendances

Compilateur compatible c++17
- Pour avoir l’exception std::bad_weak_ptr, [explication](http://en.cppreference.com/w/cpp/memory/enable_shared_from_this/shared_from_this).

[CMake 3.8.2](https://cmake.org/files/v3.8/)
- Pour avoir : set (CMAKE_CXX_STANDARD 17)

[BOOST 1.64.0](http://www.boost.org/users/history/version_1_64_0.html) avec :
- signal2 : signaux dans les widgets
- locale : conversion UTF-8 <-> Latin-1 et itération dans une chaine UTF-8
- serialization : pour la sauvegarde (pas fait)
- test : tests unitaires

## Compilation

Dans les sources du projet exécutez :
```
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make app
```
