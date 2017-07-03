#pragma once
#include "Tetromino.h"

class TetrominoI :
	public Tetromino
{
public:
	TetrominoI();
	~TetrominoI();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
	}posiciones;
};

class TetrominoJ :
	public Tetromino
{
public:
	TetrominoJ();
	~TetrominoJ();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
		int pos3[height][width];
		int pos4[height][width];
	}posiciones;
};

class TetrominoL :
	public Tetromino
{
public:
	TetrominoL();
	~TetrominoL();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
		int pos3[height][width];
		int pos4[height][width];
	}posiciones;
};

class TetrominoO :
	public Tetromino
{
public:
	TetrominoO();
	~TetrominoO();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
	}posiciones;
};

class TetrominoS :
	public Tetromino
{
public:
	TetrominoS();
	~TetrominoS();
	int rotar(); 
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
	}posiciones;
};

class TetrominoT :
	public Tetromino
{
public:
	TetrominoT();
	~TetrominoT();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
		int pos3[height][width];
		int pos4[height][width];
	}posiciones;
};

class TetrominoZ :
	public Tetromino
{
public:
	TetrominoZ();
	~TetrominoZ();
	int rotar();
	int** getForma();
	void generarFormas();
private:
	struct {
		int pos1[height][width];
		int pos2[height][width];
	}posiciones;
};



