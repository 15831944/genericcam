///////////////////////////////////////////////////////////////////////////////
// Name               : GCodeBlock.cpp
// Purpose            : 
// Thread Safe        : Yes
// Platform dependent : No
// Compiler Options   :
// Author             : Tobias Schaefer
// Created            : 09.07.2017
// Copyright          : (C) 2017 Tobias Schaefer <tobiassch@users.sourceforge.net>
// Licence            : GNU General Public License version 3.0 (GPLv3)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
///////////////////////////////////////////////////////////////////////////////

#include "GCodeBlock.h"

#include <math.h>
#include <float.h>
#include <stdint.h>
#include <stdexcept>
#include <wx/arrimpl.cpp>

WX_DEFINE_OBJARRAY(ArrayOfGCodeBlock)

GCodeBlock::GCodeBlock(wxString block, double conversionFactor)
{
	this->conversionFactor = conversionFactor;
	A = 0.0;
	B = 0.0;
	C = 0.0;
	D = -1;
	F = -1.0;
	for(uint_fast8_t n = 0; n < maxGModes; ++n)
		G[n] = -1;
	H = -1;
	I = 0.0;
	J = 0.0;
	K = 0.0;
	L = -1;
	for(uint_fast8_t n = 0; n < maxMModes; ++n)
		M[n] = -1;
	MCount = 0;
	N = -1;
	P = -1.0;
	Q = -1.0;
	R = 0.0;
	S = -1.0;
	T = -1;
	U = 0.0;
	V = 0.0;
	W = 0.0;
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
	AFlag = false;
	BFlag = false;
	CFlag = false;
	IFlag = false;
	JFlag = false;
	KFlag = false;
	RFlag = false;
	UFlag = false;
	VFlag = false;
	WFlag = false;
	XFlag = false;
	YFlag = false;
	ZFlag = false;

	block_delete = false;
	message = false;

	if(block.empty()) return;

	bool negative = false;
	int numberI = 0;
	double numberD = 0;
	double shift = 1;
	char key = 0;
	uint_fast8_t state = 0;
	const size_t BL = block.Length();
	for(size_t n = 0; n <= BL; ++n){
		const wxChar c = (n < BL)? block[n] : 0;
		bool unexpected = false;
		switch(state){
		case 0:
		{
			if(c == ' ' || c == 9) break;
			if(c == 'n' || c == 'N'){
				N = 0;
				state = 2;
				break;
			}
			if(c == '/'){
				block_delete = true;
				state = 1;
				break;
			}
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				key = c;
				negative = false;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				key = c - 32; // converts a-z to A-Z
				negative = false;
				state = 6;
				break;
			}
			if(c == '('){
				state = 7;
				break;
			}
			unexpected = true;
			break;
		}
		case 1:
		{
			if(c == ' ' || c == 9) break;
			if(c == 'n' || c == 'N'){
				N = 0; // Has a line number.
				state = 2;
				break;
			}
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				key = c;
				negative = false;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				key = c - 32; // converts a-z to A-Z
				state = 6;
				negative = false;
				break;
			}
			if(c == '('){
				state = 7;
				break;
			}
			unexpected = true;
			break;
		}
		case 2:
		{
			if(c == ' ' || c == 9) break;
			if(((c >= '0') && (c <= '9'))){
				N = c - '0';
				state = 3;
				break;
			}
			unexpected = true;
			break;
		}
		case 3:
		{
			if(c == ' ' || c == 9) break;
			if(c == 0){
				state = 4;
				break;
			}
			if(((c >= '0') && (c <= '9'))){
				//TODO: Maybe limit number of number chars?
				N = N * 10 + (c - '0');
				break;
			}
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				key = c;
				negative = false;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				key = c - 32; // converts a-z to A-Z
				negative = false;
				state = 6;
				break;
			}
			if(c == '('){
				state = 7;
				break;
			}

			unexpected = true;
			break;
		}
		case 4:
		{
			if(c == ' ' || c == 9) break;
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				key = c;
				negative = false;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				key = c - 32; // converts a-z to A-Z
				negative = false;
				state = 6;
				break;
			}
			if(c == '('){
				state = 7;
				break;
			}
			unexpected = true;
			break;
		}
		case 6:
		{
			if(c == ' ' || c == 9) break;
			if(c == '+'){
				state = 13;
				break;
			}
			if(c == '-'){
				state = 13;
				negative = true;
				break;
			}
			if(((c >= '0') && (c <= '9'))){
				numberI = c - '0';
				numberD = numberI;
				state = 14;
				break;
			}
			if(c == '.'){
				numberI = 0;
				numberD = numberI;
				shift = 1.0;
				state = 15;
				break;
			}
			unexpected = true;
			break;
		}
		case 7:
		{
			if(c == ')'){
				state = 4;
				break;
			}
			if(c == ' ' || c == 9) break;
			Comment += c;
			if(c == 'm' || c == 'M'){
				state = 9;
				break;
			}
			state = 8;
			break;
		}
		case 8:
		{
			if(c == ')'){
				state = 4;
			}else{
				Comment += c;
			}
			break;
		}
		case 9:
		{
			if(c == ')'){
				state = 4;
				break;
			}
			Comment += c;
			if(c == ' ' || c == 9) break;
			if(c == 's' || c == 'S'){
				state = 10;
				break;
			}
			state = 8;
			break;
		}
		case 10:
		{
			if(c == ')'){
				state = 4;
				break;
			}
			Comment += c;
			if(c == ' ' || c == 9) break;
			if(c == 'g' || c == 'G'){
				state = 11;
				break;
			}
			state = 8;
			break;
		}
		case 11:
		{
			if(c == ')'){
				state = 4;
				break;
			}
			Comment += c;
			if(c == ' ' || c == 9) break;
			if(c == ','){
				Comment.Empty();
				message = true;
				state = 8;
				break;
			}
			state = 8;
			break;
		}
		case 13:
		{
			if(((c >= '0') && (c <= '9'))){
				numberI = c - '0';
				numberD = numberI;
				state = 14;
				break;
			}
			if(c == '.'){
				numberI = 0;
				numberD = numberI;
				shift = 1.0;
				state = 15;
				break;
			}
			unexpected = true;
			break;
		}
		case 14:
		{
			if(((c >= '0') && (c <= '9'))){
				numberI = numberI * 10 + (c - '0');
				numberD = numberI;
				break;
			}
			if(c == '.'){
				shift = 1.0;
				state = 15;
				break;
			}
			if(c == ' ' || c == 9) break;
			if(c == 0){
				Update(key, negative, numberI, numberD);
				state = 4;
				break;
			}
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				Update(key, negative, numberI, numberD);
				key = c;
				negative = 0;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				Update(key, negative, numberI, numberD);
				key = c - 32; // converts a-z to A-Z
				negative = 0;
				state = 6;
				break;
			}
			if(c == '('){
				Update(key, negative, numberI, numberD);
				state = 7;
				break;
			}
			unexpected = true;
			break;
		}
		case 15:
		{
			if(((c >= '0') && (c <= '9'))){
				shift /= 10.0;
				numberD = numberD + ((double) (c - '0')) * shift;
				break;
			}

			if(c == ' ' || c == 9) break;
			if(c == 0){
				Update(key, negative, numberI, numberD);
				state = 4;
				break;
			}
			if(((c >= 'A') && (c <= 'D')) || ((c >= 'F') && (c <= 'M'))
					|| ((c >= 'P') && (c <= 'Z'))){
				Update(key, negative, numberI, numberD);
				key = c;
				negative = 0;
				state = 6;
				break;
			}
			if(((c >= 'a') && (c <= 'd')) || ((c >= 'f') && (c <= 'm'))
					|| ((c >= 'p') && (c <= 'z'))){
				Update(key, negative, numberI, numberD);
				key = c - 32; // converts a-z to A-Z
				negative = 0;
				state = 6;
				break;
			}
			if(c == '('){
				Update(key, negative, numberI, numberD);
				state = 7;
				break;
			}
			unexpected = true;
			break;
		}
		default:
			throw(__FILE__ ": GCodeBlock Error in statemachine.");
			break;
		}

		if(unexpected && n < BL){
			error = wxString::Format(_T("Character %c was not expected."), c);
		}

		if(n == BL && state != 4 && state != 0) error = _T(
				"Missing closing character at end of line.");
		if(!error.IsEmpty()){
			error = wxString::Format(_T("Column %u: "), n) + error;
			error += _T("\nafter ") + block.Left(n) + _T("<");
			break;
		}
	}
}

