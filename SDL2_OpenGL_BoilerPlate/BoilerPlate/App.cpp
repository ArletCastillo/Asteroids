#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Colors.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"

// OpenGL includes
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL.h>
#include <SDL_ttf.h>

namespace Engine
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;
	Colors background;
	Colors line;
	Color changeBackground(0.0f, 0.0f, 0.0f, 0.0f);
	Color changeLine(1.0f, 1.0f, 1.0f, 1.0f);

	void App::CreateEntity() {
		m_ship = new Player();
		m_asteroids.push_back(new Asteroid());
	}

	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_life(5)
		, m_activateColision(true)
		, m_isShot(true)
		, m_debug(false)
		, m_bFrame(false)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
		CreateEntity();
		m_cpt_frames = std::vector<Vector2>(MAX_FRAME_COUNT);
		for (int x = 0; x < MAX_FRAME_COUNT; x++)
		{
			m_cpt_frames[x] = Vector2((float)x, 0.0f);
		}
		m_current_frame_position = 0;
		m_time = DESIRED_FRAME_RATE;
	}

	App::~App()
	{
		CleanupSDL();
	}

	void App::Execute()
	{
		if (m_state != GameState::INIT_SUCCESSFUL)
		{
			std::cerr << "Game INIT was not successful." << std::endl;
			return;
		}

		m_state = GameState::RUNNING;

		SDL_Event event;
		while (m_state == GameState::RUNNING)
		{
			// Input polling
			//
			while (SDL_PollEvent(&event))
			{
				OnEvent(&event);
			}

			//
			Update();
			Render();
		}
	}

	bool App::Init()
	{
		// Init the external dependencies
		//
		bool success = SDLInit() && GlewInit();
		if (!success)
		{
			m_state = GameState::INIT_FAILED;
			return false;
		}

		// Setup the viewport
		//
		SetupViewport();

		// Change game state
		//
		m_state = GameState::INIT_SUCCESSFUL;

		return true;
	}

	void App::OnKeyDown(SDL_KeyboardEvent keyBoardEvent)
	{		
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_W:
			m_ship->activateThruster = true;
			m_inputManager.SetW(true);
			break;
		case SDL_SCANCODE_A:
			m_inputManager.SetA(true);
			break;
		case SDL_SCANCODE_S:
			m_inputManager.SetS(true);
			break;
		case SDL_SCANCODE_D:
			m_inputManager.SetD(true);
			break;
		case SDL_SCANCODE_Q:
			m_asteroids.push_back(new Asteroid()); //spawns new
			break;
		case SDL_SCANCODE_E:
			if (m_asteroids.size()>0) //if the vector has asteroids, then remove them.
				m_asteroids.pop_back();
			break;
		case SDL_SCANCODE_G:
			m_inputManager.SetG(true);
			break;
		case SDL_SCANCODE_F:
			m_inputManager.SetF(true);
			break;
		case SDL_SCANCODE_Z:
			m_inputManager.SetZ(true);
			break;
		case SDL_SCANCODE_SPACE:
			if (m_activateColision)
				m_bullets.push_back(new Bullet(m_ship));
			break;
		default:			
			SDL_Log("%S was pressed...", keyBoardEvent.keysym.scancode);
			break;
		}
	}

	void App::OnKeyUp(SDL_KeyboardEvent keyBoardEvent)
	{
		switch (keyBoardEvent.keysym.scancode)
		{
		case SDL_SCANCODE_ESCAPE:
			OnExit();
			break;
		case SDL_SCANCODE_W:
			m_ship->activateThruster = false;
			m_inputManager.SetW(false);
			break;
		case SDL_SCANCODE_A:
			m_inputManager.SetA(false);
			break;
		case SDL_SCANCODE_S:
			m_inputManager.SetS(false);
			break;
		case SDL_SCANCODE_D:
			m_inputManager.SetD(false);
			break;
		case SDL_SCANCODE_G:
			m_inputManager.SetG(false);
			break;
		case SDL_SCANCODE_F:
			m_inputManager.SetF(false);
			break;
		case SDL_SCANCODE_Z:
			m_inputManager.SetZ(false);
			break;
		case SDL_SCANCODE_X:
			changeBackground = background.Baby_blue();
			changeLine = line.Midnight();
			break;
		case SDL_SCANCODE_C:
			changeBackground = background.Cherry_blossom();
			changeLine = line.Dark_red();
			break;
		case SDL_SCANCODE_V:
			changeBackground = background.Dark_aqua();
			changeLine = line.Baby_blue();
			break;
		case SDL_SCANCODE_B:
			changeBackground = background.Dark_red();
			changeLine = line.Cherry_blossom();
			break;
		case SDL_SCANCODE_N:
			changeBackground = background.Midnight();
			changeLine = line.Baby_blue();
			break;
		default:
			//DO NOTHING
			break;
		}
	}

	void App::UpdateEntity() {
		m_ship->Update(DESIRED_FRAME_TIME);
		for (int i = 0; i<m_asteroids.size(); i++)
			m_asteroids[i]->Update(DESIRED_FRAME_TIME);
		for(int i=0;i<m_bullets.size();i++)
			m_bullets[i]->Update(DESIRED_FRAME_TIME);
	}

	void App::CreateAsteroidWithPosition(Vector2 position, int size){
		m_asteroids.push_back(new Asteroid(size));
		m_asteroids[m_asteroids.size() - 1]->AssignPosition(position);
	}

	void App::UpdateFrame(){
		m_cpt_frames[m_current_frame_position] = Vector2((float)m_current_frame_position, m_time);
		m_current_frame_position++;
		if (m_current_frame_position >= MAX_FRAME_COUNT)
			m_current_frame_position = 0;
	}

	void App::GetFrameRate(){
		glLoadIdentity();
		glTranslatef(X_AXIS_POSITION, Y_AXIS_POSITION, 0.0f);
		glBegin(GL_LINE_STRIP);
		glVertex2f(0.0f, 100.0f);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(130.0f, 0.0f);
		glEnd();

		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < MAX_FRAME_COUNT; i++)
			glVertex2f(10.0f * m_cpt_frames[i].x, 100000.0f * (DESIRED_FRAME_TIME - m_cpt_frames[i].y));
		glEnd();
		
	}

	void App::Input(){
		if(m_inputManager.GetW())
			m_ship->MoveForward();
		if(m_inputManager.GetA())
			m_ship->RotateLeft();
		if (m_inputManager.GetS()) {
			if (!m_bFrame)
				m_bFrame = true;
			else
				m_bFrame = false;
		}
		if(m_inputManager.GetD())
			m_ship->RotateRight();			 
		if (m_inputManager.GetG()) {
			//enters the debbug mode
			m_debug = true;
			m_ship->activateCircle = true;
			for (int i = 0; i < m_bullets.size(); i++)
				m_bullets[i]->activateCircle = true;
		}
		if (m_inputManager.GetF()) {
			//exits debugg mode
			m_debug = false;
			m_activateLine = false;
			m_ship->activateCircle = false;
			for (int i = 0; i < m_asteroids.size(); i++)
				m_asteroids[i]->activateCircle = false;
		}
		if(m_inputManager.GetZ())
			m_activateColision = true;
	}

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		Input();
		UpdateEntity();
		if (m_activateColision && !m_debug) {
			for (int i = 0; i < m_asteroids.size(); i++) {
				/* if the distance between the ship and the asteroid is smaller than the sum of their radius
				(meaning that they are really close) erase the asteroid */
				if ((m_collision.Distance(m_ship->GetOrigin(), m_asteroids[i]->GetOrigin()))
					<= (m_ship->GetRadius() + m_asteroids[i]->GetRadius())) {
					m_asteroids.erase(m_asteroids.begin() + i);
					m_activateColision = false;
					m_life--;
				}
			}
		}
		for (int i = 0; i < m_asteroids.size(); i++) {
			bool x = false;
			for (int j = 0; j < m_bullets.size(); j++) {
				/* if the distance between the asteroid and the bullet is smaller than the sum of their radius 
				(meaning that they are really close) */
				if ((m_collision.Distance(m_asteroids[i]->GetOrigin(), m_bullets[j]->GetOrigin())) 
					<= (m_asteroids[i]->GetRadius() + m_bullets[j]->GetRadius())) {
					m_bullets.erase(m_bullets.begin() + j);
					x = true;
					//checks if the asteroid is not small
					if (m_asteroids[i]->GetSize() != 1) {
						m_asteroids[i]->ChangeSize();
						int newSize = m_asteroids[i]->GetSize();
						CreateAsteroidWithPosition(m_asteroids[i]->GetOrigin(), m_asteroids[i]->GetSize());
					}
					else {
						//if it's small, then erases the asteroid
						m_asteroids.erase(m_asteroids.begin() + i);
					}
					break;
				}
			}
			if (x == true)
				break;
		}
		if (m_debug) {
			for (int i = 0; i < m_asteroids.size(); i++) {
				/* if the distance between the ship and the asteroid is smaller than the sum of their radius
				(meaning that they are really close) erase the asteroid */
				if ((m_collision.Distance(m_ship->GetOrigin(), m_asteroids[i]->GetOrigin()))
					<= 2*(m_ship->GetRadius() + m_asteroids[i]->GetRadius())) {
					m_asteroids[i]->SetDrawLine(true);
				}
			}
		}
		if (m_life <= 0)
			m_activateColision = false;
		double endTime = m_timer->GetElapsedTimeInSeconds();
		m_time = DESIRED_FRAME_TIME - (endTime - startTime);
		UpdateFrame();
		double nextTimeFrame = startTime + DESIRED_FRAME_TIME;

		while (endTime < nextTimeFrame)
		{
			// Spin lock
			endTime = m_timer->GetElapsedTimeInSeconds();
		}

		//double elapsedTime = endTime - startTime;        

		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();

		m_nUpdates++;
	}

	void App::RenderEntity() {
		if (m_activateColision == true)
			m_ship->Render();
		for (int i = 0; i < m_asteroids.size(); i++) {
			if (m_debug) 
				m_asteroids[i]->activateCircle = true;
			m_asteroids[i]->Render();
		}
		for (int i = 0; i < m_bullets.size(); i++) {
			if(m_bullets[i]->m_isAlive == true)
				m_bullets[i]->Render();
			else
				m_bullets.erase(m_bullets.begin() + i);
		}	
	}

	void App::RenderLives() {
		std::vector<Vector2> livesPoints = m_ship->ObtainLives();
		float size = 0.5f;
		float hWidth = (float)m_width / 2.0f;
		float hHeight = (float)m_height / 2.0f;
		glLoadIdentity();
		glTranslatef(hWidth, hHeight, 0.0f);
		glColor3f(changeLine.r, changeLine.g, changeLine.b);
		for (int i = 0; i < m_life; i++) {
			glBegin(GL_LINE_LOOP);
			for (int j = 0; j < livesPoints.size(); j++)
				glVertex2f(size*livesPoints[j].x - 30 * (i + 1), size*livesPoints[j].y - 20);
			glEnd();
		}
	}

	void App::Render()
	{
		//glClearColor(0.1f, 0.1f, 0.15f, 1.0f)
		Colors c;
		glClearColor(changeBackground.r, changeBackground.g, changeBackground.b, changeBackground.a);
		glColor3f(changeLine.r, changeLine.g, changeLine.b);
		glClear(GL_COLOR_BUFFER_BIT);
		RenderEntity();
		RenderLives();
		if(m_bFrame)
			GetFrameRate();
		for (int i = 0; i < m_asteroids.size(); i++) {
			if (m_asteroids[i]->GetDrawLine() == true)
				m_asteroids[i]->DrawLine(m_ship->GetOrigin());
			m_asteroids[i]->SetDrawLine(false);
		}
		SDL_GL_SwapWindow(m_mainWindow);
	}

	bool App::SDLInit()
	{
		// Initialize SDL's Video subsystem
		//
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			std::cerr << "Failed to init SDL" << std::endl;
			return false;
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

		Uint32 flags =  SDL_WINDOW_OPENGL     | 
						SDL_WINDOW_SHOWN      | 
						SDL_WINDOW_RESIZABLE;

		m_mainWindow = SDL_CreateWindow(
			m_title.c_str(),
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			m_width,
			m_height,
			flags
		);

		if (!m_mainWindow)
		{
			std::cerr << "Failed to create window!" << std::endl;
			SDL_Quit();
			return false;
		}

		m_context = SDL_GL_CreateContext(m_mainWindow);
		SDL_GL_MakeCurrent(m_mainWindow, m_context);

		// Make double buffer interval synced with vertical scanline refresh
		SDL_GL_SetSwapInterval(0);

		return true;
	}

	void App::SetupViewport()
	{
		// Defining ortho values
		//
		float halfWidth = m_width * 0.5f;
		float halfHeight = m_height * 0.5f;

		// Set viewport to match window
		//
		glViewport(0, 0, m_width, m_height);

		// Set Mode to GL_PROJECTION
		//
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		// Set projection MATRIX to ORTHO
		//
		glOrtho(-halfWidth, halfWidth, -halfHeight, halfHeight, -1, 1);

		// Setting Mode to GL_MODELVIEW
		//
		glMatrixMode(GL_MODELVIEW);
	}

	bool App::GlewInit()
	{
		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			std::cerr << "Error: " << glewGetErrorString(err) << std::endl;
			return false;
		}

		return true;
	}

	void App::CleanupSDL()
	{
		// Cleanup
		//
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_mainWindow);

		SDL_Quit();
	}

	void App::OnResize(int width, int height)
	{
		// TODO: Add resize functionality
		//
		m_width = width;
		m_height = height;

		for (int i = 0; i < m_bullets.size(); i++)
			m_bullets[i]->UpdateWrap(m_width, m_height);

		for (int i = 0; i < m_asteroids.size(); i++)
			m_asteroids[i]->UpdateWrap(m_width, m_height);

		m_ship->UpdateWrap(m_width, m_height);

		SetupViewport();
	}

	void App::OnExit()
	{
		// Exit main for loop
		//
		m_state = GameState::QUIT;

		// Cleanup SDL pointers
		//
		CleanupSDL();
	}
}
