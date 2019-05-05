/*
 *  QValueSetter.h
 *  SELA
 *
 *  Created by PRoTeW on 11/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef QVALUESETTER_H
#define QVALUESETTER_H

#include <QWidget>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QGridLayout>

class QValueSetter : public QWidget
{
    Q_OBJECT
	
	QLabel*				lbl_variable_name;
	int					line;
	int					column;
	double				value;
	int					parent_dimension;
	bool				labeled;
	QGridLayout*		main_layout;
	QDoubleSpinBox*		dsb_value_setter;

	
public:
	QValueSetter( QWidget * parent, int, int, int, bool );
	void initComponents( void );
	//SETS
	//GETS
	QDoubleSpinBox* getValueSetter( void );
	
signals:
	void emitIndexes( int, int, double );
private slots:
	void valueSetted( double );
};

#endif
