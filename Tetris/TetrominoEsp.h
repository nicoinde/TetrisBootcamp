#pragma once
#include "Tetromino.h"

class TetrominoI :
	public Tetromino
{
public:
	TetrominoI();
	~TetrominoI();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
	
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	
};

class TetrominoJ :
	public Tetromino
{
public:
	TetrominoJ();
	~TetrominoJ();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
	
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	int pos2[tetroHeight][tetroWidth];
	int pos3[tetroHeight][tetroWidth];
};

class TetrominoL :
	public Tetromino
{
public:
	TetrominoL();
	~TetrominoL();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	int pos2[tetroHeight][tetroWidth];
	int pos3[tetroHeight][tetroWidth];
};

class TetrominoO :
	public Tetromino
{
public:
	TetrominoO();
	~TetrominoO();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
private:
	int pos0[tetroHeight][tetroWidth];

};

class TetrominoS :
	public Tetromino
{
public:
	TetrominoS();
	~TetrominoS();
	int rotar(); 
	int getCelda(int x, int y);
	void generarFormas();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
};

class TetrominoT :
	public Tetromino
{
public:
	TetrominoT();
	~TetrominoT();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
	int pos2[tetroHeight][tetroWidth];
	int pos3[tetroHeight][tetroWidth];
};

class TetrominoZ :
	public Tetromino
{
public:
	TetrominoZ();
	~TetrominoZ();
	int rotar();
	int getCelda(int x, int y);
	void generarFormas();
private:
	int pos0[tetroHeight][tetroWidth];
	int pos1[tetroHeight][tetroWidth];
};



