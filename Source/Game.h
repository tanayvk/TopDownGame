#include <SDL.h>

class Game {
public:
  Game();
  bool Initialize();
  void Loop();
  void CleanUp();

  bool IsRunning() { return AmIRunning; }
private:
  void ProcessInput();
  void Update();
  void Render();

  bool AmIRunning;

  // SDL
  bool SDLIsInitialized;
  SDL_Window* window;
  SDL_Renderer* renderer;
  //SDL_Texture* hello;
};
