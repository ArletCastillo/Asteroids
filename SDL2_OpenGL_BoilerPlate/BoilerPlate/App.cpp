#include "App.hpp"
#include <iostream>
#include <algorithm>
#include "Colors.hpp"
#include "Player.hpp"
#include "Asteroid.hpp"

// OpenGL includes
#include <GL/glew.h>
#include <SDL2/SDL_opengl.h>

namespace Engine
{
	const float DESIRED_FRAME_RATE = 60.0f;
	const float DESIRED_FRAME_TIME = 1.0f / DESIRED_FRAME_RATE;

	void App::CreateEntity() {
		m_ship = new Player();
		m_asteroids.push_back(new Asteroid());
	}

	App::App(const std::string& title, const int width, const int height)
		: m_title(title)
		, m_activateColision(true)
		, m_isShot(true)
		, m_width(width)
		, m_height(height)
		, m_nUpdates(0)
		, m_timer(new TimeManager)
		, m_mainWindow(nullptr)
	{
		m_state = GameState::UNINITIALIZED;
		m_lastFrameTime = m_timer->GetElapsedTimeInSeconds();
		CreateEntity();
		
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
			m_ship->MoveForward();
			m_ship->activateThruster = true;
			break;
		case SDL_SCANCODE_A:
			m_ship->RotateLeft();
			break;
		case SDL_SCANCODE_S:
			break;
		case SDL_SCANCODE_D:
			m_ship->RotateRight();
			break;
		case SDL_SCANCODE_Q:
			m_asteroids.push_back(new Asteroid());
			break;
		case SDL_SCANCODE_E:
			if (m_asteroids.size()>0) //if the vector has asteroids, then remove them.
				m_asteroids.pop_back();
			break;
		case SDL_SCANCODE_G:
			m_activateLine = true;
			m_ship->activateCircle = true;
			for (int i = 0; i < m_asteroids.size(); i++)
				m_asteroids[i]->activateCircle = true;
			for (int i = 0; i < m_bullets.size(); i++)
				m_bullets[i]->activateCircle = true;
			break;
		case SDL_SCANCODE_F:
			m_activateLine = false;
			m_ship->activateCircle = false;
			for (int i = 0; i < m_asteroids.size(); i++)
				m_asteroids[i]->activateCircle = false;
			break;
		case SDL_SCANCODE_Z:
			m_activateColision = true;
			break;
		case SDL_SCANCODE_SPACE:
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

	void App::Update()
	{
		double startTime = m_timer->GetElapsedTimeInSeconds();

		// Update code goes here
		UpdateEntity();
		for (int i = 0; i < m_asteroids.size(); i++) {
			/* if the distance between the ship and the asteroid is smaller than the sum of their radius 
			(meaning that they are really close) erase the asteroid */
			if ((m_collision.Distance(m_ship->getOrigin(), m_asteroids[i]->getOrigin())) 
				 <= (m_ship->getRadius() + m_asteroids[i]->getRadius())) {
				m_asteroids.erase(m_asteroids.begin() + i);
				m_activateColision = false;
			}
		}
		for (int i = 0; i < m_asteroids.size(); i++) {
			for (int j = 0; j < m_bullets.size(); j++) {
				/* if the distance between the asteroid and the bullet is smaller than the sum of their radius 
				(meaning that they are really close) */
				if ((m_collision.Distance(m_asteroids[i]->getOrigin(), m_bullets[j]->getOrigin())) 
					<= (m_asteroids[i]->getRadius() + m_bullets[j]->getRadius())) {
					m_bullets.erase(m_bullets.begin() + j);
					//checks if the asteroid is not small
					if (m_asteroids[i]->GetSize() != 1) {
						m_asteroids[i]->ChangeSize();
						int newSize = m_asteroids[i]->GetSize();
						CreateAsteroidWithPosition(m_asteroids[i]->getOrigin(), m_asteroids[i]->GetSize());
					}
					else {
						//if it's small, then erases the asteroid
						m_asteroids.erase(m_asteroids.begin() + i);
					}
				}
			}
		}
		double endTime = m_timer->GetElapsedTimeInSeconds();
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
			m_asteroids[i]->Render();
		}
		for (int i = 0; i < m_bullets.size(); i++) {
			if(m_bullets[i]->m_isAlive == true)
				m_bullets[i]->Render();
			else
				m_bullets.erase(m_bullets.begin() + i);
		}	
	}

	void App::Render()
	{
		//glClearColor(0.1f, 0.1f, 0.15f, 1.0f)
		Colors c;
		glClearColor(c.Dark_aqua().r, c.Dark_aqua().g, c.Dark_aqua().b, c.Dark_aqua().a);
		glClear(GL_COLOR_BUFFER_BIT);
		RenderEntity();
		if(m_activateLine == true)
			for (int i = 0; i < m_asteroids.size(); i++)
				m_asteroids[i]->DrawLine(m_ship->getOrigin());
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
