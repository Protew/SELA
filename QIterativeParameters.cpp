/*
 *  QIterativeParameters.cpp
 *  SELA
 *
 *  Created by PRoTeW on 17/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "QIterativeParameters.h"

QIterativeParameters :: QIterativeParameters( QWidget * parent, int L )
: QWidget( parent )
{
	lines = L;
	initComponents();
}
void QIterativeParameters :: closeEvent( QCloseEvent * event )
{
	event->accept();
	
}
//SETS
void QIterativeParameters :: setX0Value( int i, int j, double value )
{
	//delete &j;
	emit emitX0Value( i, value );
}
void QIterativeParameters :: setError( int i, int j, double value )
{
	//delete &i;
	//delete &j;
	emit emitErrorValue( value );
}
//GETS
QPushButton* QIterativeParameters :: getOkButton( void )
{
	return btn_ok;
}
void QIterativeParameters :: initComponents( void )
{
	//
	main_layout = new QHBoxLayout;
	//
	//QVBoxLayout*		x0_layout;
	//QVBoxLayout*		error_layout;
	//SPB VALUE SETTER
	//
	//X0 LAYOUT
	x0_layout = new QVBoxLayout;
	//
	for ( int line = 0; line < lines; line++ ) {
		QValueSetter * x0_value_setter = new QValueSetter( this, line, 0, 1, true );
		connect( x0_value_setter->getValueSetter(), SIGNAL( valueChanged( double ) ), x0_value_setter, SLOT( valueSetted( double ) ) );
		connect( x0_value_setter, SIGNAL( emitIndexes( int, int, double ) ), this, SLOT( setX0Value( int, int, double ) ) );
		x0_layout->addWidget( x0_value_setter );
	}
	//
	//ERROR LAYOUT
	//
	error_layout = new QVBoxLayout;
	//
	QValueSetter * error_value_setter = new QValueSetter( this, 0, 0, 1, false );
	connect( error_value_setter->getValueSetter(), SIGNAL( valueChanged( double ) ), error_value_setter, SLOT( valueSetted( double ) ) );
	connect( error_value_setter, SIGNAL( emitIndexes( int, int, double ) ), this, SLOT( setError( int, int, double ) ) );
	error_layout->addWidget( error_value_setter );
	//
	//BTN OK
	//
	btn_ok = new QPushButton( "OK" );
	error_layout->addWidget( btn_ok );
	//
	//MAIN LAYOUT
	//
	main_layout = new QHBoxLayout;
	main_layout->addLayout( x0_layout );
	main_layout->addLayout( error_layout );
	setLayout( main_layout );
}
