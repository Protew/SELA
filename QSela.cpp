/*
 *  QSela.cpp
 *  SELA
 *
 *  Created by PRoTeW on 11/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "QSela.h"
#include <iostream>

QSela :: QSela( QWidget * parent, int Dimension )
: QGroupBox( parent )
{
	dimension = Dimension;
	initComponents();
}
void QSela :: keyPressEvent( QKeyEvent * event )
{
	showOutput();
	std::cout << "PRESS " << event->key() << std::endl;
	event->accept();
}
//SETS
//GETS
void QSela :: showOutput( void )
{
	//ROUND JACOBI
	//round++;
	//x_iterations.push_back( matrix_a->roundJacobi( x_iterations[ x_iterations.size() - 1 ], matrix_b ) );
	//std::cout << "STEP " << round << ":\n"<< x_iterations[ x_iterations.size() - 1 ]->showMatrix() << std::endl;
	//matrix_a->prepareGauss( matrix_b );
	output_viewer = new QOutputViewer( 0, matrix_a, matrix_b );
	output_viewer->show();
}
void QSela :: setMatrixAValue( int i, int j, double value )
{
	matrix_a->setValue( i, j, value );
}
void QSela :: setMatrixBValue( int i, int j, double value )
{
	matrix_b->setValue( i, j, value );
}
void QSela :: initComponents( void )
{
	round =		0;
	error =		0;
	//
	//OPTIONS LAYOUT
	//
	options_layout = new QHBoxLayout;
	//
	//VALUES
	values_layout = new QGridLayout;
	//
	//
	//MATRIX A
	matrix_a = matrix_b = new DoubleMatrix( dimension, dimension );
	//
	//SYSTEM MATRIXES
	matrix_x0 = matrix_aproximated_x = matrix_x = matrix_b = new DoubleMatrix( dimension, 1 );
	//
	//
	int pos_y;
	for ( int i = 0; i < dimension; i++ ) {
		for ( int j = 0; j < dimension; j++ ) {
			QValueSetter * constant_value_setter = new QValueSetter( this, i, j, dimension, true );
			connect( constant_value_setter->getValueSetter(), SIGNAL( valueChanged( double ) ), constant_value_setter, SLOT( valueSetted( double ) ) );
			connect( constant_value_setter, SIGNAL( emitIndexes( int, int, double ) ), this, SLOT( setMatrixAValue( int, int, double ) ) );
			values_layout->addWidget( constant_value_setter, i, j );
			pos_y = j;
		}
		lbl_equal = new QLabel("=");
		values_layout->addWidget( lbl_equal, i, pos_y + 1 );
		QValueSetter * result_value_setter = new QValueSetter( this, i, 0, dimension, false );
		connect( result_value_setter->getValueSetter(), SIGNAL( valueChanged( double ) ), result_value_setter, SLOT( valueSetted( double ) ) );
		connect( result_value_setter, SIGNAL( emitIndexes( int, int, double ) ), this, SLOT( setMatrixBValue( int, int, double ) ) );
		values_layout->addWidget( result_value_setter, i, pos_y + 2 );
	}
	main_layout = new QVBoxLayout;
	main_layout->addLayout( options_layout );
	main_layout->addLayout( values_layout );
	setLayout( main_layout );
}
