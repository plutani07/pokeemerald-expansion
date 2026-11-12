// Astoria ROM hack: story-specific hooks kept in one file so upstream merges stay simple.
#include "global.h"
#include "astoria.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "pokemon.h"
#include "script.h"
#include "string_util.h"
#include "task.h"
#include "constants/rgb.h"
#include "constants/species.h"

static const u8 sText_PlayerName[] = _("KANI");
static const u8 sText_RivalName[]  = _("BLUE");
static const u8 sText_Wasabi[]     = _("WASABI");

static void CB2_AstoriaNewGame(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_AstoriaNewGame(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    // The game is Kani's story: no Oak speech, no naming screen.
    gSaveBlock2Ptr->playerGender = MALE;
    StringCopy(gSaveBlock2Ptr->playerName, sText_PlayerName);
    StringCopy(gSaveBlock1Ptr->rivalName, sText_RivalName);

    DestroyTask(taskId);
    SetMainCallback2(CB2_NewGame);
}

void StartAstoriaNewGame(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_AstoriaNewGame, 0);
    SetMainCallback2(CB2_AstoriaNewGame);
}

// callnative: gives the most recently added Bulbasaur in the party the nickname WASABI.
void Astoria_NicknameWasabi(struct ScriptContext *ctx)
{
    s32 i;

    for (i = gPlayerPartyCount - 1; i >= 0; i--)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) == SPECIES_BULBASAUR)
        {
            SetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, sText_Wasabi);
            break;
        }
    }
}
