#pragma once

class Renderer;

class Renderer
{
public:
	Renderer();
	~Renderer();

	/*render to PPM file*/
	bool renderPPM();

private:
	int imageWidth;
	int imageHeight;
};