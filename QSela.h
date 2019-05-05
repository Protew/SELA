/*
 *  QSela.h
 *  SELA
 *
 *  Created by PRoTeW on 11/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef QSELA_H
#define QSELA_H

#include <QtGui>
#include <QtWidgets/QGroupBox>
#include <vector>
#include "QValueSetter.h"
#include "QOutputViewer.h"
#include "DoubleMatrix.h"

QT_BEGIN_NAMESPACE;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QRadioButton;
QT_END_NAMESPACE;

class QSela : public QGroupBox
{
    Q_OBJECT
	
	int							dimension;
	int							round;
	DoubleMatrix*				matrix_a;
	DoubleMatrix*				matrix_b;
	DoubleMatrix*				matrix_x;
	DoubleMatrix*				matrix_aproximated_x;
	DoubleMatrix*				matrix_x0;
	std::vector<DoubleMatrix*>	x_iterations;
	double						error;
	
	QOutputViewer*				output_viewer;
	
	QGridLayout*		values_layout;
	QHBoxLayout*		options_layout;
	QVBoxLayout*		main_layout;
	QLabel*				lbl_equal;
	
protected:
	void keyPressEvent( QKeyEvent * );
	
	public slots:
	void setMatrixAValue( int, int, double );
	void setMatrixBValue( int, int, double );
	void showOutput( void );
	
public:
    QSela( QWidget * parent, int dimension = 0 );
	void initComponents( void );
};

#endif
