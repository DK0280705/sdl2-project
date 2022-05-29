#include "../scene.h"
#include "../texture.h"

class Scene_main : public Scene
{
public:
    Scene_main(class Game* game, int x, int y, int w, int h);
    ~Scene_main();

    Texture ground;
    Texture trees;
    Texture mountains;
    Texture clouds;
    Texture background;

    void update(float delta) override;
};