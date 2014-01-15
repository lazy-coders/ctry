/* ctry - exception system for C language.
 * Copyright (C) 2013 Samuel Rodriguez Sevilla <laparca {at} laparca.es>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <ctry.h>
#include <stdio.h>

int test_div(int a, int b) {
	if (b == 0)
		CTHROW(1);
	return a / b;
}

int main(void) {
	int ret = 1;
	CTRY {
		printf("Indirect throwing of error inside CTRY body...");
		test_div(1, 0);
	}
	CCATCH(1) {
		printf("Error catched\n");
		ret = 0;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

