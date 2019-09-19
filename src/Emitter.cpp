


#include "ofMain.h"
#include "Emitter.h"



//  Create a new Emitter - needs a SpriteSystem
//
Emitter::Emitter(SpriteSystem *spriteSys) {
	sys = spriteSys;
	lifespan = -1;    // milliseconds (-1 lifespan -> live forever)
	score = 0;
	started = false;
	lastSpawned = 0;
	rate = 1;    // sprites/sec (-1 rate -> no spawn)
	haveChildImage = false;
	haveChildSoundPlayer = false;
	haveImage = false;
	velocity = ofVec3f(0, 100, 0);
	drawable = true;
	width = 50;
	height = 50;
	childWidth = 10;
	childHeight = 10;
}

//  Draw the Emitter if it is drawable. In many cases you would want a hidden emitter
//
//
void Emitter::draw() {
	if (drawable) {

		if (haveImage) {
			ofSetColor(255, 255, 255);
			ofPushMatrix();
				ofTranslate(trans.x, trans.y, 0);
				ofRotate(rot, 0, 0, 1);
				ofPushMatrix();
					ofTranslate(-trans.x, -trans.y, 0);
					image.draw(-image.getWidth() / 2.0 + trans.x, -image.getHeight() / 2.0 + trans.y);
				ofPopMatrix();
			ofPopMatrix();
		}
		else {
			ofSetColor(255, 255, 255);
			ofFill();
			ofDrawRectangle(-width / 2 + trans.x, -height / 2 + trans.y, width, height);
		}
	}

	// draw sprite system
	//
	sys->draw();
}

//  Update the Emitter to spawn sprites. If it has been started, 
//  spawn new sprites with initial velocity, lifespan, birthtime.
//
void Emitter::update() {
	if (!started) return;

	float time = ofGetElapsedTimeMillis();
	if (rate != -1 && (time - lastSpawned) > (1000.0 / rate)) {
		// spawn a new sprite
		Sprite sprite;
		if (haveChildImage) sprite.setImage(childImage);
		if (haveChildSoundPlayer) sprite.setSound(childSoundPlayer);
		sprite.playSound();
		sprite.velocity = velocity;
		sprite.lifespan = lifespan;
		sprite.setPosition(trans);
		sprite.setRotation(rot);
		sprite.birthtime = time;
		sprite.width = childWidth;
		sprite.height = childHeight;
		sprite.score = score;
		sys->add(sprite);
		lastSpawned = time;
	}
	sys->update();
}

// Start/Stop the emitter.
//
void Emitter::start() {
	started = true;
	lastSpawned = ofGetElapsedTimeMillis();
}

void Emitter::stop() {
	started = false;
}

// set lifespan of sprites spawned by emitter
//
void Emitter::setLifespan(float life) {
	lifespan = life;
}

// set velocity of sprites spawned by emitter
//
void Emitter::setVelocity(ofVec3f v) {
	velocity = v;
}

// set image of sprites spawned by emitter
//
void Emitter::setChildImage(ofImage img) {
	childImage = img;
	haveChildImage = true;
	childWidth = img.getWidth();
	childHeight = img.getHeight();
}

// set sound of sprites spawned by emitter
//
void Emitter::setChildSoundPlayer(ofSoundPlayer sound) {
	childSoundPlayer = sound;
	haveChildSoundPlayer = true;
}

// set image of emitter
//
void Emitter::setImage(ofImage img) {
	image = img;
	haveImage = true;
}

// set rate of sprites spawned by emitter
//
void Emitter::setRate(float r) {
	rate = r;
}

// set max distance each sprite can go per frame 
// depending on velocity spawned by emitter
//
float Emitter::maxDistPerFrame() {
	return  velocity.length() / ofGetFrameRate();
}