#include "GameEngine.h"
#include "GameState.h"
#include "DeathState.h"
#include "PlayState.h"
#include "Sprite.h"
DeathState DeathState::m_DeathState; // **has to do with singleton?**
// default constructor
//DeathState::DeathState()
//{
//
//}
// to be executed first upon entering the state
void DeathState::Init()
{
	// load intro sprite
	Sprite deathImage("TestImage", SCREEN_X, SCREEN_Y, SCREEN_CENTER, ZERO_VELOCITY, Vector2D(), 20, 0, true, "./images/DeathState.png", 1);
	m_iBG = deathImage.GetSpriteId();
	MoveSprite(m_iBG, 1024 >> 1, 768 >> 1);
	// do something to make a "fade"
	// run the fade
	printf("DeathState Init\n");
}
// to be executed when state is popped from end of stack
void DeathState::Cleanup()
{
	// **clean stuff? (sprite & fader?)**
	DestroySprite(m_iBG);
	printf("DeathState Cleanup\n");
}
void DeathState::Pause()
{
	printf("DeathState Pause\n");
}
void DeathState::Resume()
{
	printf("DeathState Resume\n");
}
void DeathState::HandleEvents(GameEngine* a_opGame)
{
	// look for key presses to quit or go to the menu??
	/*if (IsKeyDown(GLFW_KEY_ENTER))
	{
	a_opGame->ChangeState(PlayState::Instance());
	}*/
	if (IsKeyDown('Q'))
	{
		a_opGame->Quit();
	}
}
void DeathState::Update(GameEngine* a_opGame, double dt)
{
	// decrement the alpha of the fader covering the background
	// feed alpha value to the fader
}
void DeathState::Draw(GameEngine* a_opGame)
{
	// reference project uses Blit from SDL, look that up and compare with GLFW?
	// draw the background image?? check out ref. **
	DrawSprite(m_iBG);
}
DeathState* DeathState::Instance()
{
	return &m_DeathState;
}