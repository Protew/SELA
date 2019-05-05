/*
 *  QValueSetter.cpp
 *  SELA
 *
 *  Created by PRoTeW on 11/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "QValueSetter.h"

QValueSetter :: QValueSetter( QWidget * parent, int L, int C, int D, bool LABEL )
: QWidget( parent )
{
	line = L;
	column = C;
	parent_dimension = D;
	labeled = LABEL;
	initComponents();
}
//SETS
//GETS
QDoubleSpinBox* QValueSetter :: getValueSetter( void )
{
	return dsb_value_setter;
}

void QValueSetter :: valueSetted( double V )
{
	value = V;
	emit emitIndexes( line, column, value );
}
void QValueSetter :: initComponents( void )
{
	//
	main_layout = new QGridLayout;
	//
	//SPB VALUE SETTER
	dsb_value_setter = new QDoubleSpinBox;
	dsb_value_setter->setRange( -5000, 5000 );
	dsb_value_setter->setValue( 0.0 );
	dsb_value_setter->setSingleStep( 0.1 );
	main_layout->addWidget( dsb_value_setter, 0, 0 );
	//
	//
	if( labeled )
	{
		char label_name[10];
		sprintf( label_name, "X%d", column + 1 );
		lbl_variable_name = new QLabel( label_name );
		main_layout->addWidget( lbl_variable_name, 0, 1 );
	}
	
	
	setLayout( main_layout );
}
