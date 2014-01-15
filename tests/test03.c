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

#define TRY01     1
#define TRY02     2

int main(void) {
	int ret = 3;
	CTRY {
		CTRY {
			printf("Throwing error inside double CTRY body...");
			CTHROW(1);
		}
		CCATCH(1) {
			printf(" 1. Error catched\n");
			ret &= ~TRY01;
		}
		CENDTRY;

		printf("Throwing error inside CTRY body...");
		CTHROW(1);
	}
	CCATCH(1) {
		printf("2. Error catched\n");
		ret &= ~TRY02;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

