#include "ofApp.h"
#include "Emitter.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(255, 255, 255);
	haveCollisionSound = false;
	score = 0;
	rot = 0;

	player = new Emitter(new SpriteSystem());
	player->setChildSize(10, 10);
	player->setRate(-1);

	allEmitters.push_back(player);

	//Enemy Left 1 (EL1) - first left enemy emitter
	EL1 = new Emitter(new SpriteSystem());
	EL1->setChildSize(50, 50);

	//Enemy Left 2 (EL2) - second left enemy emitter
	EL2 = new Emitter(new SpriteSystem());
	EL2->setChildSize(50, 50);

	//Enemy Left 3 (EL3) - third left enemy emitter
	EL3 = new Emitter(new SpriteSystem());
	EL3->setChildSize(50, 50);

	//Enemy Top 1 (ET1) - first top enemy emitter
	ET1 = new Emitter(new SpriteSystem());
	ET1->setChildSize(50, 50);

	//Enemy Top 2 (ET2) - second top enemy emitter
	ET2 = new Emitter(new SpriteSystem());
	ET2->setChildSize(50, 50);

	//Enemy Top 3 (ET3) - third top enemy emitter
	ET3 = new Emitter(new SpriteSystem());
	ET3->setChildSize(50, 50);

	//Enemy Right 1 (ER1) - first right enemy emitter
	ER1 = new Emitter(new SpriteSystem());
	ER1->setChildSize(50, 50);

	//Enemy Right 2 (ER2) - second right enemy emitter
	ER2 = new Emitter(new SpriteSystem());
	ER2->setChildSize(50, 50);

	//Enemy Right 3 (ER3) - third right enemy emitter
	ER3 = new Emitter(new SpriteSystem());
	ER3->setChildSize(50, 50);

	//Enemy Bottom 1 (EB1) - first bottom enemy emitter
	EB1 = new Emitter(new SpriteSystem());
	EB1->setChildSize(50, 50);

	//Enemy Bottom 2 (EB2) - second bottom enemy emitter
	EB2 = new Emitter(new SpriteSystem());
	EB2->setChildSize(50, 50);

	//Enemy Bottom 3 (EB3) - third bottom enemy emitter
	EB3 = new Emitter(new SpriteSystem());
	EB3->setChildSize(50, 50);

	// Initialize medium enemies
	
	ml1 = new Emitter(new SpriteSystem());
	ml1->setChildSize(25, 25);

	ml2 = new Emitter(new SpriteSystem());
	ml2->setChildSize(25, 25);

	ml3 = new Emitter(new SpriteSystem());
	ml3->setChildSize(25, 25);

	mt1 = new Emitter(new SpriteSystem());
	mt1->setChildSize(25, 25);

	mt2 = new Emitter(new SpriteSystem());
	mt2->setChildSize(25, 25);

	mt3 = new Emitter(new SpriteSystem());
	mt3->setChildSize(25, 25);

	mr1 = new Emitter(new SpriteSystem());
	mr1->setChildSize(25, 25);

	mr2 = new Emitter(new SpriteSystem());
	mr2->setChildSize(25, 25);

	mr3 = new Emitter(new SpriteSystem());
	mr3->setChildSize(25, 25);

	mb1 = new Emitter(new SpriteSystem());
	mb1->setChildSize(25, 25);

	mb2 = new Emitter(new SpriteSystem());
	mb2->setChildSize(25, 25);

	mb3 = new Emitter(new SpriteSystem());
	mb3->setChildSize(25, 25);

	left = new Emitter(new SpriteSystem());
	left->setChildSize(10, 10);
	top = new Emitter(new SpriteSystem());
	top->setChildSize(10, 10);
	bottom = new Emitter(new SpriteSystem());
	bottom->setChildSize(10, 10);
	right = new Emitter(new SpriteSystem());
	right->setChildSize(10, 10);

	hardEmitters.push_back(left);
	hardEmitters.push_back(top);
	hardEmitters.push_back(right);
	hardEmitters.push_back(bottom);
	enemyLeftSpawn.push_back(EL1);
	enemyLeftSpawn.push_back(EL2);
	enemyLeftSpawn.push_back(EL3);
	enemyTopSpawn.push_back(ET1);
	enemyTopSpawn.push_back(ET2);
	enemyTopSpawn.push_back(ET3);
	enemyRightSpawn.push_back(ER1);
	enemyRightSpawn.push_back(ER2);
	enemyRightSpawn.push_back(ER3);
	enemyBottomSpawn.push_back(EB1);
	enemyBottomSpawn.push_back(EB2);
	enemyBottomSpawn.push_back(EB3);
	mediumSpawn.push_back(ml1);
	mediumSpawn.push_back(ml2);
	mediumSpawn.push_back(ml3);
	mediumSpawn.push_back(mt1);
	mediumSpawn.push_back(mt2);
	mediumSpawn.push_back(mt3);
	mediumSpawn.push_back(mr1);
	mediumSpawn.push_back(mr2);
	mediumSpawn.push_back(mr3);
	mediumSpawn.push_back(mb1);
	mediumSpawn.push_back(mb2);
	mediumSpawn.push_back(mb3);

	for (int i = 0; i < enemyLeftSpawn.size(); i++) {
		//set enemyLeftSpawn's drawable to false and push all left emitters to allEmitters and allEnemyEmitters
		enemyLeftSpawn[i]->drawable = false;
		allEmitters.push_back(enemyLeftSpawn[i]);
		allEnemyEmitters.push_back(enemyLeftSpawn[i]);
	}

	for (int i = 0; i < enemyTopSpawn.size(); i++) {
		//set enemyTopSpawn's drawable to false and push all top emitters to allEmitters and allEnemyEmitters
		enemyTopSpawn[i]->drawable = false;
		allEmitters.push_back(enemyTopSpawn[i]);
		allEnemyEmitters.push_back(enemyTopSpawn[i]);
	}

	for (int i = 0; i < enemyRightSpawn.size(); i++) {
		//set enemyRightSpawn's drawable to false and push all right emitters to allEmitters and allEnemyEmitters
		enemyRightSpawn[i]->drawable = false;
		allEmitters.push_back(enemyRightSpawn[i]);
		allEnemyEmitters.push_back(enemyRightSpawn[i]);
	}

	for (int i = 0; i < enemyBottomSpawn.size(); i++) {
		//set enemyBottomSpawn's drawable to false and push all bottom emitters to allEmitters and allEnemyEmitters
		enemyBottomSpawn[i]->drawable = false;
		allEmitters.push_back(enemyBottomSpawn[i]);
		allEnemyEmitters.push_back(enemyBottomSpawn[i]);
	}

	for (int i = 0; i < mediumSpawn.size(); i++) {
		//set mediumSpawn's drawable to false and push all medium emitters to allEmitters and allEnemyEmitters
		mediumSpawn[i]->drawable = false;
		allEmitters.push_back(mediumSpawn[i]);
		allEnemyEmitters.push_back(mediumSpawn[i]);
	}

	for (int i = 0; i < hardEmitters.size(); i++) {
		hardEmitters[i]->drawable = false;
		allEmitters.push_back(hardEmitters[i]);
		allEnemyEmitters.push_back(hardEmitters[i]);
	}

	//to load missle image
	if (missleImage.loadImage("images/missleImage.png")) {
		player->setChildImage(missleImage);
	}

	//to load missle sound
	//This sound file is from OpenGameArt created by Kenney.nl.
	if (missleSound.loadSound("sounds/missleSound.mp3")) {
		player->setChildSoundPlayer(missleSound);
	}

	//to load player image
	if (playerImage.loadImage("images/Player.png")) {
		player->setImage(playerImage);
	}

	//to load enemy left image
	for (int i = 0; i < enemyLeftSpawn.size(); i++) {
		if (enemyLeftImage.loadImage("images/enemyLeft.png")) {
			enemyLeftSpawn[i]->setChildImage(enemyLeftImage);
		}
	}

	//to load enemy right image
	for (int i = 0; i < enemyRightSpawn.size(); i++) {
		if (enemyRightImage.loadImage("images/enemyRight.png")) {
			enemyRightSpawn[i]->setChildImage(enemyRightImage);
		}
	}

	//to load enemy top image
	for (int i = 0; i < enemyTopSpawn.size(); i++) {
		if (enemyTopImage.loadImage("images/enemyTop.png")) {
			enemyTopSpawn[i]->setChildImage(enemyTopImage);
		}
	}

	//to load enemy bottom image
	for (int i = 0; i < enemyBottomSpawn.size(); i++) {
		if (enemyBottomImage.loadImage("images/enemyBottom.png")) {
			enemyBottomSpawn[i]->setChildImage(enemyBottomImage);
		}
	}

	//to load medium enemy image
	for (int i = 0; i < mediumSpawn.size(); i++) {
		if (mediumImage.loadImage("images/medium.png")) {
			mediumSpawn[i]->setChildImage(mediumImage);
		}
	}

	//to load hard enemy image
	for (int i = 0; i < hardEmitters.size(); i++) {
		if (hardImage.loadImage("images/hard.png")) {
			hardEmitters[i]->setChildImage(hardImage);
		}
	}

	//to load beginning screen
	if (beginningScreen.load("images/begin.png")) {
		beginningScreenSprite.setImage(beginningScreen);
	}


	//to load end screen
	if (endScreen.load("images/end.png")) {
		endScreenSprite.setImage(endScreen);
	}

	//to load font
	scoreFinalDisplay.load("fonts/Myriad Pro Regular.ttf", 35);
	scoreDisplay.load("fonts/Myriad Pro Regular.ttf", 12);

	//to load collision sound
	//This sound file was obtained from https://www.freesoundeffects.com/free-sounds/explosion-10070/.
	haveCollisionSound = collisionSound.loadSound("sounds/collision.mp3");
	if (haveCollisionSound) {
		collisionSound.setMultiPlay(true);
	}

	//to load game over sound
	//This sound file was obtained from https://freesound.org/people/peepholecircus/sounds/169994/
	//This sound file, initially called Power Down was created by peepholecircus and is licensed under CC0 1.0.
	haveGameOverSound = gameOverSound.loadSound("sounds/gameOver.mp3");

	//initial gui setup for testing purposes
	//gui.setup();
	//gui.add(rate.setup("rate", 3, 1, 10));

	//start of game setup
	dir = MoveStop;
	gameStart = false;
	//bHide = false;
	beginningScreenSprite.setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
	endScreenSprite.setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));

	//Particle Emitters
	radialForce = new ImpulseRadialForce(1000);
	turbForce = new TurbulenceForce(ofVec3f(-2000, -2000, -2000), ofVec3f(2000, 2000, 2000));

	pEmitter.setEmitterType(RadialEmitter);
	pEmitter.setOneShot(true);
	pEmitter.setGroupSize(15);

	pEmitter.sys->addForce(radialForce);

	playerPEmitter.setEmitterType(DirectionalEmitter);
	playerPEmitter.setGroupSize(20);
	playerPEmitter.sys->setParticleColor(ofColor::red);

	playerPEmitter.sys->addForce(turbForce);

	//Emitters
	player->setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
	player->start();
	accel = 0;

	//easy enemies
	EL1->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	EL1->score = 10;
	EL1->start();

	EL2->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	EL2->score = 10;
	EL2->start();

	EL3->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	EL3->score = 10;
	EL3->start();

	ET1->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	ET1->score = 10;
	ET1->start();

	ET2->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	ET2->score = 10;
	ET2->start();
	
	ET3->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	ET3->score = 10;
	ET3->start();

	ER1->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	ER1->score = 10;
	ER1->start();

	ER2->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	ER2->score = 10;
	ER2->start();

	ER3->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	ER3->score = 10;
	ER3->start();

	EB1->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));
	EB1->score = 10;
	EB1->start();

	EB2->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));
	EB2->score = 10;
	EB2->start();

	EB3->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));
	EB3->score = 10;
	EB3->start();

	//medium enemies
	ml1->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	ml2->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	ml3->setPosition(ofVec3f(-50, ofRandom(0, ofGetWindowHeight()), 0));
	mt1->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	mt2->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	mt3->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), -50, 0));
	mr1->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	mr2->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	mr3->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(0, ofGetWindowHeight()), 0));
	mb1->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));
	mb2->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));
	mb3->setPosition(ofVec3f(ofRandom(0, ofGetWindowWidth()), ofGetWindowHeight() + 50, 0));

	//hard enemies
	left->setPosition(ofVec3f(-50, ofRandom(ofGetWindowHeight() / 3, ofGetWindowHeight() * (2 / 3)), 0));
	right->setPosition(ofVec3f(ofGetWindowSize().x + 50, ofRandom(ofGetWindowHeight() / 3, ofGetWindowHeight() * (2 / 3)), 0));
	top->setPosition(ofVec3f(ofRandom(ofGetWindowWidth() / 3, ofGetWindowWidth() * (2 / 3)), -50, 0));
	bottom->setPosition(ofVec3f(ofRandom(ofGetWindowWidth() / 3, ofGetWindowWidth() * (2 / 3)), ofGetWindowHeight() + 50, 0));

	for (int i = 0; i < mediumSpawn.size(); i++) {
		mediumSpawn[i]->score = 20;
		mediumSpawn[i]->start();
		mediumSpawn[i]->setLifespan(0);
		mediumSpawn[i]->setRate(ofRandom(.15, .3));
	}

	for (int i = 0; i < hardEmitters.size(); i++) {
		hardEmitters[i]->score = 30;
		hardEmitters[i]->start();
		hardEmitters[i]->setLifespan(0);
		hardEmitters[i]->setRate(ofRandom(.3, .8));
	}

	EL1->setRate(ofRandom(.1, .25));
	EL2->setRate(ofRandom(.1, .25));
	EL3->setRate(ofRandom(.1, .25));
	ET1->setRate(ofRandom(.1, .25));
	ET2->setRate(ofRandom(.1, .25));
	ET3->setRate(ofRandom(.1, .25));
	ER1->setRate(ofRandom(.1, .25));
	ER2->setRate(ofRandom(.1, .25));
	ER3->setRate(ofRandom(.1, .25));
	EB1->setRate(ofRandom(.1, .25));
	EB2->setRate(ofRandom(.1, .25));
	EB3->setRate(ofRandom(.1, .25));
}