wxString GCodeBlock::GetCode(void) const
{
	wxString temp;

	if(T >= 0) temp += wxString::Format(_T(" T%u"), T);
	if(S >= -FLT_EPSILON) temp += wxString::Format(_T(" S%g"), S * 60);

	for(uint_fast8_t n = 0; n < maxMModes; ++n){
		if(M[n] < 0) continue;
		temp += wxString::Format(_T(" M%u"), M[n]);
	}

	if(D >= 0) temp += wxString::Format(_T(" D%u"), D);
	if(H >= 0) temp += wxString::Format(_T(" H%u"), H);
	if(L >= 0) temp += wxString::Format(_T(" L%u"), L);

	if(F >= -FLT_EPSILON) temp += wxString::Format(_T(" F%g"),
			F * 60.0 / conversionFactor);

	for(uint_fast8_t n = 0; n < maxGModes; ++n){
		if(G[n] < 0) continue;
		const uint_fast16_t gmaj = (G[n] / 10);
		const uint_fast8_t gmin = (G[n] % 10);
		if(gmin == 0){
			temp += wxString::Format(_T(" G%u"), gmaj);
		}else{
			temp += wxString::Format(_T(" G%u.%u"), gmaj, gmin);
		}
	}

	if(XFlag){
		temp += wxString::Format(_T(" X%g"), X / conversionFactor);
	}
	if(YFlag){
		temp += wxString::Format(_T(" Y%g"), Y / conversionFactor);
	}
	if(ZFlag){
		temp += wxString::Format(_T(" Z%g"), Z / conversionFactor);
	}
	if(AFlag){
		temp += wxString::Format(_T(" A%g"), A * 180.0 * M_1_PI);
	}
	if(BFlag){
		temp += wxString::Format(_T(" B%g"), B * 180.0 * M_1_PI);
	}
	if(CFlag){
		temp += wxString::Format(_T(" C%g"), C * 180.0 * M_1_PI);
	}
	if(UFlag){
		temp += wxString::Format(_T(" U%g"), U / conversionFactor);
	}
	if(VFlag){
		temp += wxString::Format(_T(" V%g"), V / conversionFactor);
	}
	if(WFlag){
		temp += wxString::Format(_T(" W%g"), W / conversionFactor);
	}
	if(IFlag){
		temp += wxString::Format(_T(" I%g"), I / conversionFactor);
	}
	if(JFlag){
		temp += wxString::Format(_T(" J%g"), J / conversionFactor);
	}
	if(KFlag){
		temp += wxString::Format(_T(" K%g"), K / conversionFactor);
	}
	if(RFlag){
		temp += wxString::Format(_T(" R%g"), R / conversionFactor);
	}

	if(P >= -FLT_EPSILON) temp += wxString::Format(_T(" P%g"), P);
	if(Q >= -FLT_EPSILON) temp += wxString::Format(_T(" Q%g"),
			Q / conversionFactor);

	if(N >= 0) temp = wxString::Format(_T(" N%u"), N) + temp;
	if(block_delete) temp = _T("/") + temp;
	if(!Comment.empty()){
		if(message){
			temp += _T(" (MSG,") + Comment + _T(")");
		}else{
			temp += _T(" (") + Comment + _T(")");
		}
	}
	if(!temp.IsEmpty() && temp[0] == ' '){
		temp = temp.Right(temp.Length() - 1);
	}
	return temp;
}

