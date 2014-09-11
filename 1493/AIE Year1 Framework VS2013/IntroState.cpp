#include "GameEngine.h"
#include "GameState.h"
#include "IntroState.h"
#include "PlayState.h"
#include "Sprite.h"
IntroState IntroState::m_IntroState; // **has to do with singleton?**
// default constructor
//IntroState::IntroState()
//{
//
//}
// to be executed first upon entering the state
void IntroState::Init()
{
	// load intro sprite
	Sprite introImage("TestImage", SCREEN_X, SCREEN_Y, SCREEN_CENTER, ZERO_VELOCITY, Vector2D(), 0, 0, true, "./images/IntroState.png", 1);
	m_iBG = introImage.GetSpriteId();
	MoveSprite(m_iBG, 1024 >> 1, 768 >> 1);
	// do something to make a "fade"
	// run the fade
	printf("IntroState Init\n");
}
// to be executed when state is popped from end of stack
void IntroState::Cleanup()
{
	// **clean stuff? (sprite & fader?)**
	DestroySprite(m_iBG);
	printf("IntroState Cleanup\n");
}
void IntroState::Pause()
{
	printf("IntroState Pause\n");
}
void IntroState::Resume()
{
	printf("IntroState Resume\n");
}
void IntroState::HandleEvents(GameEngine* a_opGame)
{
	// look for key presses to quit or go to the menu??
	if (IsKeyDown(GLFW_KEY_ENTER))
	{
		a_opGame->ChangeState(PlayState::Instance());
	}
	if (IsKeyDown('Q'))
	{
		a_opGame->Quit();
	}
}
void IntroState::Update(GameEngine* a_opGame, double dt)
{
	// decrement the alpha of the fader covering the background
	// feed alpha value to the fader
}
void IntroState::Draw(GameEngine* a_opGame)
{
	// reference project uses Blit from SDL, look that up and compare with GLFW?
	// draw the background image?? check out ref. **
	DrawSprite(m_iBG);
}
IntroState* IntroState::Instance()
{
	return &m_IntroState;
}