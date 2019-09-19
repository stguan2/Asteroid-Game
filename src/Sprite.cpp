
#include "Sprite.h"

BaseObject::BaseObject() {
	trans = ofVec3f(0, 0, 0);
	scale = ofVec3f(1, 1, 1);
	rot = 0;
}

void BaseObject::setPosition(ofVec3f pos) {
	trans = pos;
}

void BaseObject::setRotation(float r) {
	rot = r;
}

//
// Basic Sprite Object
//
Sprite::Sprite() {
	speed = 0;
	score = 0;
	velocity = ofVec3f(0, 0, 0);
	lifespan = -1;      // lifespan of -1 => immortal 
	birthtime = 0;
	bSelected = false;
	haveImage = false;
	haveSound = false;
	name = "UnamedSprite";
	width = 20;
	height = 20;
}

// Return a sprite's age in milliseconds
//
float Sprite::age() {
	return (ofGetElapsedTimeMillis() - birthtime);
}

//  Set an image for the sprite. If you don't set one, a rectangle
//  gets drawn.
//
void Sprite::setImage(ofImage img) {
	image = img;
	haveImage = true;
	width = image.getWidth();
	height = image.getHeight();
}

// Set a sound for the sprite when spawned. If no sound is provided, 
// the spirte will not play any sounds.
//
void Sprite::setSound(ofSoundPlayer sound) {
	soundPlayer = sound;
	soundPlayer.setMultiPlay(true);
	haveSound = true;
}

// Play its sound
//
void Sprite::playSound() {
	if (haveSound) {
		soundPlayer.play();
	}
}

// Render the sprite
//
void Sprite::draw() {

	ofSetColor(255, 255, 255, 255);

	// draw image centered and add in translation amount and rotation amount
	//
	if (haveImage) {

		ofPushMatrix();
			ofTranslate(trans.x, trans.y, 0);
			ofRotate(rot, 0, 0, 1);
			ofPushMatrix();
				ofTranslate(-trans.x, -trans.y, 0);
				image.draw(-width / 2.0 + trans.x, -height / 2.0 + trans.y);
			ofPopMatrix();
		ofPopMatrix();
	}
	else {
		// in case no image is supplied, draw something.
		// 
		ofNoFill();
		ofSetColor(255, 255, 255);
		ofDrawRectangle(-width / 2.0 + trans.x, -height / 2.0 + trans.y, width, height);
	}
}

//  Add a Sprite to the Sprite System
//
void SpriteSystem::add(Sprite s) {
	sprites.push_back(s);
}

// Remove a sprite from the sprite system. Note that this function is not currently
// used. The typical case is that sprites automatically get removed when the reach
// their lifespan.
//
void SpriteSystem::remove(int i) {
	sprites.erase(sprites.begin() + i);
}

// remove all sprites within a given dist of point
//
vector<int> SpriteSystem::removeNear(ofVec3f point, float dist) {
	vector<Sprite>::iterator s = sprites.begin();
	vector<Sprite>::iterator tmp;
	vector<int> x;
	ofVec3f pos = ofVec3f(0, 0, 0);
	int count = 0;

	while (s != sprites.end()) {
		ofVec3f v = s->trans - point;
		if (v.length() < dist) {
			pos = s->trans;
			count += s->score;
			tmp = sprites.erase(s);
			s = tmp;
		}
		else s++;
	}
	x.push_back(count);
	x.push_back(pos.x);
	x.push_back(pos.y);
	x.push_back(pos.z);
	return x;
}


//  Update the SpriteSystem by checking which sprites have exceeded their
//  lifespan (and deleting).  Also the sprite is moved to it's next
//  location based on velocity and direction.
//
void SpriteSystem::update() {

	if (sprites.size() == 0) return;
	vector<Sprite>::iterator s = sprites.begin();
	vector<Sprite>::iterator tmp;

	// check which sprites have exceed their lifespan and delete
	// from list.  When deleting multiple objects from a vector while
	// traversing at the same time, use an iterator.
	//
	while (s != sprites.end()) {
		if (s->lifespan != -1 && s->age() > s->lifespan) {
						//cout << "deleting sprite: " << s->name << endl;
			tmp = sprites.erase(s);
			s = tmp;
		}
		else s++;
	}

	//  Move sprite
	//
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].trans += sprites[i].velocity / ofGetFrameRate();
	}

}

//  Render all the sprites
//
void SpriteSystem::draw() {
	for (int i = 0; i < sprites.size(); i++) {
		sprites[i].draw();
	}
}