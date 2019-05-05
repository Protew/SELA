/*
 *  MainWindow.cpp
 *  Function_2o
 *
 *  Created by PRoTeW on 29/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "MainWindow.h"

MainWindow :: MainWindow( void )
{
	initComponents();
	setWindowTitle( tr( " SELA ANALYZER " ) );
}
void MainWindow :: keyPressEvent( QKeyEvent * event )
{
	createMatrix();
	event->accept();
}
//SETS
//GETS
void MainWindow :: createMatrix( void )
{
    if( sela_widget != nullptr )
		delete sela_widget;
	sela_widget = new QSela( this, dsb_setter_dimension->value() );
	main_layout->update();
	upper_layout->addWidget( sela_widget );
	connect( btn_output, SIGNAL( clicked() ), sela_widget, SLOT( showOutput() ) );
    base_buttons_layout->addWidget( btn_output );
}
void MainWindow :: initComponents( void )
{
	//BUTTONS LAYOUT
	base_buttons_layout = new QHBoxLayout;
	//
	//MATRIX INICIALIZER
	dsb_setter_dimension	=	new QSpinBox();
	dsb_setter_dimension->setRange( 2, 5000 );
	dsb_setter_dimension->setValue( 2 );
	dsb_setter_dimension->setSingleStep( 1 );
	base_buttons_layout->addWidget( dsb_setter_dimension );
	//
	//BTN CREATE
    btn_create	=	new QPushButton("CREATE");
	connect( btn_create, SIGNAL( clicked() ), this, SLOT( createMatrix() ) );
	base_buttons_layout->addWidget( btn_create );
	//
	//BTN OUTPUT
	btn_output = new QPushButton("OUTPUT");
	//
	upper_layout  = new QHBoxLayout; 
    sela_widget = nullptr;
	//
	//
	//MAIN LAYOUT
	//
	main_layout = new QVBoxLayout;
	main_layout->addLayout( upper_layout );
	main_layout->addLayout( base_buttons_layout );
	setLayout( main_layout );
}
