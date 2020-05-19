#include <SDL.h>
#include <map>
#include <string>
class Renderer {
    friend class Game;
public:
    void DrawTexture(std::string textureId, int x, int y, int w, int h);
    void AddTexture(std::string textureId, std::string textureFilePath);
    void QueryTexture(std::string textureId, int* texWidth, int* texHeight);

private:
    SDL_Renderer* SDLRenderer;
    std::map<std::string, SDL_Texture*> textures;

    SDL_Texture* LoadTextureFromImageFile(std::string imageFilePath);

    bool Initialize(SDL_Window* window);
    void CleanUp();

};