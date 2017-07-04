#pragma once
#include "Tetromino.h"

class TetrominoI :
	public Tetromino
{
public:
	TetrominoI();
	~TetrominoI();
	int rotar();
	//int** getForma();
	void generarFormas();
	struct {
		int pos0[tetroHeight][tetroWidth] = { 
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 1,1,1,1 },
			{ 0,0,0,0 } };
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 },
			{ 0,1,0,0 } };
	}posiciones;
private:
	
};

class TetrominoJ :
	public Tetromino
{
public:
	TetrominoJ();
	~TetrominoJ();
	int rotar();
	//int** getForma();
	void generarFormas();
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,2,0,0 },
			{ 0,2,2,2 } };
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,2,0 },
			{ 0,0,2,0 },
			{ 0,2,2,0 } };
		int pos2[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,2,2,2 },
			{ 0,0,0,2 } };
		int pos3[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,2,2,0 },
			{ 0,2,0,0 },
			{ 0,2,0,0 } };

	}posiciones;
private:
	
};

class TetrominoL :
	public Tetromino
{
public:
	TetrominoL();
	~TetrominoL();
	int rotar();
	//int** getForma();
	void generarFormas();
private:
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,0,3 },
			{ 0,3,3,3 } };
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,3,0,0 },
			{ 0,3,0,0 },
			{ 0,3,3,0 } };
		int pos2[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,3,3,3 },
			{ 0,3,0,0 } };
		int pos3[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,3,3,0 },
			{ 0,0,3,0 },
			{ 0,0,3,0 } };
	}posiciones;
};

class TetrominoO :
	public Tetromino
{
public:
	TetrominoO();
	~TetrominoO();
	int rotar();
	//int** getForma();
	void generarFormas();
private:
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,4,4,0 },
			{ 0,4,4,0 } };
		
	}posiciones;
};

class TetrominoS :
	public Tetromino
{
public:
	TetrominoS();
	~TetrominoS();
	int rotar(); 
	//int** getForma();
	void generarFormas();
private:
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,0,5,5 },
			{ 0,5,5,0 } };
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,5,0,0 },
			{ 0,5,5,0 },
			{ 0,0,5,0 } };
	}posiciones;
};

class TetrominoT :
	public Tetromino
{
public:
	TetrominoT();
	~TetrominoT();
	int rotar();
	//int** getForma();
	void generarFormas();
private:
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,6,6,6 },
			{ 0,0,6,0 } };
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,6,0 },
			{ 0,0,6,6 },
			{ 0,0,6,0 } };
		int pos2[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,6,0 },
			{ 0,6,6,6 },
			{ 0,0,0,0 } };
		int pos3[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,6,0 },
			{ 0,6,6,0 },
			{ 0,0,6,0 } };
	}posiciones;
};

class TetrominoZ :
	public Tetromino
{
public:
	TetrominoZ();
	~TetrominoZ();
	int rotar();
	//int** getForma();
	void generarFormas();
private:
	struct {
		int pos0[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,0,0 },
			{ 0,7,7,0 },
			{ 0,0,7,7 }
		};
		int pos1[tetroHeight][tetroWidth] = {
			{ 0,0,0,0 },
			{ 0,0,7,0 },
			{ 0,7,7,0 },
			{ 0,7,0,0 } };
	}posiciones;
};



