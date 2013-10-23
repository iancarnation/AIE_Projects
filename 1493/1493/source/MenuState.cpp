///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// File:			MenuState.cpp
// Author:			Ian Rich
// Date Created:	October 2013
// Brief:			menu state, inherits GameState base class
// References:		http://gamedevgeek.com/tutorials/managing-game-states-in-c/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GameEngine.h"
#include "GameState.h"
#include "MenuState.h"
#include "Sprite.h"

MenuState MenuState::m_MenuState; // **has to do with singleton?**

// default constructor
//MenuState::MenuState()
//{
//
//}

// to be executed first upon entering the state
void MenuState::Init()
{
	// load menu sprite(s)
	Sprite menuImage("TestImage", 1024, 768, 612, 384, 0, 0, 0,true, "./images/MenuState.png");
	m_iBG = menuImage.GetSpriteId();
	MoveSprite(m_iBG, 1024>>1, 768>>1);
	// reference calls bg = SDL_DisplayFormat(temp);
	//				   SDL_FreeSurface(temp);

	printf("MenuState Init\n");

}

// to be executed when state is popped from end of stack
void MenuState::Cleanup()
{
	// **clean stuff?  destroy sprites?? reference calls SDL_FreeSurface(bg);**
	DestroySprite(m_iBG);

	printf("MenuState Cleanup\n");
}

void MenuState::Pause()
{
	printf("MenuState Pause\n");
}

void MenuState::Resume()
{
	printf("MenuState Resume\n");
}

void MenuState::HandleEvents(GameEngine* a_opGame)
{
	// look for key presses for menu actions
	// maybe use a 'select' button or directional controls to select options as well
	if (IsKeyDown('Q'))
		{
			a_opGame->Quit();
		}
	/*if (IsKeyDown('M'))		//  **make key delay function**
		{
			a_opGame->PopState();   
		}*/
	if (IsKeyDown(GLFW_KEY_ESC))
		{
			a_opGame->PopState();
		}
}

void MenuState::Update(GameEngine* a_opGame)
{

}

void MenuState::Draw(GameEngine* a_opGame)
{
	// reference project uses Blit from SDL, look that up and compare with GLFW?

	// draw the background image??  check out ref. **
	DrawSprite(m_iBG);
}

MenuState* MenuState::Instance()
{
	// call draw function on menu sprites?
	return &m_MenuState;
}