//--------------------------------------------------------------
void ofApp::update() {
	if (gameStart) {
		player->setVelocity(ofVec3f(100 * sin(ofDegToRad(player->rot)), -100 * cos(ofDegToRad(player->rot)), velocity->z));
		player->update();

		// Random rate so not all enemies spawn at once every time.
		//
		EL1->setVelocity(ofVec3f(ofRandom(10, 40), ofRandom(-60, 60), 0));
		EL1->update();

		EL2->setVelocity(ofVec3f(ofRandom(10, 40), ofRandom(-60, 60), 0));
		EL2->update();

		EL3->setVelocity(ofVec3f(ofRandom(10, 40), ofRandom(-60, 60), 0));
		EL3->setRate(ofRandom(.0001, .2));
		EL3->update();

		ET1->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(10, 40), 0));
		ET1->update();

		ET2->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(10, 40), 0));
		ET2->update();
		
		ET3->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(10, 40), 0));
		ET3->update();

		ER1->setVelocity(ofVec3f(ofRandom(-10, -40), ofRandom(-60, 60), 0));
		ER1->update();

		ER2->setVelocity(ofVec3f(ofRandom(-10, -40), ofRandom(-60, 60), 0));
		ER2->update();

		ER3->setVelocity(ofVec3f(ofRandom(-10, -40), ofRandom(-60, 60), 0));
		ER3->update();

		EB1->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(-10, -40), 0));
		EB1->update();

		EB2->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(-10, -40), 0));
		EB2->update();

		EB3->setVelocity(ofVec3f(ofRandom(-60, 60), ofRandom(-10, -40), 0));
		EB3->update();

		//medium enemy velocities
		//
		ml1->setVelocity(ofVec3f(ofRandom(100, 300), ofRandom(-100, 100), 0));
		ml2->setVelocity(ofVec3f(ofRandom(100, 300), ofRandom(-100, 100), 0));
		ml3->setVelocity(ofVec3f(ofRandom(100, 300), ofRandom(-100, 100), 0));
		mt1->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(100, 300), 0));
		mt2->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(100, 300), 0));
		mt3->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(100, 300), 0));
		mr1->setVelocity(ofVec3f(ofRandom(-100, -300), ofRandom(-100, 100), 0));
		mr2->setVelocity(ofVec3f(ofRandom(-100, -300), ofRandom(-100, 100), 0));
		mr3->setVelocity(ofVec3f(ofRandom(-100, -300), ofRandom(-100, 100), 0));
		mb1->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(-100, -300), 0));
		mb2->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(-100, -300), 0));
		mb3->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(-100, -300), 0));

		//hard enemy velocities
		//
		left->setVelocity(ofVec3f(ofRandom(100, 300), ofRandom(-100, 100), 0));
		top->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(100, 300), 0));
		right->setVelocity(ofVec3f(ofRandom(-100, -300), ofRandom(-100, 100), 0));
		bottom->setVelocity(ofVec3f(ofRandom(-100, 100), ofRandom(-100, -300), 0));


		// Introduce medium enemies if score is higher than 100.
		// Reduce easy enemies spawn rate.
		float time = ofGetElapsedTimeMillis();
		if (score > 100) {
			for (int i = 0; i < mediumSpawn.size(); i++) {
				mediumSpawn[i]->setLifespan(-1);
				mediumSpawn[i]->update();
			}
			if (reduceRate1 == false) {
				EL1->setRate(EL1->rate / 2.0);
				EL2->setRate(EL2->rate / 2.0);
				EL3->setRate(EL3->rate / 2.0);
				ET1->setRate(ET1->rate / 2.0);
				ET2->setRate(ET2->rate / 2.0);
				ET3->setRate(ET3->rate / 2.0);
				ER1->setRate(ER1->rate / 2.0);
				ER3->setRate(ER2->rate / 2.0);
				ER3->setRate(ER3->rate / 2.0);
				EB1->setRate(EB1->rate / 2.0);
				EB2->setRate(EB2->rate / 2.0);
				EB3->setRate(EB3->rate / 2.0);
				reduceRate1 = true;
			}
		}

		// Introduce hard enemies if score is higher than 250.
		// Reduce medium enemies spawn rate by a little bit.
		if (score > 250) {
			for (int i = 0; i < hardEmitters.size(); i++) {
				hardEmitters[i]->setLifespan(-1);
				hardEmitters[i]->update();
			}
			if (reduceRate2 == false) {
				for (int i = 0; i < mediumSpawn.size(); i++) {
					mediumSpawn[i]->setRate(mediumSpawn[i]->rate / 2.0);
				}
				reduceRate2 = true;
			}
		}

		for (int i = 0; i < allEnemyEmitters.size(); i++) {
			rot = ofRandom(359);
			allEnemyEmitters[i]->setRotation(rot);
		}

		pEmitter.update(); 
		pEmitter.setLifespan(1);
		pEmitter.setParticleRadius(3);
		pEmitter.setRate(10);

		playerPEmitter.update();

		playerPEmitter.setPosition(ofVec3f(player->trans.x + cos(ofDegToRad(player->rot)) - (player->height / 2.3) * sin(ofDegToRad(player->rot)),
			player->trans.y + sin(ofDegToRad(player->rot)) + (player->height / 2.3)*cos(ofDegToRad(player->rot)), 0));
		playerPEmitter.setLifespan(.2);
		playerPEmitter.setParticleRadius(2);
		playerPEmitter.setRate(100);

		move();
		moveCheck();
		checkOffScreen();
		checkCollisions();

		//Reset game after it ends.
		if (gameOver) {
			for (int i = 0; i < allEnemyEmitters.size(); i++) {
				allEnemyEmitters[i]->sys->removeNear(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0), 1000);
			}
			player->setPosition(ofVec3f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2, 0));
			player->setRotation(0);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (gameStart) {
		if (!gameOver) {
			ofBackground(0, 0, 0);
			player->draw();
			ofPopMatrix();
			ofPopMatrix();
			EL1->draw();
			EL2->draw();
			EL3->draw();
			ET1->draw();
			ET2->draw();
			ET3->draw();
			ER1->draw();
			ER2->draw();
			ER3->draw();
			EB1->draw();
			EB2->draw();
			EB3->draw();

			for (int i = 0; i < mediumSpawn.size(); i++) {
				mediumSpawn[i]->draw();
			}

			for (int i = 0; i < hardEmitters.size(); i++) {
				hardEmitters[i]->draw();
			}

			pEmitter.draw();
			playerPEmitter.draw();
			ofSetColor(ofColor::white);
			string s = "Score: " + ofToString(score);
			scoreDisplay.drawString(s, ofGetWindowWidth() - scoreDisplay.stringWidth(s) - 20, 20);
		}
		if (gameOver) {
			endScreenSprite.draw();
			ofSetColor(ofColor::white);
			string s = "Final Score: " + ofToString(score);
			scoreFinalDisplay.drawString(s, (ofGetWindowWidth() / 2) - (scoreFinalDisplay.stringWidth(s) / 2), (ofGetWindowHeight() / 2));
			float time = ofGetElapsedTimeMillis();
			if (time > 5000 + timeAfterGameEnd) {
				score = 0;
				gameStart = false;
				gameOver = false;
			}
		}
	}
	else {
		beginningScreenSprite.draw();
	}
}

