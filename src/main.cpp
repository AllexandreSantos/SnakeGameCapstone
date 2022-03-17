#include <iostream>
#include <fstream>  
#include <chrono>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "stats.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Stats stats(0, 0, 0);

  auto startGameTime = std::chrono::system_clock::now();

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;

  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

  auto endGameTime = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsedSeconds = endGameTime-startGameTime;
  stats = Stats(game.GetSize(), game.GetScore(), elapsedSeconds.count());
  stats.GenerateStatsFile();
 
  return 0;
}
