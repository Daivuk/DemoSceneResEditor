#include <Windows.h>
#include "onut.h"
#include "texturesVC.h"

enum class eState
{
    MAIN_MENU,
    TEXTURES
};

eState g_state = eState::TEXTURES;

TexturesVC* pTextureVC;

int CALLBACK WinMain(
    _In_  HINSTANCE hInstance,
    _In_  HINSTANCE hPrevInstance,
    _In_  LPSTR lpCmdLine,
    _In_  int nCmdShow
    )
{
    OSettings->setGameName("Demo Scene Resources Editor");
    OSettings->setResolution({1024, 600});

    onut::run([]
    {
        pTextureVC = new TexturesVC();
    },
        []
    {
        switch (g_state)
        {
            case eState::TEXTURES: pTextureVC->update(); break;
        }
    },
        []
    {
        ORenderer->clear(Color::Black);
        switch (g_state)
        {
            case eState::TEXTURES: pTextureVC->render(); break;
        }
    });
}
