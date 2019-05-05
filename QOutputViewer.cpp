/*
 *  QOutputViewer.cpp
 *  SELA
 *
 *  Created by PRoTeW on 14/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "QOutputViewer.h"

QOutputViewer :: QOutputViewer( QWidget * parent, DoubleMatrix * A, DoubleMatrix * B  )
: QWidget( parent )
{
	matrix_a = A;
	matrix_b = B;
	initComponents();
	repaint();
}
//SETS
//GETS
std::string QOutputViewer :: selaPatternOutput( void )
{
	std::string output = "";
	char part[20];
	for ( int i = 0; i < matrix_a->getLines(); i++ ) {
		for ( int j = 0; j < matrix_a->getColumns(); j++ ) {
			if( j == 0 )
				output += "| ";
			sprintf(part, "%.2f ", matrix_a->getValue(i, j));
			output += part;
		}
		output += " | ";
		if( i == 0 )
			output += "x";
		else
			output += "  ";
		sprintf( part, " | X%d | ", i+1 );
		output += part;
		if( i == 0 )
			output += "=";
		else
			output += "  ";	
		sprintf( part, " | %.2f | ", matrix_b->getValue(i, 0));
		output += part;
		output += "\n";
	}
	return output;
}
void QOutputViewer :: paintEvent( QPaintEvent * event )
{
	event->accept();
}
void QOutputViewer :: setSela( void )
{
	operation_viewer->setMainMatrix( matrix_a->getExtendedMatrix( matrix_b ) );
}
void QOutputViewer :: setA( void )
{
	operation_viewer->setMainMatrix( matrix_a );
}
void QOutputViewer :: setB( void )
{
	operation_viewer->setMainMatrix( matrix_b );
}
void QOutputViewer :: setDet( void )
{
	DoubleMatrix* det = new DoubleMatrix( 1, 1 );
	det->setValue( 0, 0, matrix_a->getDet() );
	operation_viewer->setMainMatrix( det );
}
void QOutputViewer :: setInverse( void )
{
	operation_viewer->setMainMatrix( matrix_a->getInverse() );
}
void QOutputViewer :: setTranpose( void )
{
	operation_viewer->setMainMatrix( matrix_a->getTranspose() );
}
void QOutputViewer :: setCofactor( void )
{
	operation_viewer->setMainMatrix( matrix_a->getCofactor() );
}
void QOutputViewer :: setIdentity( void )
{
	operation_viewer->setMainMatrix( matrix_a->getIdentity() );
}
void QOutputViewer :: setDiagonal( void )
{
	operation_viewer->setMainMatrix( matrix_a->getDiagonal() );
}
void QOutputViewer :: initComponents( void )
{
	//
	sela_layout = new QHBoxLayout;
	//
	//SELA VIEWER
	sela_viewer = new QMatrixViewer( this, matrix_a, matrix_b, true );
	sela_viewer->setFixedSize( ( matrix_a->getColumns() + 4 ) * 100 + 20, 10 + matrix_a->getLines() * 20 );
	sela_layout->addWidget( sela_viewer ); 
	//
	//OPTIONS LAYOUT
	//
	operations_layout = new QVBoxLayout;
	//
	//
	lbl_a	= new QLabel("<a href=' '>Matrix A</a>");
	connect( lbl_a, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setA() ) );
	operations_layout->addWidget( lbl_a );
	//
	lbl_b	= new QLabel("<a href=' '>Matrix B</a>");
	connect( lbl_b, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setB() ) );
	operations_layout->addWidget( lbl_b );
	//
	lbl_det	= new QLabel("<a href=' '>Determinant</a>");
	connect( lbl_det, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setDet() ) );
	operations_layout->addWidget( lbl_det );
	//
	lbl_inverse	= new QLabel("<a href=' '>Inverse</a>");
	connect( lbl_inverse, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setInverse() ) );
	operations_layout->addWidget( lbl_inverse );
	//
	lbl_transpose	= new QLabel("<a href=' '>Transpose</a>");
	connect( lbl_transpose, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setTranpose() ) );
	operations_layout->addWidget( lbl_transpose );
	//
	lbl_cofactor	= new QLabel("<a href=' '>Co-factor</a>");
	connect( lbl_cofactor, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setCofactor() ) );
	operations_layout->addWidget( lbl_cofactor );
	//
	lbl_identity	= new QLabel("<a href=' '>Identity</a>");
	connect( lbl_identity, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setIdentity() ) );
	operations_layout->addWidget( lbl_identity );
	//
	lbl_diagonal	= new QLabel("<a href=' '>Diagonal</a>");
	connect( lbl_diagonal, SIGNAL( linkActivated( const QString& ) ), this, SLOT( setDiagonal() ) );
	operations_layout->addWidget( lbl_diagonal );
	//
	//OPERATION VIEWER
	//
	operation_viewer = new QMatrixViewer( this, matrix_a );
	operation_viewer->setFixedSize( 20 + matrix_a->getColumns() * 100, 10 + matrix_a->getLines() * 20 );
	operations_layout->addWidget( operation_viewer );
	//
	//CALCU OPTIONS LAYOUT
	//
	calc_options_layout = new QHBoxLayout;
	//
	//CALC OPTIONS LIST
	//
	lv_calc_options = new QComboBox;
	lv_calc_options->insertItem(0, "GAUSS" );
	lv_calc_options->insertItem(1, "GAUSS-JORDAN" );
	lv_calc_options->insertItem(2, "GAUSS-SEIDL" );
	lv_calc_options->insertItem(3, "JACOBI" );
	calc_options_layout->addWidget( lv_calc_options );
	//
	//BTN CALC
	//
	btn_calc = new QPushButton( "CALC" );
	calc_options_layout->addWidget( btn_calc );
	//
	//
	//
	//CALCULATIONS LAYOUT
	//
	calculations_layout = new QVBoxLayout;
	calculations_layout->addLayout( calc_options_layout );
	//
	//CALC TABLE
	calc_table = new CalcTable( this, matrix_a, matrix_b );
	calc_table->setLineWrapMode( QTextEdit::NoWrap );
	calc_table->setFixedSize( 500, 500 );
	connect( lv_calc_options, SIGNAL( currentIndexChanged( int ) ), calc_table, SLOT( methodChanged( int ) ) );
	connect( btn_calc, SIGNAL( clicked() ), calc_table, SLOT( doCalcStep() ) );
	calculations_layout->addWidget( calc_table );
	//
	lv_calc_options->setFixedSize( 250, 30 );
	//
	//VIEWERS LAYOUT
	viewers_layout = new QHBoxLayout;
	viewers_layout->addLayout( operations_layout );
	viewers_layout->addLayout( calculations_layout );
	//
	//MAIN LAYOUT
	main_layout = new QVBoxLayout;
	main_layout->addLayout( sela_layout );
	main_layout->addLayout( viewers_layout );
	setLayout( main_layout );
}