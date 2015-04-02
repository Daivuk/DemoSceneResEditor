#include <Windows.h>
#include "onut.h"
#include "texturesVC.h"
#include "mainVC.h"

enum class eState
{
    MAIN_MENU,
    TEXTURES
};

eState g_state = eState::TEXTURES;

TexturesVC* pTextureVC;
MainVC* pMainVC;

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
        pMainVC = new MainVC();
        pTextureVC = new TexturesVC();

        OWindow->onWrite = [](char c){pMainVC->m_uiContext.write(c); };
        OWindow->onKey = [](uintptr_t key)
        {
            //if (!g_pDocument->isBusy())
            {
                pMainVC->m_uiContext.keyDown(key);
                //if (!dynamic_cast<onut::UITextBox*>(pMainVC->m_uiContext.getFocusControl()))
                //{
                //    //checkShortCut(key);
                //    g_pDocument->onKeyDown(key);
                //}
            }
        };
    },
        []
    {
        pMainVC->m_uiContext.resize({OScreenWf, OScreenHf});

        switch (g_state)
        {
            case eState::TEXTURES: pMainVC->update(); break;
        }
    },
        []
    {
        ORenderer->clear(Color::Black);
        switch (g_state)
        {
            case eState::TEXTURES: pMainVC->render(); break;
        }
    });
}
