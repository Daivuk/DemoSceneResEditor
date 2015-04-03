#pragma once
#include "onut.h"
using namespace std;
using namespace onut;

enum eRES_CMD : uint8_t
{
    RES_IMG,
    RES_FILL,
    RES_RECT,
    RES_BEVEL,
    RES_CIRCLE,
    RES_BEVEL_CIRCLE,
    RES_LINE,
    RES_GRADIENT,
    RES_NORMAL_MAP,
    RES_IMG_END,

    RES_MESH,
    RES_QUAD,
    RES_MESH_END,

    RES_MODEL,
    RES_CAMERA,
    RES_EMITTER,
    RES_LIGHT,
    RES_SPOT_LIGHT,
    RES_SUN_LIGHT,
    RES_AMBIENT
};

class sTextureCmd
{
public:
    virtual ~sTextureCmd() {}
    struct sTexture* texture = nullptr;
};

class sTextureCmdFILL : public sTextureCmd
{
public:
    Color color = Color::White;
};

class sTextureCmdRECT : public sTextureCmd
{
public:
    Color color = Color::White;
    int x = 0, y = 0, w = 16, h = 16;
};

class sTextureCmdBEVEL : public sTextureCmd
{
public:
    Color color = Color::Black;
    int x = 0, y = 0, w = 16, h = 16;
    int bevel;
};

class sTextureCmdCIRCLE : public sTextureCmd
{
public:
    Color color = Color::White;
    int x = 0, y = 0;
    int radius;
};

class sTextureCmdBEVEL_CIRCLE : public sTextureCmd
{
public:
    Color color = Color::White;
    int x = 0, y = 0;
    int radius = 20;
    int bevel = 3;
};

class sTextureCmdLINE : public sTextureCmd
{
public:
    Color color = Color::White;
    int x1 = 0, y1 = 8, x2 = 16, y2 = 8;
    int size = 3;
};

class sTextureCmdGRADIENT : public sTextureCmd
{
public:
    Color color1 = Color::White, color2 = Color::Black;
    int x = 0, y = 0, w = 16, h = 16;
    bool bVertical;
};

class sTextureCmdNORMAL_MAP : public sTextureCmd
{
public:
};

struct sTexture
{
    Texture* texture = nullptr;
    int w = 256, h = 256;
    vector<sTextureCmd*> cmds;
};

extern vector<sTexture*> res_textures;
