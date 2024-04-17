#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"
#include "../../header/Powerup/PowerupConfig.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Particle/ParticleService.h"  // a change is made here, included particle -> particleservice since it will be used further

namespace Player
{
    class PlayerModel;      
    class PlayerView;       // had to call PlayerModel and PlayerView class because of these classes were being accessed without being defined
    class PlayerController : public Collision::ICollider
    {
    private:
        float elapsed_shield_duration;
        float elapsed_rapid_fire_duration;
        float elapsed_tripple_laser_duration;

        float elapsed_fire_duration;
        float elapsed_freez_duration;

        PlayerView* player_view;
        PlayerModel* player_model;

        void processPlayerInput();
        void moveLeft();
        void moveRight();
        void processBulletFire();       // added processBulletFire() because to define it further, we need to first create the function

        bool processPowerupCollision(ICollider* other_collider);
        bool processEnemyCollision(ICollider* other_collider);
        void updateFreezDuration();
        void freezPlayer();
        void updatePowerupDuration();
       
        void disableShield();   
        void disableRapidFire();    
        void disableTrippleLaser();

        void saveHighScore();

    public:
        PlayerController();
        ~PlayerController();

        void initialize();
        void update();
        void render();

        void reset();

        void decreasePlayerLive();
        inline void increaseScore(int val) { PlayerModel::player_score += val; }
        inline void decreaseScore(int val) { PlayerModel::player_score -= val; }
        inline void increaseEnemiesKilled(int val) { PlayerModel::enemies_killed += val; }
        inline void increaseBulletsFired(int val) { PlayerModel::bullets_fired += val; }
        
        void enableShield();
        void enableRapidFire();
        void enableTrippleLaser();

        sf::Vector2f getPlayerPosition();
        PlayerState getPlayerState();

        const sf::Sprite& getColliderSprite() override;
        void onCollision(ICollider* other_collider) override;
    };
}