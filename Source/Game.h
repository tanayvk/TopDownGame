#include <SDL.h>
#include <vector>

class Game {
public:
  Game();
  bool Initialize();
  void Loop();
  void CleanUp();

 	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

  bool IsRunning() { return AmIRunning; }

  class Renderer* GetRenderer() { return renderer; }
private:
  void ProcessInput();
  void Update();
  void Render();

  int ticksCount;
  bool AmIRunning;

	std::vector<class Actor*> actors;
	std::vector<class SpriteComponent*> sprites;
 
  class Renderer* renderer;

  // SDL
  bool SDLIsInitialized;
  SDL_Window* window;
};
