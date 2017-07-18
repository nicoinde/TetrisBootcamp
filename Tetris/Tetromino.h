#pragma once

class Tetromino
{
public:
	Tetromino();
	virtual ~Tetromino();
	int rotate();
	int rotateInversed();
	void setRotation(int ind);
	virtual int getRotation();
	virtual void resetRotation();
	virtual int getCell(int x, int y) = 0;
	unsigned getTetroWidth();
	unsigned getTetroHeight();


protected:
	static const short tetroWidth = 4;
	static const short tetroHeight = 4;
	int cantRotPosibles;
	int currentRotation;
	
	
};

