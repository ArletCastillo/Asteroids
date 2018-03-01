#pragma once
#ifndef APP_HPP
#define APP_HPP

// C++ STL
#include <string>
#include <list>

// Asteroids
#include "SDLEvent.hpp"
#include "TimeManager.hpp"

#include "Player.hpp"
#include "Asteroid.hpp"
#include "Vector2.hpp"
#include <vector>
#include "Bullet.hpp"
#include "InputManager.hpp"
#include "Color.hpp"

const int MAX_FRAME_COUNT = 15;
const int X_AXIS_POSITION = 100;
const int Y_AXIS_POSITION = -200;

namespace Engine
{
	class App : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		App( const std::string& title, const int width, const int height );
		~App( );
		void Execute						( );
		bool Init							( );
		void Update							( );
		void Render							( );
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		bool GlewInit						( );
		void SetupViewport					( );
		void CleanupSDL						( );
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;
		void CreateEntity					( );
		void UpdateEntity					( );
		void RenderEntity					( );
		void CreateAsteroidWithPosition		(Vector2, int);
		void UpdateFrame					( );
		void GetFrameRate					( );
		void Input							( );
		void RenderLives					( );
		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		int									m_width;
		int									m_height;
		int									m_nUpdates;
		int									m_current_frame_position;
		int									m_life;
		double								m_lastFrameTime;
		bool								m_activateLine;
		bool								m_activateColision;
		bool								m_isShot;
		bool								m_debug;
		bool								m_bFrame;
		bool								m_graph;
		float								m_time;
		std::string							m_title;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		GameState::State					m_state;
		Engine::TimeManager*				m_timer;
		Player*                             m_ship;
		std::vector<Asteroid*>				m_asteroids;
		Vector2								m_collision;
		std::vector<Vector2>				m_cpt_frames;
		std::vector<Bullet*>				m_bullets;
		InputManager						m_inputManager;
	};
}
#endif /* GAME_HPP */
