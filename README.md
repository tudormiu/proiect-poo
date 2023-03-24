# Sokoban


Sokoban (倉庫番, Sōko-ban, lit.'warehouse keeper') is a puzzle 
video game in which the player pushes boxes around in a warehouse,
trying to get them to storage locations. The game was designed in
1981 by Hiroyuki Imabayashi, and first published in December 1982.
[ <sup>[1]</sup> ](https://en.wikipedia.org/wiki/Sokoban)

### Gameplay

The game is played on a board of squares, where each square is a
floor or a wall. Some floor squares contain boxes, and some floor
squares are marked as storage locations.

The player is confined to the board and may move horizontally or
vertically onto empty squares (never through walls or boxes). The
player can move a box by walking up to it and push it to the
square beyond. Boxes cannot be pulled, and they cannot be pushed
to squares with walls or other boxes. The number of boxes equals
the number of storage locations. The puzzle is solved when all 
boxes are placed at storage locations.
<sup> [[2]](https://en.wikipedia.org/wiki/Sokoban#Gameplay) </sup>

### Movement

You can move the player using the 'w', 'a', 's', 'd' keys.
The player can move only one square at a time.

In this stage of the project, inputs can be given using the 
"tastatura.txt" file.

### Current state of the project:

The player can move around the board. Collisions with walls and
the edges of the board are handled.

There are no boxes yet and no grpaics. In order to test the
movement of the player, the board is printed to the console.

In order to better understand the movement of the player, in case
of a collision, the player is not moved and, along with the board,
a message is printed to the console.

After the game is stopped, a window will open. It doesn't have
any functionality yet, but it will be used to display the
current state of the game.

---

# OOP Template

### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim 3-4 clase folosind compunere
- [x] constructori de inițializare
- [x] pentru o clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru toate clasele pentru afișare (std::ostream)
- [x] cât mai multe `const` (unde este cazul)
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități specifice temei alese
- [x] scenariu de utilizare a claselor definite:
  - crearea de obiecte și apelarea funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` exemple de date de intrare de la tastatură (dacă există)
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI); exemplu: GitHub Actions

## Tema 2

#### Cerințe
- [ ] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [ ] moșteniri
  - [ ] clasă cu atribut de tip pointer la o clasă de bază cu derivate
  - [ ] funcții virtuale (pure) apelate prin pointeri de bază din clasa de mai sus, constructori virtuali (clone)
    - minim o funcție virtuală va fi **specifică temei** (e.g. nu simple citiri/afișări)
  - [ ] apelarea constructorului din clasa de bază din constructori din derivate
  - [ ] smart pointers
  - [ ] `dynamic_cast`
- [ ] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
- [ ] excepții
  - [ ] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim 2 clase pentru erori specifice
  - [ ] utilizare cu sens: de exemplu, `throw` în constructor, `try`/`catch` în `main`
- [ ] funcții și atribute `static`
- [ ] STL
- [ ] cât mai multe `const`
- [ ] la sfârșit: commit separat cu adăugarea unei noi derivate fără a modifica restul codului
- [ ] tag de `git`: de exemplu `v0.2`

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] o clasă șablon cu sens; minim 2 instanțieri
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git`: de exemplu `v0.3` sau `v1.0`

## Resurse

- adăugați trimiteri către resursele externe care v-au ajutat sau pe care le-ați folosit