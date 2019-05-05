/*
 *  MainWindow.h
 *  Function_2o
 *
 *  Created by PRoTeW on 29/12/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QPushButton>
#include "QSela.h"
#include "QOutputViewer.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow( void );
	void initComponents( void );
	//SETS
	//GETS
	
protected:
	void keyPressEvent( QKeyEvent * );
	public slots:
		void createMatrix( void );
	
private:
	
	QSela				*	sela_widget;
	QSpinBox			*	dsb_setter_dimension;
	//
	//BUTTONS
	QPushButton			*	btn_create;
	QPushButton			*	btn_output;

	//MAIN WINDOW LAYOUTS
	QHBoxLayout			*	base_buttons_layout;
	QHBoxLayout			*	upper_layout;
	QVBoxLayout			*	main_layout;
};

#endif
