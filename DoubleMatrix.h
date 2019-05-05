/*
 *  DoubleMatrix.h
 *  SELA
 *
 *  Created by PRoTeW on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef DOUBLEMATRIX_H
#define DOUBLEMATRIX_H

#include <iostream>
#include <vector>

enum CHOOSEN_METHOD{ GAUSS = 0, GAUSS_JORDAN = 1, GAUSS_SEIDL = 2, JACOBI = 3 };

class DoubleMatrix
{
	int					lines;
	int					columns;
	int					pivot_line;
	int					round;
	double				error;
	double**			matrix;
	DoubleMatrix*		x0;
	std::vector<DoubleMatrix*> iteractions_x;
	DoubleMatrix*		auxiliar;
	DoubleMatrix*		extended;
	DoubleMatrix*		ldu;
	DoubleMatrix*		inverse;
	DoubleMatrix*		diagonal;
	DoubleMatrix*		cofactor;
	DoubleMatrix*		identity;
	DoubleMatrix*		transpose;
	
	std::string			output;
	bool				solved;
	
public:
	DoubleMatrix( int, int );
	void createAuxiliar( void );
	//SETS
	void addIteraction( DoubleMatrix* );
	void setRound( int );
	void setValue( int, int, double );
	void setPivotLine( int );
	void setOutput( std::string );
	void setError( double );
	void setSolved( bool );
	//GETS
	std::vector<DoubleMatrix*> getIteractions( void );
	int getRound( void );
	std::string getOutput( void );
	int getPivotLine( void );
	int getLines( void );
	int getColumns( void );
	double** getMatrix( void );
	double getValue( int, int );
	bool isIdentity( void );
	bool isSingular( void );
	bool isSolved( void );
	bool hasZeroDiagonal( void );
	bool isInferiorTriangle( void );
	bool isDiagonallyDominant( void );
	double getDet( void );
	double getError( void );
	DoubleMatrix* getX0( void );
	DoubleMatrix* getLDU( void );
	DoubleMatrix* getInverse( void );
	DoubleMatrix* getAuxiliar( void );
	DoubleMatrix* getDiagonal( void );
	DoubleMatrix* getCofactor( void );
	DoubleMatrix* getIdentity( void );
	DoubleMatrix* getTranspose( void );
	DoubleMatrix* getComplementar( int, int );
	DoubleMatrix* getExtendedMatrix( DoubleMatrix* );
	double* getLineMultiplied( int, double );
	int getNextAvailablePivotLine( void );
	void addOutput( std::string );
	void clearIteractions( void );
	//
	void transformDiagonallyDominant( void );
	//
	//CALCULATION COMMANDS
	//
	std::string swapLines( int, int );
	std::string swapColumns( int, int );
	std::string multiplyLine( int, double );
	std::string sumLines( double*, int );
	//
	//
	//GAUSS
	void prepareGauss( DoubleMatrix* );
	//
	//GAUSS JORDAN
	//
	void roundGauss( void );
	void roundGaussJordan( void );
	//
	//JACOBI
	void roundJacobi( DoubleMatrix*, DoubleMatrix* );
	//
	//OPERATORS
	//
	DoubleMatrix* sumMatrix( DoubleMatrix* );
	DoubleMatrix* multMatrix( double );
	DoubleMatrix* multMatrix( DoubleMatrix* );
	bool equals( DoubleMatrix* );
	double distanceTo( DoubleMatrix* );
	//
	std::string showMatrix( void );
	//
};

#endif