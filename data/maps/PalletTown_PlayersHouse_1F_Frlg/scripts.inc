PalletTown_PlayersHouse_1F_Frlg_MapScripts::
	.byte 0

PalletTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEAT_RIVAL_IN_OAKS_LAB, PalletTown_PlayersHouse_1F_EventScript_MomHeal
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale
	closemessage
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouMale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomOakLookingForYouFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou
	return

PalletTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare
	release
	end

@ Displays special text if interacted with from side or back (which are normally inaccessible)
PalletTown_PlayersHouse_1F_EventScript_TV::
	lockall
	goto_if_eq VAR_FACING, DIR_NORTH, PalletTown_PlayersHouse_1F_EventScript_TVScreen
	msgbox PalletTown_PlayersHouse_1F_Text_OopsWrongSide
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreen::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenMale
	call_if_eq VAR_RESULT, FEMALE, PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale
	releaseall
	end

PalletTown_PlayersHouse_1F_EventScript_TVScreenMale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad
	return

PalletTown_PlayersHouse_1F_EventScript_TVScreenFemale::
	msgbox PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad
	return

PalletTown_PlayersHouse_1F_Text_AllBoysLeaveOakLookingForYou::
	.string "MOM: …Right.\n"
	.string "All boys leave home someday.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_AllGirlsLeaveOakLookingForYou::
	.string "MOM: …Right.\n"
	.string "All girls dream of traveling.\l"
	.string "It said so on TV.\p"
	.string "Oh, yes. PROF. OAK, next door, was\n"
	.string "looking for you.$"

PalletTown_PlayersHouse_1F_Text_YouShouldTakeQuickRest::
	.string "MOM: {PLAYER}!\n"
	.string "You should take a quick rest.$"

PalletTown_PlayersHouse_1F_Text_LookingGreatTakeCare::
	.string "MOM: Oh, good! You and your\n"
	.string "POKéMON are looking great.\l"
	.string "Take care now!$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVFourBoysOnRailroad::
	.string "There's a movie on TV.\n"
	.string "Four boys are walking on railroad\l"
	.string "tracks.\p"
	.string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_MovieOnTVGirlOnBrickRoad::
	.string "There's a movie on TV.\n"
	.string "A girl with her hair in pigtails is\l"
	.string "walking up a brick road.\p"
	.string "…I better go, too.$"

PalletTown_PlayersHouse_1F_Text_OopsWrongSide::
	.string "Oops, wrong side…$"

@ ---------------------------------------------------------------
@ Astoria first-build test NPCs (placeholder dialogue, replace later)
@ ---------------------------------------------------------------

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestWasabi::
	lock
	faceplayer
	goto_if_set FLAG_ASTORIA_GOT_WASABI, PalletTown_PlayersHouse_1F_EventScript_AstoriaTestWasabiAfter
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestWasabiIntro, MSGBOX_DEFAULT
	givemon SPECIES_BULBASAUR, 5
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, PalletTown_PlayersHouse_1F_EventScript_AstoriaTestWasabiNoRoom
	callnative Astoria_NicknameWasabi
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	message PalletTown_PlayersHouse_1F_Text_AstoriaTestReceivedWasabi
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_ASTORIA_GOT_WASABI
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestWasabiAfter, MSGBOX_DEFAULT
	release
	end

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestWasabiAfter::
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestWasabiAfter, MSGBOX_DEFAULT
	release
	end

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestWasabiNoRoom::
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestNoRoom, MSGBOX_DEFAULT
	release
	end

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestMoney::
	lock
	faceplayer
	goto_if_set FLAG_ASTORIA_GOT_TEST_MONEY, PalletTown_PlayersHouse_1F_EventScript_AstoriaTestMoneyAfter
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestMoneyIntro, MSGBOX_DEFAULT
	addmoney 1500000
	showmoneybox 0, 0
	playse SE_SHOP
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestReceivedMoney, MSGBOX_DEFAULT
	hidemoneybox
	setflag FLAG_ASTORIA_GOT_TEST_MONEY
	release
	end

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestMoneyAfter::
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestMoneyAfter, MSGBOX_DEFAULT
	release
	end

PalletTown_PlayersHouse_1F_EventScript_AstoriaTestKid::
	lock
	faceplayer
	msgbox PalletTown_PlayersHouse_1F_Text_AstoriaTestKid, MSGBOX_DEFAULT
	release
	end

PalletTown_PlayersHouse_1F_Text_AstoriaTestWasabiIntro::
	.string "TEST NPC: Hey, {PLAYER}!\n"
	.string "This is test dialogue number one.\p"
	.string "If you can read this, scripts work.\n"
	.string "Here, take your partner.$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestReceivedWasabi::
	.string "{PLAYER} received WASABI\n"
	.string "the BULBASAUR!$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestWasabiAfter::
	.string "TEST NPC: Check your party menu.\n"
	.string "WASABI should be in there.$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestNoRoom::
	.string "TEST NPC: Your party is full!$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestMoneyIntro::
	.string "TEST NPC: Test dialogue number two.\p"
	.string "This checks the new money cap.\n"
	.string "Take ¥1,500,000.$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestReceivedMoney::
	.string "{PLAYER} received ¥1,500,000!\p"
	.string "The money box should show\n"
	.string "seven digits.$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestMoneyAfter::
	.string "TEST NPC: Open the TRAINER CARD to\n"
	.string "check your money again.$"

PalletTown_PlayersHouse_1F_Text_AstoriaTestKid::
	.string "TEST NPC: Test dialogue number three!\n"
	.string "I wander around. Walking works!$"
