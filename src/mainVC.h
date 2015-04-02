#pragma once

#include "onut.h"
using namespace onut;

class MainVC
{
public:
    MainVC();

    void update();
    void render();

public:
    UIContext m_uiContext;
    UIControl m_uiScreen;

    UIControl* m_pMainView;
};
