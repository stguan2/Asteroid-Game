#pragma once

#include "ofMain.h"

// This is a base object that all drawable object inherit from
// It is possible this will be replaced by ofNode when we move to 3D
//
class BaseObject {
public:
	BaseObject();
	ofVec2f trans, scale;
	float	rot;
	bool	bSelected;
	void setPosition(ofVec3f);
	void setRotation(float);
};

//  General Sprite class  (similar to a Particle)
//
class Sprite : public BaseObject {
public:
	Sprite();
	void draw();
	float age();
	void setImage(ofImage);
	void setSound(ofSoundPlayer);
	void playSound();
	float speed;    //   in pixels/sec
	ofVec3f velocity; // in pixels/sec
	ofImage image;
	ofSoundPlayer soundPlayer;
	float birthtime; // elapsed time in ms
	float lifespan;  //  time in ms
	int score; // score returned after removenear funtion
	string name;
	bool haveImage;
	bool haveSound;
	float width, height;
};

//  Manages all Sprites in a system.  You can create multiple systems
//
class SpriteSystem {
public:
	void add(Sprite);
	void remove(int);
	void update();
	void draw();
	vector<int> removeNear(ofVec3f point, float dist);
	vector<Sprite> sprites;

};