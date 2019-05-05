/*
 *  OutputViewer.h
 *  SELA
 *
 *  Created by PRoTeW on 14/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef QOUTPUTVIEWER_H
#define QOUTPUTVIEWER_H

#include <QtGui>
#include <QPainter>
#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "DoubleMatrix.h"
#include "QMatrixViewer.h"
#include "CalcTable.h"

class QOutputViewer : public QWidget
{
    Q_OBJECT
	
	DoubleMatrix*		matrix_a;
	DoubleMatrix*		matrix_b;

	QLabel*				lbl_a;
	QLabel*				lbl_b;
	QLabel*				lbl_det;
	QLabel*				lbl_inverse;
	QLabel*				lbl_transpose;
	QLabel*				lbl_cofactor;
	QLabel*				lbl_identity;
	QLabel*				lbl_diagonal;
	
	QMatrixViewer*		sela_viewer;
	QMatrixViewer*		operation_viewer;
	CalcTable*			calc_table;
	
	QComboBox*			lv_calc_options;
	QPushButton*		btn_calc;
	
	QVBoxLayout*		operations_layout;
	QVBoxLayout*		calculations_layout;
	QHBoxLayout*		calc_options_layout;
	QHBoxLayout*		viewers_layout;
	QHBoxLayout*		sela_layout;
	QVBoxLayout*		table_area_layout;
	QVBoxLayout*		main_layout;
	
protected:
	void paintEvent( QPaintEvent * );
	
public:
	QOutputViewer( QWidget*, DoubleMatrix*, DoubleMatrix* );
	void initComponents( void );
	std::string selaPatternOutput( void );
	//SETS
	//GETS
	public slots:
	void setSela( void );
	void setA( void );
	void setB( void );
	void setDet( void );
	void setInverse( void );
	void setTranpose( void );
	void setCofactor( void );
	void setIdentity( void );
	void setDiagonal( void );
};

#endif
