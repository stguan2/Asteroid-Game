#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Sprite.h"
#include "Particle.h"
#include "ParticleEmitter.h"

typedef enum { MoveStop, MoveLeft, MoveRight, MoveUp, MoveDown } MoveDir;

class Emitter;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void move();
		void moveCheck();
		void checkOffScreen();
		void checkCollisions();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Sprite user;
		Sprite beginningScreenSprite;
		Sprite endScreenSprite;
		Emitter *player;
		// Controls acceleration of player when pressing up arrow key
		float accel;
		float timeAfterGameStart;
		float timeAfterGameEnd;
		// easy enemies
		Emitter *EL1, *EL2, *EL3, *ET1, *ET2, *ET3, *ER1, *ER2, *ER3, *EB1, *EB2, *EB3;
		// medium enemies (small and fast)
		Emitter *ml1, *ml2, *ml3, *mt1, *mt2, *mt3, *mr1, *mr2, *mr3, *mb1, *mb2, *mb3;
		// very small enemy
		Emitter *left, *top, *right, *bottom;

		// enemy rotation
		float rot;
		vector<Emitter *> enemyLeftSpawn;
		vector<Emitter *> enemyTopSpawn;
		vector<Emitter *> enemyRightSpawn;
		vector<Emitter *> enemyBottomSpawn;
		vector<Emitter *> mediumSpawn;
		vector<Emitter *> hardEmitters;
		vector<Emitter *> allEnemyEmitters;
		vector<Emitter *> allEmitters;

		ParticleEmitter playerPEmitter;
		ParticleEmitter pEmitter;
		ImpulseRadialForce *radialForce;
		TurbulenceForce *turbForce;

		MoveDir dir;
		ofVec3f mouse_last;
		ofImage playerImage;
		ofImage missleImage;
		ofImage beginningScreen;
		ofImage endScreen;
		ofImage enemyLeftImage, enemyRightImage, enemyTopImage, enemyBottomImage, mediumImage, hardImage;
		ofSoundPlayer collisionSound;
		ofSoundPlayer gameOverSound;
		bool haveCollisionSound;
		bool haveGameOverSound;
		bool gameOver = false;
		ofSoundPlayer missleSound;

		//gameStart variable initially false
		//if spacebar is pressed gameStart variable changes to true
		//player, background, and enemies start only when gameStart is true
		bool gameStart;
		//check if easy enemies have their rate reduced
		bool reduceRate1 = false;
		//check if medium enemies have their rate reduced
		bool reduceRate2 = false;
		bool bHide;

		int score;
		ofTrueTypeFont scoreFinalDisplay;
		ofTrueTypeFont scoreDisplay;
		//prevents lag from arrow key presses
		int prevKey = -99999;

		ofxFloatSlider rate, leftRate1, leftRate2, leftRate3, topRate1, topRate2, topRate3, rightRate1, rightRate2, rightRate3;
		ofxFloatSlider life;
		ofxVec3Slider velocity, leftVel1, leftVel2, leftVel3, topVel1, topVel2, topVel3, rightVel1, rightVel2, rightVel3;
		ofxLabel screenSize;


		ofxPanel gui;
};