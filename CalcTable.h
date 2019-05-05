/*
 *  CalcTable.h
 *  SELA
 *
 *  Created by PRoTeW on 16/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CALCTABLE_H
#define CALCTABLE_H

#include <QtGui>
#include <QtWidgets/QTextBrowser>
#include <QPainter>
#include "DoubleMatrix.h"
#include "QIterativeParameters.h"

QT_BEGIN_NAMESPACE;
class QTextBrowser;
class QLabel;
class QFrame;
class QVBoxLayout;
class QHBoxLayout;
QT_END_NAMESPACE;

class CalcTable : public QTextBrowser
{
    Q_OBJECT
	
	DoubleMatrix*		matrix_a;
	DoubleMatrix*		matrix_b;
	CHOOSEN_METHOD		method;
	
	std::vector<DoubleMatrix*> iteractions_x;
	
	bool				accept_input;
	bool				first_iteration;
	
public:
	CalcTable( QWidget*, DoubleMatrix*, DoubleMatrix* );
	//SETS
	//GETS
	void initComponents( void );
	//
	public slots:
	void methodChanged( int );
	void doCalcStep( void );
	void setX0( void );
	void setX0Value( int, double );
	void setError( double );
};

#endif
