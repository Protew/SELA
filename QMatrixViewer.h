/*
 *  QMatrixViewer.h
 *  SELA
 *
 *  Created by PRoTeW on 14/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef QMATRIXVIEWER_H
#define QMATRIXVIEWER_H

#include <QtGui>
#include <QtWidgets/QFrame>
#include <QPainter>
#include "DoubleMatrix.h"

QT_BEGIN_NAMESPACE;
class QTextEdit;
class QLabel;
class QFrame;
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE;

class QMatrixViewer : public QFrame
{
	Q_OBJECT;
	
	DoubleMatrix*		matrix_a;
	DoubleMatrix*		matrix_b;
	CHOOSEN_METHOD		method;
	
	bool sela;
	
protected:
	void paintEvent( QPaintEvent * );
	
public:
	QMatrixViewer( QWidget* );
	QMatrixViewer( QWidget*, DoubleMatrix* );
	QMatrixViewer( QWidget*, DoubleMatrix*, DoubleMatrix*, bool );
	//SETS
	void setMainMatrix( DoubleMatrix* );
	//GETS
	void initComponents( void );
	void drawSela( void );
	void drawGauss( void );
	void drawSimpleMatrix( void );
	void drawBox( void );
	void drawMatrix( void );
	
	public slots:
		void methodChanged( int );
		void doCalcStep( void );
};

#endif
