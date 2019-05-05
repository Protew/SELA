/*
 *  CalcTable.cpp
 *  SELA
 *
 *  Created by PRoTeW on 16/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "CalcTable.h"

CalcTable :: CalcTable( QWidget * parent, DoubleMatrix * A, DoubleMatrix * B )
: QTextBrowser( parent )
{
	matrix_a = A;
	matrix_b = B;
	initComponents();
}
//SETS
void CalcTable :: setX0Value( int i, double value )
{
	matrix_a->getX0()->setValue( i, 0, value );
}
void CalcTable :: setX0( void )
{
	matrix_a->addIteraction( matrix_a->getX0() );
}
void CalcTable :: setError( double value )
{
	matrix_a->setError( value );
}
//GETS

void CalcTable :: methodChanged( int choosen )
{
	matrix_a->clearIteractions();
	matrix_a->setOutput("");
	matrix_a->setRound( 0 );
	matrix_a->setSolved( false );
	accept_input = true;
	first_iteration = true;
	method = (CHOOSEN_METHOD) choosen;
	switch ( method ) {
		case GAUSS:
			matrix_a->prepareGauss( matrix_b );
			setText( matrix_a->getOutput().c_str() );
			break;
		case GAUSS_JORDAN:
			matrix_a->prepareGauss( matrix_b );
			setText( matrix_a->getOutput().c_str() );
			break;
		case GAUSS_SEIDL:
			break;
		case JACOBI:
			matrix_a->setRound( 0 );
			if( matrix_a->isDiagonallyDominant() )
				setText( "DEFINE X0 AND ERROR" );
			else {
				matrix_a->addOutput( "MATRIX A Do NOT CONVERGE" );
				matrix_a->transformDiagonallyDominant();
			}
			break;
	}
	setText( matrix_a->getOutput().c_str() );
	//repaint();
}
void CalcTable :: doCalcStep( void )
{
	switch ( method ) {
		case GAUSS:
			matrix_a->roundGauss();
			break;
		case GAUSS_JORDAN:
			matrix_a->roundGaussJordan();
			break;
		case GAUSS_SEIDL:
			break;
		case JACOBI:
			if( first_iteration )
			{
                QIterativeParameters * iterative_input = new QIterativeParameters( nullptr, matrix_a->getLines() );
                connect( iterative_input->getOkButton(), SIGNAL( clicked() ), this, SLOT( setX0() ) );
                connect( iterative_input->getOkButton(), SIGNAL( clicked() ), iterative_input, SLOT( close()) );
				connect( iterative_input, SIGNAL( emitX0Value( int, double ) ), this, SLOT( setX0Value( int, double ) ) );
				connect( iterative_input, SIGNAL( emitErrorValue( double ) ), this, SLOT( setError( double ) ) );
				iterative_input->show();
				first_iteration = false;
			}
			else {
				matrix_a->roundJacobi( matrix_a->getIteractions()[ matrix_a->getRound() ], matrix_b );
			}
			break;
	}
	if( accept_input )
		setText( matrix_a->getOutput().c_str() );
	if( matrix_a->isSolved() )
		accept_input = false;
}
void CalcTable :: initComponents( void )
{
	first_iteration = true;
	accept_input = true;
	matrix_a->getX0();
	methodChanged( GAUSS );
}
