/*
 *  QMatrixViewer.cpp
 *  SELA
 *
 *  Created by PRoTeW on 14/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "QMatrixViewer.h"

QMatrixViewer :: QMatrixViewer( QWidget * parent )
: QFrame( parent )
{
	matrix_a = NULL;
	matrix_b = NULL;
	sela = false;
	initComponents();
}
QMatrixViewer :: QMatrixViewer( QWidget * parent, DoubleMatrix * A  )
: QFrame( parent )
{
	matrix_a = A;
	matrix_b = NULL;
	sela = false;
	initComponents();
}
QMatrixViewer :: QMatrixViewer( QWidget * parent, DoubleMatrix * A, DoubleMatrix * B, bool S  )
: QFrame( parent )
{
	matrix_a = A;
	matrix_b = B;
	sela = S;
}
//SETS
void QMatrixViewer :: setMainMatrix( DoubleMatrix* M )
{
	matrix_a = M;
	repaint();
}
//GETS

void QMatrixViewer :: drawBox( void )
{
	QPainter painter( this );
	painter.setRenderHint( QPainter::Antialiasing, true );
	painter.setPen( QPen( Qt::black, 1, Qt::SolidLine, Qt::RoundCap ) );
	painter.fillRect( this->rect(), Qt::white );
	painter.drawRect( this->rect() );
}
void QMatrixViewer :: methodChanged( int choosen )
{
	method = (CHOOSEN_METHOD) choosen;
	switch ( method ) {
		case GAUSS:
			matrix_a->prepareGauss( matrix_b );
			break;
		case GAUSS_JORDAN:
			matrix_a->prepareGauss( matrix_b );
			break;
		case GAUSS_SEIDL:
			break;
		case JACOBI:
			break;
	}
	std::cout << "METHOD" << method << std::endl;
	repaint();
}
void QMatrixViewer :: drawSela( void )
{
	QPainter painter( this );
	painter.setRenderHint( QPainter::Antialiasing, true );
		char part[20];
		//DRAW NUMBERS
		painter.setPen( QPen( Qt::black, 1, Qt::SolidLine, Qt::RoundCap ) );
		for ( int i = 0; i < matrix_a->getLines(); i++ )
		{
			for ( int j = 0; j < matrix_a->getColumns() + 2; j++ )
			{
				if ( j < matrix_a->getColumns() ) {
					sprintf( part, "%.2f", matrix_a->getValue( i, j ) );
					painter.drawText( 20 + j * 100, 20 + i * 20, part );
				}
				else if ( j > matrix_a->getColumns() ) {
					sprintf( part, "%.2f", matrix_b->getValue( i, 0 ) );
					painter.drawText( 20 + (j+2) * 100, 20 + i * 20, part );
				}
				else {
					sprintf( part, "X%d", i+1 );
					painter.drawText( 20 + (j+1) * 100, 20 + i * 20, part );
				}
			}
		}
		painter.setPen( QPen( Qt::black, 2, Qt::SolidLine, Qt::RoundCap ) );
		//A FIRST
		painter.drawLine( 10, 10, 10, matrix_a->getLines() * 20 );
		//A LAST
		painter.drawLine( 10 + matrix_a->getColumns() * 100, 10, 10 + matrix_a->getColumns() * 100, matrix_a->getLines() * 20 );
		painter.drawText( 10 + (matrix_a->getColumns()) * 100 + 40, matrix_a->getLines() * 15, "X" );
		//X FIRST
		painter.drawLine( 10 + (matrix_a->getColumns() + 1) * 100, 10, 10 + ( matrix_a->getColumns() + 1) * 100, matrix_a->getLines() * 20 );
		//X LAST
		painter.drawLine( 10 + (matrix_a->getColumns() + 2) * 100, 10, 10 + ( matrix_a->getColumns() + 2) * 100, matrix_a->getLines() * 20 );
		painter.drawText( 10 + (matrix_a->getColumns() + 2) * 100 + 40, matrix_a->getLines() * 15, "=" );
		//B FIRST
		painter.drawLine( 10 + (matrix_a->getColumns() + 3) * 100, 10, 10 + ( matrix_a->getColumns() + 3) * 100, matrix_a->getLines() * 20 );
		//BLAST
		painter.drawLine( 10 + (matrix_a->getColumns() + 4) * 100, 10, 10 + ( matrix_a->getColumns() + 4) * 100, matrix_a->getLines() * 20 );
}
void QMatrixViewer :: drawSimpleMatrix( void )
{
	QPainter painter( this );
	painter.setRenderHint( QPainter::Antialiasing, true );
	//DRAW NUMBERS
	painter.setPen( QPen( Qt::black, 1, Qt::SolidLine, Qt::RoundCap ) );
	for ( int i = 0; i < matrix_a->getLines(); i++ )
		for ( int j = 0; j < matrix_a->getColumns(); j++ )
		{
			//if( i == 2 )
			//{
			//painter.fillRect( 10 + (j * 100), (i * 20) + 5, 100, 20, Qt::green );
			//}
			char part[20];
			sprintf( part, "%.2f", matrix_a->getValue( i, j ) );
			painter.drawText( 20 + j * 100, 20 + i * 20, part );
		}
	
	painter.setPen( QPen( Qt::black, 2, Qt::SolidLine, Qt::RoundCap ) );
	//FIRST SEPARATOR
	painter.drawLine( 10, 10, 10, matrix_a->getLines() * 20 );
	//LAST SEPARATOR
	painter.drawLine( 10 + matrix_a->getColumns() * 100, 10, 10 + matrix_a->getColumns() * 100, matrix_a->getLines() * 20 );
}
void QMatrixViewer :: drawGauss( void )
{
	for ( int i = 0; i < matrix_a->getAuxiliar()->getLines(); i++ )
	{
		for ( int j = 0; j < matrix_a->getAuxiliar()->getColumns(); j++ )
		{
			std::cout << matrix_a->getAuxiliar()->getValue(i, j) << " ";
		}
		std::cout << std::endl;
	}
	QPainter painter( this );
	painter.setRenderHint( QPainter::Antialiasing, true );
	char part[20];
	int diff = 0;
	//DRAW NUMBERS
	painter.setPen( QPen( Qt::black, 1, Qt::SolidLine, Qt::RoundCap ) );
	for ( int i = 0; i < matrix_a->getAuxiliar()->getLines(); i++ )
	{
		for ( int j = 0; j < matrix_a->getAuxiliar()->getColumns(); j++ )
		{
			sprintf( part, "%.2f", matrix_a->getAuxiliar()->getValue( i, j ) );
			painter.drawText( 20 + j * 100, 20 + i * 20, part );
		}
	}
	painter.setPen( QPen( Qt::black, 2, Qt::SolidLine, Qt::RoundCap ) );
	//FIRST
	painter.drawLine( 10, 5, 10, matrix_a->getAuxiliar()->getLines() * 25 );
	//LAST
	painter.drawLine( 10 + (matrix_a->getAuxiliar()->getColumns() + 1) * 100, 5, 10 + ( matrix_a->getAuxiliar()->getColumns() + 1) * 100, matrix_a->getAuxiliar()->getLines() * 25 );
	//MIDDLE
	painter.setPen( QPen( Qt::black, 1.5, Qt::DotLine, Qt::RoundCap ) );
	painter.drawLine( 10 + matrix_a->getAuxiliar()->getColumns() * 100, 5, 10 + matrix_a->getAuxiliar()->getColumns() * 100, matrix_a->getAuxiliar()->getLines() * 25 );
}
void QMatrixViewer :: doCalcStep( void )
{
	switch ( method ) {
		case GAUSS:
			break;
		case GAUSS_JORDAN:
			matrix_a->roundGaussJordan();
			break;
		case GAUSS_SEIDL:
			break;
		case JACOBI:
			break;
	}
}
void QMatrixViewer :: drawMatrix( void )
{
	if( sela )
	{
		drawSela();
	}
	else if( matrix_a != NULL && matrix_b == NULL )
	{
		drawSimpleMatrix();
	}
	else {
		switch ( method ) {
			case GAUSS:
				drawGauss();
				break;
			case GAUSS_JORDAN:
				break;
			case GAUSS_SEIDL:
				break;
			case JACOBI:
				break;
		}
	}
}
void QMatrixViewer :: paintEvent( QPaintEvent * event )
{
	event->accept();
	drawBox();
	drawMatrix();
}
void QMatrixViewer :: initComponents( void )
{
}