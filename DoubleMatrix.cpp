/*
 *  DoubleMatrix.cpp
 *  SELA
 *
 *  Created by PRoTeW on 12/01/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "DoubleMatrix.h"
#include "cmath"

DoubleMatrix :: DoubleMatrix( int L, int C )
{
	lines = L;
	columns = C;
	matrix = ( double ** ) malloc( lines * sizeof( double* ) );
	for ( int i = 0; i < lines; i++ )
	{
		matrix[ i ] = ( double * ) malloc( columns * sizeof( double ) );
		for ( int j = 0; j < columns; j++ )
			matrix[ i ][ j ] = 0;
	}
	error = 0;
	x0 = NULL;
	auxiliar = NULL;
	inverse = NULL;
	diagonal = NULL;
	cofactor = NULL;
	identity = NULL;
	transpose = NULL;
	ldu = NULL;
	pivot_line = 0;
	output += "";
	solved = false;
}
void DoubleMatrix :: clearIteractions( void )
{
	iteractions_x.clear();
}
void DoubleMatrix :: createAuxiliar( void )
{
	auxiliar = new DoubleMatrix( lines, columns );
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
			auxiliar->setValue( i, j, matrix[i][j] );
}
void DoubleMatrix :: addOutput( std::string addendum )
{
	std::string old_content = output;
	output = addendum;
	output +="\n_______________________________________________________________________________________________________________________________\n\n";
	output += old_content;
}
//SETS
void DoubleMatrix :: addIteraction( DoubleMatrix* xn )
{
	iteractions_x.push_back( xn );
}
void DoubleMatrix :: setRound( int value )
{
	round = value;
}
void DoubleMatrix :: setError( double value )
{
	error = value;
}
void DoubleMatrix :: setValue( int i, int j, double value )
{
	matrix[ i ][ j ]  = value;
}
void DoubleMatrix :: setPivotLine( int value )
{
	pivot_line = value;
}
void DoubleMatrix :: setSolved( bool value )
{
	solved = value;
}
//GETS
std::vector<DoubleMatrix*> DoubleMatrix :: getIteractions( void )
{
	return iteractions_x;
}
int DoubleMatrix :: getRound( void )
{
	return round;
}
double DoubleMatrix :: getError( void )
{
	return error;
}
DoubleMatrix* DoubleMatrix :: getX0( void )
{
	if( x0 == NULL )
		x0 = new DoubleMatrix( lines, 1 );
	return x0;
}
int DoubleMatrix :: getPivotLine( void )
{
	return pivot_line;
}
int DoubleMatrix :: getLines( void )
{
	return lines;
}
int DoubleMatrix :: getColumns( void )
{
	return columns;
}
double** DoubleMatrix :: getMatrix( void )
{
	return matrix;
}
DoubleMatrix* DoubleMatrix :: getAuxiliar( void )
{
	if( auxiliar == NULL )
		createAuxiliar();
	return auxiliar;
}
DoubleMatrix* DoubleMatrix :: getDiagonal( void )
{
	diagonal = new DoubleMatrix( lines, columns );
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
		{
			if( i == j )
			{
				diagonal->setValue( i, j, matrix[ i][ j ] );
			}
		}
	return diagonal;
}
DoubleMatrix* DoubleMatrix :: getLDU( void )
{
	return getDiagonal()->sumMatrix( multMatrix( -1 ) );
}
double DoubleMatrix :: getValue( int i, int j )
{
	return matrix[ i ][ j ];
}
DoubleMatrix* DoubleMatrix :: sumMatrix( DoubleMatrix* M )
{
	if( lines == M->getLines() && columns == M->getColumns() )
	{
		DoubleMatrix * sum = new DoubleMatrix( lines, columns );
		for ( int i = 0; i < lines; i++ )
			for ( int j = 0; j < columns; j++ )
				sum->setValue( i, j, matrix[i][j] + M->getValue(i, j) );
		return sum;
	}
	else {
		output += "INVALID SUM\n";
		return NULL;
	}
}
DoubleMatrix* DoubleMatrix :: multMatrix( double X )
{
	DoubleMatrix * mult = new DoubleMatrix( lines, columns );
	for ( int mult_i = 0; mult_i < lines; mult_i++ )
		for ( int mult_j = 0; mult_j < columns; mult_j++ )
		{
			mult->setValue( mult_i, mult_j, matrix[mult_i][mult_j] * X );
		}
	return mult;
}
DoubleMatrix* DoubleMatrix :: multMatrix( DoubleMatrix* M )
{
	if( columns == M->getLines() )
	{
		DoubleMatrix * mult = new DoubleMatrix( lines, M->getColumns() );
		for ( int mult_i = 0; mult_i < mult->getLines(); mult_i++ )
			for ( int mult_j = 0; mult_j < mult->getColumns(); mult_j++ )
			{
				double sum = 0;
				for ( int id = 0; id < columns; id++ )
				{
					sum += matrix[mult_i][id] * M->getValue(id, mult_j);
				}
				mult->setValue( mult_i, mult_j, sum );
			}
		return mult;
	}
	else {
		output += "INVALID MULTIPLICATION\n";
		return NULL;
	}
}
bool DoubleMatrix :: equals( DoubleMatrix* M )
{
	if( lines == M->getLines() && columns == M->getColumns() )
	{
		for ( int i = 0; i < lines; i++ )
			for ( int j = 0; j < columns; j++ )
			{
				if( matrix[ i ][ j ] != M->getValue( i, j ) )
				{
					return false;
				}
			}
		return true;
	}
	else {
		return false;
	}
}
double DoubleMatrix :: distanceTo( DoubleMatrix* M )
{
	if( lines == M->getLines() && columns == M->getColumns() )
	{
		double distance = 0;
		for ( int i = 0; i < lines; i++ )
		{
			double line_sum = 0;
			for ( int j = 0; j < columns; j++ )
			{
				line_sum += ( matrix[ i ][ j ] - M->getValue( i, j ) ) * ( matrix[ i ][ j ] - M->getValue( i, j ) );
			}
			distance += sqrt( line_sum );
		}
		return distance;
	}
	else {
		return -1;
	}
}
//GETS
bool DoubleMatrix :: isSolved( void )
{
	return solved;
}
std::string DoubleMatrix :: getOutput( void )
{
	return output;
}
DoubleMatrix* DoubleMatrix :: getIdentity( void )
{
	identity = new DoubleMatrix( lines, columns );
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
			( i == j ) ? identity->setValue( i, j, 1 ) : identity->setValue( i, j, 0 );
	return identity;
}
bool DoubleMatrix :: isIdentity( void )
{
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
		{
			if( i == j && matrix[ i ][ j ] != 1 )
				return false;
			if( i != j && matrix[ i ][ j ] != 0 )
				return false;
		}
	return true;
}
bool DoubleMatrix :: isSingular( void )
{
	for ( int i = 0; i < lines; i++ )
	{
		bool line_zero = true;
		for ( int j = 0; j < columns && line_zero; j++ )
		{
			if( matrix[i][j] != 0 )
				line_zero = false;
		}
		if( line_zero )
		{
			char line[50];
			sprintf( line, "SINGULAR LINHA %d\n", (i + 1) );
			output += line;
			return true;
		}
	}
	for ( int j = 0; j < lines; j++ )
	{
		bool column_zero = true;
		for ( int i = 0; i < columns && column_zero; i++ )
		{
			if( matrix[i][j] != 0 )
				column_zero = false;
		}
		if( column_zero )
		{
			char line[50];
			sprintf( line, "SINGULAR COLUNA %d\n", (j + 1) );
			output += line;
			return true;
		}
	}
	return false;
}
bool DoubleMatrix :: hasZeroDiagonal( void )
{
	for( int i = 0; i < lines; i++ )
	{
		if( matrix[i][i] == 0 )
			return true;
	}
	return false;
}
int DoubleMatrix :: getNextAvailablePivotLine( void )
{
	for ( int i1 = pivot_line; i1 < lines; i1++ )
	{
		if ( matrix[i1][pivot_line] != 0 ) {
			return i1;
		}
	}
	return -1;
}
bool DoubleMatrix :: isInferiorTriangle( void )
{
	for ( int j = 0; j < lines; j++ )
	{
		for ( int i = j+1; i < lines; i++ )
		{
			if ( matrix[i][j] != 0 ) {
				return false;
			}
		}
	}
	return true;
}
void DoubleMatrix :: transformDiagonallyDominant( void )
{
	int count = 0;
	while( !isDiagonallyDominant() && count < lines*lines )
	{
		for ( int i1 = 0; i1 < lines; i1++ )
		{
			double sum_1 = 0;
			for ( int j1 = 0; j1 < columns; j1++ )
			{
				if( i1 != j1 )
					sum_1 += matrix[i1][j1];
			}
			if( sum_1 > matrix[i1][i1] )
			{
				bool found = false;
				for ( int i2 = 0; i2 < lines && !found; i2++ )
				{
					if( i1 != i2 )
					{
						double sum_2 = 0;
						for ( int j2 = 0; j2 < columns; j2++ )
						{
							if( j2 != i1 )
								sum_2 += matrix[i2][j2];
						}
						if( sum_2 <= matrix[i2][i1] )
						{
							output += swapLines( i1, i2 );
							found = true;
						}
					}
				}
			}
		}
		count++;
	}
	output += showMatrix();
}
bool DoubleMatrix :: isDiagonallyDominant( void )
{
	for ( int i = 0; i < lines; i++ )
	{
		double sum = 0;
		for ( int j = 0; j < columns; j++ )
		{
			if( i != j )
				sum += matrix[i][j];
		}
		if( sum > matrix[i][i] )
			return false;
	}
	return true;
}
void DoubleMatrix :: roundGauss( void ) 
{
	char step_head_line[100];
	std::string step_content;
	//PARADA
	if( !auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isInferiorTriangle() && !auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isSingular() )
	{
		sprintf( step_head_line, "STEP %d )\n\n", round + 1 );
		step_content = step_head_line;
		//PIVOTEAMENTO
		int available_pivot = auxiliar->getNextAvailablePivotLine();
		if( available_pivot != auxiliar->getPivotLine() )
		{
			step_content += auxiliar->swapLines( available_pivot, auxiliar->getPivotLine() );
			step_content += auxiliar->showMatrix();
		}
		for( int line = auxiliar->getPivotLine(); line < lines; line++ )
		{
			if( line != auxiliar->getPivotLine() )
			{
				double multiplier = -( auxiliar->getValue( line, auxiliar->getPivotLine() ) / auxiliar->getValue( auxiliar->getPivotLine(), auxiliar->getPivotLine() ) );
				char command[100];
				sprintf(command, "LINE %d MULTIPLIED BY %f [ ", auxiliar->getPivotLine() + 1, multiplier );
				step_content += command;
				for ( int c = 0; c < auxiliar->getColumns(); c++ ) {
					sprintf( command, "%f ", auxiliar->getLineMultiplied( auxiliar->getPivotLine(), multiplier )[c] );
					step_content += command;
				}
				step_content += " ] ";
				step_content += auxiliar->sumLines( auxiliar->getLineMultiplied( auxiliar->getPivotLine(), multiplier ), line  );
			}
		}
		step_content += auxiliar->showMatrix();
		auxiliar->setPivotLine( auxiliar->getPivotLine() + 1 );
	}
	else if( auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isInferiorTriangle() )
	{
		sprintf( step_head_line, "STEP %d )\n\n", round + 1 );
		solved = true;
	}
	else if( auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isSingular() )
	{
		step_content += "END )\n\nSINGULAR MATRIX\n";
		solved = true;
	}
	round++;
	addOutput( step_content );
}
void DoubleMatrix :: roundGaussJordan( void ) 
{
	char step_head_line[100];
	std::string step_content;
	//PARADA
	if( !auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isIdentity() && !auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isSingular() )
	{
		sprintf( step_head_line, "STEP %d )\n\n", round + 1 );
		step_content = step_head_line;
		//PIVOTEAMENTO
		int available_pivot = auxiliar->getNextAvailablePivotLine();
		if( available_pivot != auxiliar->getPivotLine() )
		{
			step_content += auxiliar->swapLines( available_pivot, auxiliar->getPivotLine() );
			step_content += auxiliar->showMatrix();
		}
		//TRANSFORMA PIVOT EM 1
		if( auxiliar->getValue( auxiliar->getPivotLine(), auxiliar->getPivotLine() ) != 1 )
			step_content += auxiliar->multiplyLine( auxiliar->getPivotLine(), 1 / auxiliar->getValue( auxiliar->getPivotLine(), auxiliar->getPivotLine() ) );
		for( int line = 0; line < lines; line++ )
		{
			if( line != auxiliar->getPivotLine() )
			{
				double multiplier = -auxiliar->getValue( line, auxiliar->getPivotLine() );
				char command[100];
				sprintf(command, "LINE %d MULTIPLIED BY %f [ ", auxiliar->getPivotLine() + 1, multiplier );
				step_content += command;
				for ( int c = 0; c < auxiliar->getColumns(); c++ ) {
					sprintf( command, "%f ", auxiliar->getLineMultiplied( auxiliar->getPivotLine(), multiplier )[c] );
					step_content += command;
				}
				step_content += " ] ";
				step_content += auxiliar->sumLines( auxiliar->getLineMultiplied( auxiliar->getPivotLine(), multiplier ), line  );
			}
		}
		step_content += auxiliar->showMatrix();
		auxiliar->setPivotLine( auxiliar->getPivotLine() + 1 );
	}
	else if( auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isIdentity() )
	{
		step_content += "END )\n\n";
		char exit_part[20];
		for ( int x_id = 0; x_id < auxiliar->getLines(); x_id++ ) {
			sprintf( exit_part, "X%d = %f\n", x_id+1, auxiliar->getValue( x_id, auxiliar->getColumns() - 1 ) );
			step_content += exit_part;
		}
		solved = true;
	}
	else if( auxiliar->getComplementar( lines, auxiliar->getColumns() - 1 )->isSingular() )
	{
		step_content += "END )\n\nSINGULAR MATRIX\n";
		solved = true;
	}
	round++;
	addOutput( step_content );
}
void DoubleMatrix :: roundJacobi( DoubleMatrix* XN, DoubleMatrix* B )
{
	char step_head_line[100];
	std::string step_content;
	//
	iteractions_x.push_back( getDiagonal()->getInverse()->multMatrix( getLDU() )->multMatrix( XN )->sumMatrix( getDiagonal()->getInverse()->multMatrix( B ) ) );
	//
	//PARADA
	std::cout << "ERROR " << iteractions_x[ round + 1 ]->distanceTo( XN ) << std::endl;
	if( round < 5 && iteractions_x[ round + 1 ]->distanceTo( XN ) > error && !iteractions_x[ round + 1 ]->equals( XN ) )
	{
		//
		sprintf( step_head_line, "STEP %d )\n\n", round + 1 );
		step_content = step_head_line;
		char part[200];
		for ( int i = 0; i < lines; i++ ) {
			for ( int j = 0; j < 3 * columns + 8; j++ ) {
				if( j < 1 )
				{
					sprintf(part, "%f\t", iteractions_x[ round + 1 ]->getValue( i, 0 ) );
				}
				else if( j < 2 )
				{
					if( i == 0 )
						sprintf(part, "=\t" );
					else
						sprintf(part, " \t");
				}
				else if( j < columns + 2 )
				{
					sprintf(part, "%f\t", getDiagonal()->getInverse()->getValue( i, j - 2 ) );
				}
				else if( j < columns + 3 )
				{
					if( i == 0 )
						sprintf(part, "x\t");
					else
						sprintf(part, " \t");
				}
				else if( j < 2 * columns + 3 )
				{
					sprintf( part, "%f\t", getLDU()->getValue( i , j - ( columns + 3 ) ) );
				}
				else if( j < 2 * columns + 4 )
				{
					if( i == 0 )
						sprintf(part, "x\t");
					else
						sprintf(part, " \t");
				}
				else if( j < 2 * columns + 5 )
				{
					sprintf( part, "%f\t", XN->getValue( i , j - ( 2 * columns + 4 ) ) );
				}
				else if( j < 2 * columns + 6 )
				{
					if( i == 0 )
						sprintf(part, "+\t");
					else
						sprintf(part, " \t");
				}
				else if( j < 3 * columns + 6 )
				{
					sprintf( part, "%f\t", getDiagonal()->getInverse()->getValue( i, j - ( 2 * columns + 6 ) ) );
				}
				else if( j < 3 * columns + 7 )
				{
					if( i == 0 )
						sprintf(part, "x\t");
					else
						sprintf(part, " \t");
				}
				else if( j < 3 * columns + 8 )
				{
					sprintf( part, "%f\t", B->getValue( i, j - ( 3 * columns + 7 ) ) );
				}
				step_content += part;
			}
			step_content += "\n\n";
		}
	}
	else {
		step_content += "END )\n\n";
		char exit_part[20];
		for ( int x_id = 0; x_id < lines; x_id++ ) {
			sprintf( exit_part, "X%d = %f\n", x_id+1, iteractions_x[ round ]->getValue( x_id, 0 ) );
			step_content += exit_part;
		}
		solved = true;
	}
	round++;
	addOutput( step_content );
}
void DoubleMatrix :: prepareGauss( DoubleMatrix* B ) 
{
	std::string step_content = "";
	auxiliar = getExtendedMatrix( B );
	round = 0;
	int prepare_round = 0;
	solved = false;
	step_content += auxiliar->showMatrix();
	while ( auxiliar->hasZeroDiagonal() && prepare_round < lines * lines ) {
		bool found_zero = false;
		for ( int i1 = 0; i1 < lines && !found_zero; i1++ )
		{
			if( auxiliar->getValue( i1, i1 ) == 0 )
			{
				found_zero = true;
				bool found_non_zero = false;
				for ( int i2 = 0; i2 < lines && !found_non_zero; i2++ )
				{
					if( i1 != i2 && auxiliar->getValue( i2, i1 ) != 0 )
					{
						found_non_zero = true;
						step_content += auxiliar->swapLines( i1, i2 );
					}
				}
			}
		}
		prepare_round++;
	}
	addOutput( step_content );
}
std::string DoubleMatrix :: swapLines( int i, int j )
{
	double* aux = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = aux;
	char command[100];
	sprintf(command, "SWAP LINES %d AND %d\n", i + 1, j + 1 );
	return command;
}
std::string DoubleMatrix :: multiplyLine( int line, double x )
{
	std::string command;
	char command_part[100];
	sprintf( command_part, "MULTIPLY LINE %d BY %f [ ", line + 1, x );
	command += command_part;
	for ( int j = 0; j < columns; j++ )
	{
		matrix[line][j] *= x;
		sprintf( command_part, "%f ", matrix[line][j] );
		command += command_part;
	}
	command += " ]\n";
	return command;
}
std::string DoubleMatrix :: sumLines( double* sum_line, int target_line  )
{
	for ( int j = 0; j < columns; j++ )
	{
		matrix[target_line][j] += sum_line[j];
	}
	char command[100];
	sprintf(command, "ADDED TO LINE %d\n", target_line + 1 );
	return command;
}
std::string DoubleMatrix :: swapColumns( int i , int j )
{
	char command[100];
	sprintf(command, "SWAP COLUMNS %d AND %d\n", i + 1, j + 1 );
	return command;
}
//
void DoubleMatrix :: setOutput( std::string content )
{
	output = content;
}
double* DoubleMatrix :: getLineMultiplied( int line, double x )
{
	double * mult_line = ( double * ) malloc( columns * sizeof( double ) );
	for ( int j = 0; j < columns; j++ )
	{
		mult_line[j] = matrix[line][j] * x;
	}
	return mult_line;
}
double DoubleMatrix :: getDet( void )
{
	if( lines == columns )
	{
		if( lines == 1 && columns == 1 )
		{
			return matrix[0][0];
		}
		else if( lines == 2 && columns == 2 )
		{
			return ( -1 * ( matrix[0][1] * matrix[1][0] ) ) + ( matrix[0][0] * matrix[1][1] );
		}
		else if( lines == 3 && columns == 3 )
		{
			return  ( -1 * ( matrix[0][2] * matrix[1][1] * matrix[2][0] ) ) +
			( -1 * ( matrix[0][0] * matrix[1][2] * matrix[2][1] ) ) +
			( -1 * ( matrix[0][1] * matrix[1][0] * matrix[2][2] ) ) +
			( matrix[0][0] * matrix[1][1] * matrix[2][2] ) +
			( matrix[0][1] * matrix[1][2] * matrix[2][0] ) +
			( matrix[0][2] * matrix[1][0] * matrix[2][1] );
		}
		else {
			double det = 0;
			for ( int i = 0; i < lines; i++ )
			{
				det += pow( -1, i+2 ) * getComplementar( i, 0 )->getDet();
			}
			return det;
		}
	}
	else {
		return 0;
	}
}
DoubleMatrix* DoubleMatrix :: getComplementar( int Pi, int Pj )
{
	int comp_lines, comp_columns;
	( Pi >= 0 && Pi < lines ) ? comp_lines = lines - 1 : comp_lines = lines;
	( Pj >= 0 && Pj < columns ) ? comp_columns = columns - 1 : comp_columns = columns;
	
	DoubleMatrix * complementar = new DoubleMatrix( comp_lines, comp_columns );
	for ( int ci = 0, i = 0; i < lines; i++ )
	{
		bool is_line = false;
		if( i < Pi )
		{
			ci = i;
			is_line = true;
		}
		else if( i > Pi )
		{
			ci = i - 1;
			is_line = true;
		}
		for ( int cj = 0, j = 0; j < columns; j++ )
		{
			if( j != Pj )
			{
				if( is_line )
					complementar->setValue( ci, cj, matrix[ i ][ j ] );
				cj++;
			}
		}
	}
	return complementar;
}
DoubleMatrix* DoubleMatrix :: getTranspose( void )
{
	transpose = new DoubleMatrix( lines, columns );
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
		{
			transpose->setValue( i, j, matrix[ j ][ i ] );
		}
	return transpose;
}
DoubleMatrix* DoubleMatrix :: getCofactor( void )
{
	cofactor = new DoubleMatrix( lines, columns );
	for ( int i = 0; i < lines; i++ )
		for ( int j = 0; j < columns; j++ )
		{
			cofactor->setValue( i, j, pow( -1, ( i + 1 ) + ( j + 1 ) ) * getComplementar( i, j )->getDet() );
		}
	return cofactor;
}
DoubleMatrix* DoubleMatrix :: getInverse( void )
{
	return getCofactor()->getTranspose()->multMatrix( 1 / getDet() );
}
DoubleMatrix* DoubleMatrix :: getExtendedMatrix( DoubleMatrix* M )
{
	if( lines == M->lines )
	{
		DoubleMatrix * extended = new DoubleMatrix( lines, columns + M->getColumns() );
		for ( int mult_i = 0; mult_i < extended->getLines(); mult_i++ )
			for ( int mult_j = 0; mult_j < extended->getColumns(); mult_j++ )
			{
				( mult_j < columns ) ? extended->setValue( mult_i, mult_j, matrix[ mult_i ][ mult_j ] ) : extended->setValue( mult_i, mult_j, M->getValue( mult_i, mult_j - columns ) );
			}
		return extended;
	}
	else {
		output += "EXT INVALIDA\n";
		return NULL;
	}
}
std::string DoubleMatrix :: showMatrix( void )
{
	std::string matrix_content = "\n";
	char part[20];
	for ( int i = 0; i < lines; i++ ) {
		for ( int j = 0; j < columns; j++ ) {
			sprintf(part, "%f\t", matrix[i][j]);
			matrix_content += part;
		}
		matrix_content += "\n";
	}
	return matrix_content;
}