//--------------------------------------------------------------
void ofApp::move()
//Moves player sprite depending on MoveDir dir variable
//
{
	if (dir == MoveStop) {
		player->trans += ofVec3f(0, 0, 0);
	}
	if (dir == MoveLeft) {
		player->rot -= 4;
	}
	if (dir == MoveRight) {
		player->rot += 4;
	}
	if (dir == MoveUp) {
		if (accel < 4.5) {
			accel += .15;
		}
		if (playerPEmitter.started == false) {
			playerPEmitter.start();
		}
	}
	else {
		if (accel > 0) {
			accel -= .15;
		}
	}
	if (accel > 0) {
		player->trans += ofVec3f(accel * sin(ofDegToRad(player->rot)), -accel * cos(ofDegToRad(player->rot)), 0);
	}
}

//--------------------------------------------------------------
void ofApp::moveCheck()
{
	//Check if player emitter is within play area/window screen
	//
	if (player->trans.x - player->width / 2 < 0) {
		player->trans.x = player->width / 2;
	}
	if (player->trans.x + player->width / 2 > ofGetWindowSize().x) {
		player->trans.x = ofGetWindowSize().x - player->width / 2;
	}
	if (player->trans.y - player->height / 2 < 0) {
		player->trans.y = player->height / 2;
	}
	if (player->trans.y + player->height / 2 > ofGetWindowSize().y) {
		player->trans.y = ofGetWindowSize().y - player->height / 2;
	}
}
//--------------------------------------------------------------
void ofApp::checkOffScreen()
{
	//Check when a sprite is off screen.
	//Removes the offscreen sprite by making its lifespan = 1.
	//+/- 200 buffer since enemy emitters start outside the boundary of the screen
	for (int i = 0; i < allEmitters.size(); i++) {
		for (int j = 0; j < allEmitters[i]->sys->sprites.size(); j++) {
			if (allEmitters[i]->sys->sprites[j].trans.y + allEmitters[i]->sys->sprites[j].height < -200) {
				allEmitters[i]->sys->sprites[j].lifespan = 1;
			}
			if (allEmitters[i]->sys->sprites[j].trans.y - allEmitters[i]->sys->sprites[j].height > ofGetWindowSize().y + 200) {
				allEmitters[i]->sys->sprites[j].lifespan = 1;
			}
			if (allEmitters[i]->sys->sprites[j].trans.x + allEmitters[i]->sys->sprites[j].width > ofGetWindowSize().x + 200) {
				allEmitters[i]->sys->sprites[j].lifespan = 1;
			}
			if (allEmitters[i]->sys->sprites[j].trans.x - allEmitters[i]->sys->sprites[j].width < -200) {
				allEmitters[i]->sys->sprites[j].lifespan = 1;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::checkCollisions()
{
	//Check's collisions of missle sprite from player and enemy sprites.
	for (int j = 0; j < allEnemyEmitters.size(); j++) {
		//Loop through all enemy emitters
		float playerCollisionDist = player->height / 2 + allEnemyEmitters[j]->childHeight / 2;
		vector<int> y = allEnemyEmitters[j]->sys->removeNear(player->trans, playerCollisionDist);

		if (y[0] > 0) {
			gameOver = true;
			timeAfterGameEnd = ofGetElapsedTimeMillis();
			if (haveGameOverSound) {
				gameOverSound.play();
			}
		}

		for (int i = 0; i < player->sys->sprites.size(); i++) {
			//Loop through all player missles
			float collisionDist = player->childHeight / 2 + allEnemyEmitters[j]->childHeight / 2;
			vector<int> x = allEnemyEmitters[j]->sys->removeNear(player->sys->sprites[i].trans, collisionDist);
			int tmp = score;
			
			//If current missle near any enemy sprites, remove enemy sprite
			//using enemy sprites remove near function. 
			//Then increment score depending on amount of enemies removed.
			
			if (!gameOver) {
				//Only increment score if game is not over.
				score += x[0];
			}
			ofVec3f pos = ofVec3f(x[1], x[2], x[3]);
			
			if (score > tmp) {
				//If score goes up (missle removed an enemy/touched an enemy), remove the missle by
				//changing its lifespan to 1 and letting SpriteSystem's update function take care of the missle sprite.
				// Also play collision sound.
				if (haveCollisionSound) {
					collisionSound.play();
				}
				player->sys->sprites[i].lifespan = 1;
				pEmitter.sys->reset();
				pEmitter.setPosition(pos);
				pEmitter.start();
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == prevKey) {
		return;
	}
	prevKey = key;
	switch (key) {
		case OF_KEY_LEFT:
			dir = MoveLeft;
			break;
		case OF_KEY_RIGHT:
			dir = MoveRight;
			break;
		case OF_KEY_UP:
			dir = MoveUp;
			break;
		case OF_KEY_DOWN:
			dir = MoveDown;
			break;
		case ' ':
			if (gameStart == false) {
				timeAfterGameStart = ofGetElapsedTimeMillis();
				gameStart = true;
			}
			else {
				if (!gameOver) {
					player->setRate(3);
				}
				else {
					player->setRate(-1);
				}
			}
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
		case OF_KEY_LEFT:
			dir = MoveStop;
			prevKey = -99999;
			break;
		case OF_KEY_RIGHT:
			dir = MoveStop;
			prevKey = -99999;
			break;
		case OF_KEY_UP:
			dir = MoveStop;
			playerPEmitter.stop();
			prevKey = -99999;
			break;
		case OF_KEY_DOWN:
			dir = MoveStop;
			prevKey = -99999;
			break;
		case ' ':
			player->setRate(-1);
			prevKey = -99999;
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	//testing purposes only
	//ofPoint mouse_cur = ofPoint(x, y);
	//ofVec3f delta = mouse_cur - mouse_last;
	//player->trans += delta;
	//mouse_last = mouse_cur;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//testing purposes only
	//mouse_last = ofPoint(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