static const int Gindex[1000] =
	{1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 6, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			7, -1, -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 8, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			12, -1, -1, -1, -1, -1, -1, -1, -1, -1, 12, 12, 12, 12, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 13, 13, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 13, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			0, 0, 0, 0, -1, -1, -1, -1, -1, -1, 5, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1, 14, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, 10, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1};

static const int Mindex[120] =
	{4, 4, 4, 7, 7, 7, 6, 8, 8, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 9, 9, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
			-1, -1, -1, -1, -1, -1, -1, -1, -1, 4, 4, 10, 10, 10, 10, 10, 10,
			10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

//TODO: Make error messages translatable.
void GCodeBlock::Update(char key, bool negative, int numberI, double numberD)
{
	if(negative){
		numberI = -numberI;
		numberD = -numberD;
	}

	switch(key){
	case 'A':
	{
		AFlag = true;
		A = numberD * M_PI / 180.0;
		break;
	}
	case 'B':
	{
		BFlag = true;
		B = numberD * M_PI / 180.0;
		break;
	}
	case 'C':
	{
		CFlag = true;
		C = numberD * M_PI / 180.0;
		break;
	}
	case 'I':
	{
		IFlag = true;
		I = numberD * conversionFactor;
		break;
	}
	case 'J':
	{
		JFlag = true;
		J = numberD * conversionFactor;
		break;
	}
	case 'K':
	{
		KFlag = true;
		K = numberD * conversionFactor;
		break;
	}
	case 'R':
	{
		RFlag = true;
		R = numberD * conversionFactor;
		break;
	}
	case 'U':
	{
		UFlag = true;
		U = numberD * conversionFactor;
		break;
	}
	case 'V':
	{
		VFlag = true;
		V = numberD * conversionFactor;
		break;
	}
	case 'W':
	{
		WFlag = true;
		W = numberD * conversionFactor;
		break;
	}
	case 'X':
	{
		XFlag = true;
		X = numberD * conversionFactor;
		break;
	}
	case 'Y':
	{
		YFlag = true;
		Y = numberD * conversionFactor;
		break;
	}
	case 'Z':
	{
		ZFlag = true;
		Z = numberD * conversionFactor;
		break;
	}

	case 'D':
	{
		if(numberI < 0){
			error = _T("Integer negative for D.");
		}else{
			D = numberI;
		}
		break;
	}
	case 'F':
	{
		if(numberD < 0){
			error = _T("Integer negative for F.");
		}else{
			F = numberD * conversionFactor / 60.0;
		}
		break;
	}
	case 'H':
	{
		if(numberI < 0){
			error = _T("Integer negative for H.");
		}else{
			H = numberI;
		}
		break;
	}
	case 'L':
	{
		if(numberI < 0){
			error = _T("Integer negative for L.");
		}else{
			L = numberI;
		}
		break;
	}
	case 'P':
	{
		if(numberD < 0){
			error = _T("Integer negative for P.");
		}else{
			P = numberD;
		}
		break;
	}
	case 'Q':
	{
		if(numberD < 0){
			error = _T("Integer negative for Q.");
		}else{
			Q = numberD * conversionFactor;
		}
		break;
	}

	case 'S':
	{
		if(numberD < 0){
			error = _T("Integer negative for S.");
		}else{
			S = numberD / 60.0;
		}
		break;
	}

	case 'T':
	{
		if(numberI < 0){
			error = _T("Integer negative for T.");
		}else{
			T = numberI;
		}
		break;
	}

	case 'G':
	{
		const int temp = round(numberD * 10.0);
		if(temp >= 0 && temp < 1000){
			const int index = Gindex[temp];
			if(index == -1){
				error = _T("Unknown or unsupported G command.");
			}else{
				if(G[index] >= 0){
					error = wxString::Format(
							_T("From this modal-group there is already G%g."),
							(double) G[index] / 10.0);
				}else{
					G[index] = temp;
				}
			}
		}else{
			if(temp < 0) error = _T("G command may not be negative.");
			if(temp >= 1000) error = _T(
					"G command may not be greater than 99.9.");
		}
		break;
	}
	case 'M':
	{
		const int temp = numberI;
		if(temp >= 0 && temp < 120){
			const int index = Mindex[temp];
			if(index == -1){
				error = _T("Unknown or unsupported M command.");
			}else{
				if(M[index] >= 0){
					error =
							wxString::Format(
									_T(
											"A command for this M command-group was already found. (M%i)"),
									M[index]);
				}else{
					M[index] = temp;
				}
			}
		}else{
			if(temp < 0) error = _T("M command may not be negative.");
			if(temp >= 120) error = _T(
					"M command may not be greater than 119.");
		}
		break;
	}
	default:
		error = wxString::Format(_T("Missing case for %c."), key);
		break;
	}
}

void GCodeBlock::ClearGM(void)
{
	for(uint_fast8_t n = 0; n < maxGModes; ++n)
		G[n] = -1;
	for(uint_fast8_t n = 0; n < maxMModes; ++n)
		M[n] = -1;
	MCount = 0;
}

void GCodeBlock::SetG(unsigned int nr, unsigned char subnr)
{
	const int temp = nr * 10 + subnr;
	if(temp < 0) throw(std::out_of_range("G command may not be negative."));
	if(temp >= 1000) throw(std::out_of_range(
			"G command may not be greater than 99.9."));
	const int index = Gindex[temp];
	if(index == -1) throw(std::logic_error("Unknown or unsupported G command."));
	G[index] = temp;
}

void GCodeBlock::SetM(unsigned int nr)
{
	if(nr < 0) throw(std::out_of_range("M command may not be negative."));
	if(nr >= 120) throw(std::out_of_range(
			"M command may not be greater than 119."));
	const int index = Mindex[nr];
	if(index == -1) throw(std::logic_error("Unknown or unsupported M command."));
	M[index] = nr;
}

void GCodeBlock::Rapid(void)
{
	SetG(0);
}

void GCodeBlock::FeedSpeed(void)
{
	SetG(1);
}

void GCodeBlock::ArcCW(void)
{
	SetG(2);
}

void GCodeBlock::ArcCCW(void)
{
	SetG(3);
}

bool GCodeBlock::IsCutting(void) const
{
	return G[1] > 0; // neither empty nor rapid motion selected
}

int GCodeBlock::Motion(void) const
{
	if(G[1] >= 0) return G[1] / 10;
	return -1;
}
