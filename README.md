# Projet d'initiation à la programmation C++

## Installation des librairies :
```
sudo apt-get install libsdl2-image-dev
sudo apt-get install libsdl2-mixer-dev
sudo apt-get install libsdl2-ttf-dev
```
```
cd SDL2-2.0.20/
./configure
make all
sudo make install
```
## Compilation + lancement :
```
g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include && mkdir -p bin/release && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
```
```
cd bin/release && ./main
```
## Se mettre à jour avant une session :
git fetch - récupérer toutes les branches en local
git pull origin [branche] - mettre à jour la branche par rapport à origin