#include "MainVC.h"
#include "styles.h"
#include "resTexture.h"

using namespace std;

static const Color g_guideColor = OColorHex(3399ff);
static const Color g_toolBtnHoverColor = OColorHex(3e3e40);
static const Color g_toolBtnDownColor = OColorHex(007acc);

MainVC::MainVC()
    : m_uiContext({(float)OSettings->getResolution().x, (float)OSettings->getResolution().y})
    , m_uiScreen("../../assets/ui/main.json")
{
    // create UI styles
    createUIStyles(&m_uiContext);

    // create UI styles
    m_uiContext.addStyle<UICheckBox>("selectBox", [this](const onut::UICheckBox* pCheckBox, const onut::sUIRect& rect)
    {
        auto state = pCheckBox->getState(m_uiContext);
        auto orect = UI2Onut(rect);
        switch (state)
        {
            case eUIState::HOVER:
                OSB->drawRect(nullptr, orect, g_toolBtnHoverColor);
                break;
            case eUIState::DOWN:
                OSB->drawRect(nullptr, orect, g_toolBtnDownColor);
                break;
        }
        if (pCheckBox->getIsChecked())
        {
            OSB->drawRect(nullptr, orect, g_guideColor);
        }
    });

    // We set stuff manually because the UI Editor is far from complete
    auto pTxtImgW = m_uiScreen.getChild<UITextBox>("txtImgW");
    pTxtImgW->setIsNumerical(true);
    pTxtImgW->setIsDecimalPrecision(0);
    auto pTxtImgH = m_uiScreen.getChild<UITextBox>("txtImgH");
    pTxtImgH->setIsNumerical(true);
    pTxtImgH->setIsDecimalPrecision(0);
    auto pChkTextureCmd = m_uiScreen.getChild<UICheckBox>("chkTextureCmd");
    pChkTextureCmd->behavior = eUICheckBehavior::CHK_OPTIONAL;

    // Hide the texture inspector area
    m_pMainView = m_uiScreen.getChild("mainView");
}

void MainVC::update()
{
    m_uiScreen.update(m_uiContext, {OMousePos.x, OMousePos.y}, OInput->isStateDown(DIK_MOUSEB1));
}

void MainVC::render()
{
    OSB->begin();
    m_uiScreen.render(m_uiContext);
    OSB->end();
}
