/*
 *  QIterativeParameters.h
 *  SELA
 *
 *  Created by PRoTeW on 17/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef QITERATIVEPARAMETERS_H
#define QITERATIVEPARAMETERS_H

#include <QtGui>
#include <QWidget>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "QValueSetter.h"
#include "DoubleMatrix.h"

class QIterativeParameters : public QWidget
{
    Q_OBJECT
	
	int					lines;
	
	QPushButton*		btn_ok;
	
	QVBoxLayout*		x0_layout;
	QVBoxLayout*		error_layout;
	QHBoxLayout*		main_layout;
	
protected:
	void closeEvent( QCloseEvent * );
	
public:
	QIterativeParameters( QWidget *, int );
	void initComponents( void );
	//SETS
	//GETS
	QDoubleSpinBox* getValueSetter( void );
	QPushButton* getOkButton( void );

signals:
	void emitX0Value( int, double );
	void emitErrorValue( double );
	private slots:
	void setX0Value( int, int, double );
	void setError( int, int, double );
};

#endif
