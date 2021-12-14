# chess-core
Библиотека для создания виртуальных шахмат

## Что-где
В /include лежит программный интерфейс библиотеки  
В /source лежит реализация библиотеки  
В /test лежат тесты

## Про интерфейс
Главные классы:
- core::board::board - интерфейс управления шахматной партией
- core::board::position - шахматная диаграмма (местный аналог FEN)
- core::board::player - интерфейс программного игрока

## Про реализацию
...

## Про тесты
...

## Пример использования библиотеки
```
#include <iostream>

#include "core/game/game.hpp"
#include "core/player/ai.hpp"
#include "core/player/dummy.hpp"

int main(int argc, char const *argv[])
{
    auto white = core::player::ai();
    auto black = core::player::dummy();
    auto game = core::game::game();

    while (!game.finished())
    {
        game.turn(white.bestmove(game.position()));
        game.turn(black.bestmove(game.position()));
    }

    std::cout << "and the winner is... " << (int) game.winner() << std::endl;

    return 0;
}
```
